/* ***************************************************************************
 * Copyright (c) 2012-2013 Google, Inc.  All rights reserved.
 * ***************************************************************************/

/*
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 * 
 * * Redistributions of source code must retain the above copyright notice,
 *   this list of conditions and the following disclaimer.
 * 
 * * Redistributions in binary form must reproduce the above copyright notice,
 *   this list of conditions and the following disclaimer in the documentation
 *   and/or other materials provided with the distribution.
 * 
 * * Neither the name of Google, Inc. nor the names of its contributors may be
 *   used to endorse or promote products derived from this software without
 *   specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL GOOGLE, INC. OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH
 * DAMAGE.
 */

/* Code Manipulation API Sample:
 * bbcov.c
 * 
 * Collects information about basic blocks that have been executed.
 * It simply stores the information of basic blocks seen in bb callback event
 * into a table without any instrumentation, and dumps the buffer into log files
 * on thread/process exit.
 * To collect per-thread basic block execution information, run DR with
 * a thread private code cache (i.e., -thread_private).
 * The information can be used in cases like code coverage.
 *
 * The runtime options for this client include:
 * -dump_text         Dumps the log file in text format
 * -dump_binary       Dumps the log file in binary format
 * -[no_]nudge_kills  Windows only. On by default.
 *                    Uses nudge to notify the process for termination
 *                    so that the exit event will be called.
 * -logdir <dir>      Sets log directory, which by default is at the same
 *                    directory as the client library.
 *
 * The two options below can only be used when the client is compiled with
 * CBR_COVERAGE being defined.
 *
 * -check_cbr     Performs simple online conditional branch coverage checks.
 *                Checks how many conditional branches are seen and how
 *                many branches/fallthroughs are not excercised.
 *                The result are printed to bbcov.*.res file.
 * -summary_only  Prints only the summary of check results. Must be used
 *                with -check_cbr option.
 */

#include "dr_api.h"
#include "bbcov.h"
#include "../common/modules.h"
#include "../common/utils.h"
#include "hashtable.h"
#include "drtable.h"
#include "limits.h"
#include <string.h>

#ifdef WINDOWS
# define  STATIC_DRMGR_ONLY 1 /* for drmgr_decode_sysnum_from_wrapper only */
# include "drmgr.h"
#endif

#ifdef CBR_COVERAGE
# define IF_CBR_COVERAGE_ELSE(x, y) x
#else
# define IF_CBR_COVERAGE_ELSE(x, y) y
#endif

static uint verbose;

#define NOTIFY(level, fmt, ...) do {          \
    if (verbose >= (level))                   \
        dr_fprintf(STDERR, fmt, __VA_ARGS__); \
} while (0)

#define OPTION_MAX_LENGTH MAXIMUM_PATH

typedef struct _bbcov_option_t {
    bool dump_text;
    bool dump_binary;
#ifdef WINDOWS
    /* Use nudge to notify the process for termination so that
     * event_exit will be called. Windows only.
     */
    bool nudge_kills;
#endif
    char logdir[MAXIMUM_PATH];
    int native_until_thread;
#ifdef CBR_COVERAGE
    bool check;
    bool summary;
#endif
} bbcov_option_t;
static bbcov_option_t options;


#define NUM_THREAD_MODULE_CACHE 4

typedef struct _per_thread_t {
    void *bb_table;
    /* for quick per-thread query without lock */
    module_entry_t *cache[NUM_THREAD_MODULE_CACHE];
    file_t  log;
#ifdef CBR_COVERAGE
    file_t  res;
#endif
} per_thread_t;

static per_thread_t *global_data;
static bool bbcov_per_thread = false;
static module_table_t *module_table;
static client_id_t client_id;
#ifndef WINDOWS
static int sysnum_execve = IF_X64_ELSE(59, 11);
#endif
static volatile bool go_native;

static void
event_exit(void);

static void
event_thread_exit(void *drcontext);

/****************************************************************************
 * Utility Functions
 */
static file_t
log_file_create_helper(void *drcontext, char *prefix, const char *suffix)
{
    char buf[MAXIMUM_PATH];
    file_t log;
    int i;
    size_t len;
    for (i = 0; i < 10000; i++) {
        len = dr_snprintf(buf, MAXIMUM_PATH, "%s.%04d.%s", prefix, i, suffix);
        ASSERT(len > 0, "dr_snprintf failed");
        NULL_TERMINATE_BUFFER(buf);
        log = dr_open_file(buf,
#ifndef WINDOWS
                           DR_FILE_CLOSE_ON_FORK |
#endif
                           DR_FILE_WRITE_REQUIRE_NEW | DR_FILE_ALLOW_LARGE);
        if (log != INVALID_FILE) {
            dr_log(drcontext, LOG_ALL, 1, "bbcov: log file is %s\n", buf);
            NOTIFY(1, "<created log file %s>\n", buf);
            return log;
        }
    }
    return INVALID_FILE;
}

static void
log_file_create(void *drcontext, per_thread_t *data)
{
    char logname[MAXIMUM_PATH];
    const char *app_name;
    char *dirsep;
    size_t len;

    /* We will dump data to a log file at the same directory as our library.
     * We could also pass in a path and retrieve with dr_get_options().
     */
    len = dr_snprintf(logname, BUFFER_SIZE_ELEMENTS(logname), "%s",
                      options.logdir[0] != '\0' ?
                      options.logdir : dr_get_client_path(client_id));
    ASSERT(len > 0, "dr_snprintf failed");
    NULL_TERMINATE_BUFFER(logname);
    dirsep = logname + len - 1;
    if (options.logdir[0] == '\0' /* removing client lib */ ||
        /* path does not have a trailing / and is too large to add it */
        (*dirsep != '/' IF_WINDOWS(&& *dirsep != '\\') &&
         len == BUFFER_SIZE_ELEMENTS(logname) - 1)) {
        for (dirsep = logname + len;
             *dirsep != '/' IF_WINDOWS(&& *dirsep != '\\');
             dirsep--)
            ASSERT(dirsep > logname, "fail to find trailing /");
    }
    /* add trailing / if necessary */
    if (*dirsep != '/' IF_WINDOWS(&& *dirsep != '\\')) {
        dirsep++;
        /* append a dirsep at the end if missing */
        *dirsep = IF_UNIX_ELSE('/', '\\');
    }
    app_name = dr_get_application_name();
    if (app_name == NULL)
        app_name = "unknown";
    len = dr_snprintf(dirsep + 1,
                      (sizeof(logname)-(dirsep+1-logname))/sizeof(logname[0]),
                      "bbcov.%s.%05d", app_name,
                      drcontext == NULL ?
                      dr_get_process_id() :
                      dr_get_thread_id(drcontext));
    ASSERT(len > 0, "dr_snprintf failed");
    NULL_TERMINATE_BUFFER(logname);
    if (options.dump_text || options.dump_binary) {
        data->log = log_file_create_helper(drcontext, logname,
                                           drcontext == NULL ?
                                           "proc.log" : "thd.log");
    } else {
        data->log = INVALID_FILE;
    }
#ifdef CBR_COVERAGE
    if (options.check) {
        data->res = log_file_create_helper(drcontext, logname,
                                           drcontext == NULL ?
                                           "proc.res" : "thd.res");
    } else
        data->res = INVALID_FILE;
#endif
}

/****************************************************************************
 * BB Table Functions
 */

#ifdef CBR_COVERAGE
/* iterate data passed for branch coverage check iteration */
typedef struct _check_iter_data_t {
    per_thread_t *data;
    int           num_mods;
    /* arrays below are indexed by module id, #modules-1 for bb w/ no-module */
    ptr_uint_t   *num_bbs;
    ptr_uint_t   *num_cbr_tgts;
    ptr_uint_t   *num_cbr_falls;
    ptr_uint_t   *num_cbr_tgt_misses;
    ptr_uint_t   *num_cbr_fall_misses;
    /* stores all the bbs seen for each module */
    hashtable_t  *bb_htables;
    /* stores all the cbr targets/fallthroughs seen for each module */
    hashtable_t  *cbr_htables;
} check_iter_data_t;

static bool
bb_table_entry_check(ptr_uint_t idx, void *entry, void *iter_data)
{
    check_iter_data_t *data = (check_iter_data_t *)iter_data;
    bb_entry_t  *bb_entry = (bb_entry_t *)entry;
    hashtable_t *bb_htable;
    hashtable_t *cbr_htable;
    int mod_id = (bb_entry->mod_id == -1) ? data->num_mods-1 : bb_entry->mod_id;
    bb_htable  = &data->bb_htables[mod_id];
    cbr_htable = &data->cbr_htables[mod_id];
    if (bb_entry->cbr_tgt != 0) {
        if (hashtable_add
            (cbr_htable, (void *)(ptr_uint_t)bb_entry->cbr_tgt, entry)) {
            data->num_cbr_tgts[mod_id]++;
            if (hashtable_lookup
                (bb_htable, (void *)(ptr_uint_t)bb_entry->cbr_tgt) == NULL) {
                data->num_cbr_tgt_misses[mod_id]++;
                if (!options.summary) {
                    dr_fprintf(data->data->res, "module[%3d]: "PFX" to "PFX"\n",
                               mod_id,
                               (void *)(ptr_uint_t)bb_entry->start,
                               (void *)(ptr_uint_t)bb_entry->cbr_tgt);
                }
            }
        }
        if (hashtable_add(cbr_htable,
                          (void *)(ptr_uint_t)(bb_entry->start+bb_entry->size),
                          entry)) {
            data->num_cbr_falls[mod_id]++;
            if (hashtable_lookup(bb_htable,
                                 (void *)(ptr_uint_t)
                                 (bb_entry->start + bb_entry->size))
                == NULL) {
                data->num_cbr_fall_misses[mod_id]++;
                if (!options.summary) {
                    dr_fprintf(data->data->res, "module[%3d]: "PFX" to "PFX"\n",
                               mod_id,
                               bb_entry->start,
                               bb_entry->start + bb_entry->size);
                }
            }
        }
    }
    return true;
}

static bool
bb_table_entry_fill_htable(ptr_uint_t idx, void *entry, void *iter_data)
{
    check_iter_data_t *data = (check_iter_data_t *)iter_data;
    bb_entry_t  *bb_entry = (bb_entry_t *)entry;
    int mod_id = (bb_entry->mod_id == -1) ?
        data->num_mods - 1 : bb_entry->mod_id;
    hashtable_t *htable = &data->bb_htables[mod_id];
    if (hashtable_add(htable, (void *)(ptr_uint_t)bb_entry->start, entry))
        data->num_bbs[mod_id]++;
    return true;
}

static void
bb_table_check_print_result(per_thread_t *data,
                            check_iter_data_t *iter_data,
                            int mod_id)
{
    dr_fprintf(data->res,
               "\tunique basic blocks seen: "SZFMT",\n"
               "\tunique conditional branch targets: "SZFMT
               ", not excercised: "SZFMT",\n"
               "\tunique conditional branch fallthroughs: "SZFMT
               ", not excercised: "SZFMT",\n",
               iter_data->num_bbs[mod_id],
               iter_data->num_cbr_tgts[mod_id],
               iter_data->num_cbr_tgt_misses[mod_id],
               iter_data->num_cbr_falls[mod_id],
               iter_data->num_cbr_fall_misses[mod_id]);
}

/* Checks each conditional branch target and fall-through with whether
 * it was executed.
 *
 * This is done by iterating the bb_table twice:
 * - Iteration 1 scans the bb table to find all unique bbs and put them
 *   into hashtables (bb_htables) of each module.
 * - Iteration 2 scans the bb table to find all unique cbr targets and
 *   fall-throughs, which are stored in hashtables (cbr_htables), and check
 *   whether they are in bb_htables.
 */
static void
bb_table_check_cbr(module_table_t *table, per_thread_t *data)
{
    check_iter_data_t iter_data;
    int i;
    /* one additional mod for bb w/o module */
    int num_mods = table->vector.entries + 1;
    ASSERT(data->res != INVALID_FILE, "result file is invalid");
    /* create hashtable for each module */
    iter_data.data          = data;
    iter_data.num_mods      = num_mods;
    iter_data.bb_htables    = dr_global_alloc(sizeof(hashtable_t)*num_mods);
    iter_data.cbr_htables   = dr_global_alloc(sizeof(hashtable_t)*num_mods);
    iter_data.num_bbs       = dr_global_alloc(sizeof(ptr_uint_t)*num_mods);
    iter_data.num_cbr_tgts  = dr_global_alloc(sizeof(ptr_uint_t)*num_mods);
    iter_data.num_cbr_falls = dr_global_alloc(sizeof(ptr_uint_t)*num_mods);
    iter_data.num_cbr_tgt_misses =
        dr_global_alloc(sizeof(ptr_uint_t)*num_mods);
    iter_data.num_cbr_fall_misses =
        dr_global_alloc(sizeof(ptr_uint_t)*num_mods);
    memset(iter_data.num_bbs, 0, sizeof(ptr_uint_t)*num_mods);
    memset(iter_data.num_cbr_tgts, 0, sizeof(ptr_uint_t)*num_mods);
    memset(iter_data.num_cbr_falls, 0, sizeof(ptr_uint_t)*num_mods);
    memset(iter_data.num_cbr_tgt_misses, 0, sizeof(ptr_uint_t)*num_mods);
    memset(iter_data.num_cbr_fall_misses, 0, sizeof(ptr_uint_t)*num_mods);
    for (i = 0; i < num_mods; i++) {
        hashtable_init_ex(&iter_data.bb_htables[i], 6, HASH_INTPTR,
                          false/*!strdup*/, false/*!sync*/, NULL, NULL, NULL);
        hashtable_init_ex(&iter_data.cbr_htables[i], 6, HASH_INTPTR,
                          false/*!strdup*/, false/*!sync*/, NULL, NULL, NULL);
    }
    /* first iteration to fill the hashtable */
    drtable_iterate(data->bb_table, &iter_data, bb_table_entry_fill_htable);
    /* second iteration to check if any cbr tgt is there */
    if (!options.summary)
        dr_fprintf(data->res, "conditional branch not excercised:\n");
    drtable_iterate(data->bb_table, &iter_data, bb_table_entry_check);
    /* check result */
    dr_fprintf(data->res, "Summary:\n");
    dr_fprintf(data->res, "module id, base, end, entry, unload, name, path");
#ifdef WINDOWS
    dr_fprintf(data->res, ", checksum, timestamp");
#endif
    dr_fprintf(data->res, "\n");
    drvector_lock(&module_table->vector);
    for (i = 0; i < num_mods-1; i++) {
        module_entry_t *entry = drvector_get_entry(&module_table->vector, i);
        ASSERT(entry != NULL, "fail to get a module entry");
        module_table_entry_print(entry, data->res);
        bb_table_check_print_result(data, &iter_data, i);
    }
    drvector_unlock(&module_table->vector);
    if (iter_data.num_bbs[i] != 0) {
        dr_fprintf(data->res, "basic blocks from unknown module\n");
        bb_table_check_print_result(data, &iter_data, i);
    }
    /* destroy the hashtable for each modules */
    for (i = 0; i < num_mods; i++) {
        hashtable_delete(&iter_data.bb_htables[i]);
        hashtable_delete(&iter_data.cbr_htables[i]);
    }
    dr_global_free(iter_data.bb_htables, sizeof(hashtable_t)*num_mods);
    dr_global_free(iter_data.cbr_htables, sizeof(hashtable_t)*num_mods);
    dr_global_free(iter_data.num_bbs, sizeof(ptr_uint_t)*num_mods);
    dr_global_free(iter_data.num_cbr_tgts, sizeof(ptr_uint_t)*num_mods);
    dr_global_free(iter_data.num_cbr_falls, sizeof(ptr_uint_t)*num_mods);
    dr_global_free(iter_data.num_cbr_tgt_misses, sizeof(ptr_uint_t)*num_mods);
    dr_global_free(iter_data.num_cbr_fall_misses, sizeof(ptr_uint_t)*num_mods);
}
#endif /* CBR_COVERAGE */

static bool
bb_table_entry_print(ptr_uint_t idx, void *entry, void *iter_data)
{
    per_thread_t *data = iter_data;
    bb_entry_t *bb_entry = (bb_entry_t *)entry;
    dr_fprintf(data->log, "module[%3u]: "PFX", %3u",
               bb_entry->mod_id, bb_entry->start, bb_entry->size);
#ifdef CBR_COVERAGE
    dr_fprintf(data->log, ", "PFX", %2u, %3u",
               bb_entry->cbr_tgt, bb_entry->trace ? 1:0, bb_entry->num_instrs);
#endif
    dr_fprintf(data->log, "\n");
    return true; /* continue iteration */
}

static void
bb_table_print(void *drcontext, per_thread_t *data)
{
    ASSERT(data != NULL, "data must not be NULL");
    if (data->log == INVALID_FILE) {
        ASSERT(false, "invalid log file");
        return;
    }
    dr_fprintf(data->log, "BB Table: %u bbs\n",
               drtable_num_entries(data->bb_table));
    if (options.dump_text) {
        dr_fprintf(data->log, "module id, start, size");
#ifdef CBR_COVERAGE
        dr_fprintf(data->log, ", cbr tgt, trace, #instr");
#endif
        dr_fprintf(data->log, ":\n");
        drtable_iterate(data->bb_table, data, bb_table_entry_print);
    } else
        drtable_dump_entries(data->bb_table, data->log);
}

static void
bb_table_entry_add(void *drcontext, per_thread_t *data, app_pc start,
#ifdef CBR_COVERAGE
                   app_pc cbr_tgt, ushort num_instrs, bool trace,
#endif
                   uint size)
{
    bb_entry_t *bb_entry = drtable_alloc(data->bb_table, 1, NULL);
    module_entry_t **mod_entry_cache = data != NULL ? data->cache : NULL;
    module_entry_t *mod_entry = module_table_lookup(mod_entry_cache,
                                                    NUM_THREAD_MODULE_CACHE,
                                                    module_table, start);
    /* we do not de-duplicate repeated bbs */
    ASSERT(size < USHRT_MAX, "size overflow");
    bb_entry->size = (ushort)size;
    if (mod_entry != NULL && mod_entry->data != NULL) {
        ASSERT(bb_entry->mod_id < USHRT_MAX, "module id overflow");
        bb_entry->mod_id = (ushort)mod_entry->id;
        ASSERT(start > mod_entry->data->start, "wrong module");
        bb_entry->start = (uint)(start - mod_entry->data->start);
#ifdef CBR_COVERAGE
        ASSERT(cbr_tgt == NULL || cbr_tgt > mod_entry->data->start,
               "cbr target should be withing module");
        bb_entry->cbr_tgt = (cbr_tgt == NULL) ?
            0 : (uint)(cbr_tgt - mod_entry->data->start);
#endif
    } else {
        /* XXX: we just truncate the address, which may have wrong value
         * in x64 arch. It should be ok now since it is an unknown module,
         * which will be ignored in the post-processing.
         * Should be handled for JIT code in the future.
         */
        bb_entry->mod_id = USHRT_MAX;
        bb_entry->start  = (uint)(ptr_uint_t)start;
#ifdef CBR_COVERAGE
        bb_entry->cbr_tgt = (uint)(ptr_uint_t)cbr_tgt;
#endif
    }
#ifdef CBR_COVERAGE
    bb_entry->trace = trace;
    bb_entry->num_instrs = num_instrs;
#endif
}

#define INIT_BB_TABLE_ENTRIES 4096
static void *
bb_table_create(bool synch)
{
    return drtable_create(INIT_BB_TABLE_ENTRIES,
                          sizeof(bb_entry_t), 0 /* flags */, synch, NULL);
}

static void
bb_table_destroy(void *table, void *data)
{
    drtable_destroy(table, data);
}

/****************************************************************************
 * Thread/Global Data Creation/Destroy
 */

/* make a copy of global data for pre-thread cache */
static per_thread_t *
thread_data_copy(void *drcontext)
{
    per_thread_t *data;
    ASSERT(drcontext != NULL, "drcontext must not be NULL");
    data = dr_thread_alloc(drcontext, sizeof(*data));
    *data = *global_data;
    return data;
}

static per_thread_t *
thread_data_create(void *drcontext)
{
    per_thread_t *data;
    if (drcontext == NULL) {
        ASSERT(!bbcov_per_thread, "bbcov_per_thread should not be set");
        data = dr_global_alloc(sizeof(*data));
    } else {
        ASSERT(bbcov_per_thread, "bbcov_per_thread should be set");
        data = dr_thread_alloc(drcontext, sizeof(*data));
    }
    /* XXX: can we assume bb create event is serialized,
     * if so, no lock is required for bb_table operation.
     */
    data->bb_table = bb_table_create(drcontext == NULL ? true : false);
    memset(data->cache, 0, sizeof(data->cache));
    log_file_create(drcontext, data);
    return data;
}

static void
thread_data_destroy(void *drcontext, per_thread_t *data)
{
    /* destroy the bb table */
    bb_table_destroy(data->bb_table, data);
    dr_close_file(data->log);
    /* free thread data */
    if (drcontext == NULL) {
        ASSERT(!bbcov_per_thread, "bbcov_per_thread should not be set");
        dr_global_free(data, sizeof(*data));
    } else {
        ASSERT(bbcov_per_thread, "bbcov_per_thread is not set");
        dr_thread_free(drcontext, data, sizeof(*data));
    }
}

static void *
global_data_create(void)
{
    return thread_data_create(NULL);
}

static void
global_data_destroy(per_thread_t *data)
{
    thread_data_destroy(NULL, data);
}

/****************************************************************************
 * Windows Specific Code
 */

#ifdef WINDOWS

enum {
    NUDGE_TERMINATE_PROCESS = 1,
};

static int sysnum_TerminateProcess = 0;

/* copy from nudge_ex.dll.c */
static int
get_sysnum(const char *wrapper)
{
    byte *entry;
    module_data_t *data = dr_lookup_module_by_name("ntdll.dll");
    ASSERT(data != NULL, "data must not be NULL");
    entry = (byte *) dr_get_proc_address(data->handle, wrapper);
    dr_free_module_data(data);
    if (entry == NULL)
        return -1;
    return drmgr_decode_sysnum_from_wrapper(entry);
}

static void
event_nudge(void *drcontext, uint64 argument)
{
    int nudge_arg = (int)argument;
    int exit_arg  = (int)(argument >> 32);
    if (nudge_arg == NUDGE_TERMINATE_PROCESS)
        dr_exit_process(exit_arg);
    ASSERT(nudge_arg == NUDGE_TERMINATE_PROCESS, "unsupported nudge");
    ASSERT(false, "should not reach"); /* should not reach */
}
#endif

static bool
event_filter_syscall(void *drcontext, int sysnum)
{

#ifdef WINDOWS
    return (options.nudge_kills && sysnum == sysnum_TerminateProcess);
#else
    return sysnum == sysnum_execve;
#endif
}

/****************************************************************************
 * Event Callbacks
 */

static bool
event_pre_syscall(void *drcontext, int sysnum)
{
#ifdef WINDOWS
    /* XXX: we should also watch for NtTerminateJobObject and other job
     * termination (xref i#1229).
     */
    /* XXX i#1231: we should try to share Dr. Memory's code by placing it
     * in an Extension.
     */
    if (options.nudge_kills && sysnum == sysnum_TerminateProcess) {
        HANDLE proc = (HANDLE)dr_syscall_get_param(drcontext, 0);
        process_id_t pid = dr_convert_handle_to_pid(proc);
        if (pid != INVALID_PROCESS_ID && pid != dr_get_process_id()) {
            /* we pass [exit_code, NUDGE_TERMINATE_PROCESS] to target process */
            dr_config_status_t res;
            uint64 exit_code = (uint64)dr_syscall_get_param(drcontext, 1);
            ASSERT(exit_code >> 32 == 0, "exit_code top 32-bit is not zero");
            res = dr_nudge_client_ex(pid, client_id,
                                     NUDGE_TERMINATE_PROCESS | exit_code << 32,
                                     0);
            if (res == DR_SUCCESS) {
                /* skip syscall since target will terminate itself */
                dr_syscall_set_result(drcontext, 0/*success*/);
                return false;
            }
            /* else failed b/c target not under DR control or maybe some other
             * error: let syscall go through
             */
        }
    }
    return true;
#else
    /* We assume execve always succeeds */
    if (sysnum == sysnum_execve) {
        event_thread_exit(drcontext);
        event_exit();
    }
    return true;
#endif
}

/* We collect the basic block information including offset from module base,
 * size, and num of instructions, and add it into a basic block table without
 * instrumentation.
 */
static dr_emit_flags_t
event_basic_block(void *drcontext, void *tag,
                  instrlist_t *bb, bool for_trace, bool translating)
{
    per_thread_t *data;
    instr_t *instr;
    app_pc start_pc, end_pc;
#ifdef CBR_COVERAGE
    ushort num_instrs = 0;
    app_pc cbr_tgt = NULL;
#endif

    /* do nothing for translation */
    if (translating)
        return DR_EMIT_DEFAULT;

    data = (per_thread_t *)dr_get_tls_field(drcontext);
    /* Collect the number of instructions and the basic block size,
     * assuming the basic block does not have any elision on control
     * transfer instructions, which is true for default options passed
     * to DR but not for -opt_speed.
     */
    start_pc = dr_fragment_app_pc(tag);
    end_pc   = start_pc; /* for finding the size */
    for (instr  = instrlist_first(bb);
         instr != NULL;
         instr  = instr_get_next(instr)) {
        app_pc pc = instr_get_app_pc(instr);
        if (instr_ok_to_mangle(instr)) {
            int len = instr_length(drcontext, instr);
            /* -opt_speed (elision) is not supported */
            ASSERT(pc != NULL && pc >= start_pc, "-opt_speed is not supported");
            if (pc + len > end_pc)
                end_pc = pc + len;
#ifdef CBR_COVERAGE
            num_instrs++;
            if (instr_opcode_valid(instr) && instr_is_cbr(instr))
                cbr_tgt = opnd_get_pc(instr_get_target(instr));
#endif
        }
    }
    /* We allow duplicated basic blocks for the following reasons:
     * 1. Avoids handling issues like code cache consistency, e.g.,
     *    module load/unload, self-modifying code, etc.
     * 2. Avoids the overhead on duplication check.
     * 3. Stores more information on code cache events, e.g., trace building,
     *    repeated bb building, etc.
     * 4. The duplication can be easily handled in a post-processing step,
     *    which is required anyway.
     */
    bb_table_entry_add(drcontext, data, start_pc,
#ifdef CBR_COVERAGE
                       cbr_tgt, num_instrs, for_trace,
#endif
                       (uint)(end_pc - start_pc));

    if (go_native)
        return DR_EMIT_GO_NATIVE;
    else
        return DR_EMIT_DEFAULT;
}

static void
event_module_unload(void *drcontext, const module_data_t *info)
{
    /* we do not delete the module entry but clean the cache only. */
    module_table_unload(module_table, info);
}

static void
event_module_load(void *drcontext, const module_data_t *info, bool loaded)
{
    module_table_load(module_table, info);
}

static void
version_print(file_t log)
{
    if (log == INVALID_FILE) {
        /* It is possible that failure on log file creation is caused by the
         * running process not having enough privilege, so this is not a
         * release-build fatal error
         */
        ASSERT(false, "invalid log file");
        return;
    }
    dr_fprintf(log, "BBCOV VERSION: %d\n", BBCOV_VERSION);
}

static void
event_thread_exit(void *drcontext)
{
    per_thread_t *data;

    data = (per_thread_t *)dr_get_tls_field(drcontext);
    ASSERT(data != NULL, "data must not be NULL");

    if (bbcov_per_thread) {
        /* print per-thread bbcov info */
        if (options.dump_text || options.dump_binary) {
            version_print(data->log);
            module_table_print(module_table, data->log,
                               IF_CBR_COVERAGE_ELSE(true, false));
            bb_table_print(drcontext, data);
        }
#ifdef CBR_COVERAGE
        if (options.check)
            bb_table_check_cbr(module_table, data);
#endif
        thread_data_destroy(drcontext, data);
    } else {
        /* the per-thread data is a copy of global data */
        dr_thread_free(drcontext, data, sizeof(*data));
    }
}

static void 
event_thread_init(void *drcontext)
{
    per_thread_t *data;
    static volatile int thread_count;

    if (options.native_until_thread > 0) {
        int local_count = dr_atomic_add32_return_sum(&thread_count, 1);
        NOTIFY(1, "@@@@@@@@@@@@@ new thread #%d %d\n",
               local_count, dr_get_thread_id(drcontext));
        if (go_native && local_count == options.native_until_thread) {
            void **drcontexts = NULL;
            uint num_threads, i;
            go_native = false;
            NOTIFY(1, "thread %d suspending all threads\n", dr_get_thread_id(drcontext));
            if (dr_suspend_all_other_threads_ex(&drcontexts, &num_threads, NULL,
                                                DR_SUSPEND_NATIVE)) {
                NOTIFY(1, "suspended %d threads\n", num_threads);
                for (i = 0; i < num_threads; i++) {
                    if (dr_is_thread_native(drcontexts[i])) {
                        NOTIFY(2, "\txxx taking over thread #%d %d\n",
                               i, dr_get_thread_id(drcontexts[i]));
                        dr_retakeover_suspended_native_thread(drcontexts[i]);
                    } else {
                        NOTIFY(2, "\tthread #%d %d under DR\n",
                               i, dr_get_thread_id(drcontexts[i]));
                    }
                }
                if (!dr_resume_all_other_threads(drcontexts, num_threads)) {
                    ASSERT(false, "failed to resume threads");
                }
            } else {
                ASSERT(false, "failed to suspend threads");
            }
        }

    }
    /* allocate thread private data for per-thread cache */
    if (bbcov_per_thread)
        data = thread_data_create(drcontext);
    else
        data = thread_data_copy(drcontext);
    dr_set_tls_field(drcontext, data);
}

#ifndef WINDOWS
static void
event_fork(void *drcontext)
{
    if (!bbcov_per_thread) {
        log_file_create(NULL, global_data);
    } else {
        per_thread_t *data = dr_get_tls_field(drcontext);
        if (data != NULL) {
            thread_data_destroy(drcontext, data);
        }
        event_thread_init(drcontext);
    }
}
#endif

static void
event_exit(void)
{
    if (!bbcov_per_thread) {
        if (options.dump_text || options.dump_binary) {
            version_print(global_data->log);
            module_table_print(module_table, global_data->log,
                               IF_CBR_COVERAGE_ELSE(true, false));
            bb_table_print(NULL, global_data);
        }
#ifdef CBR_COVERAGE
        if (options.check)
            bb_table_check_cbr(module_table, global_data);
#endif
        global_data_destroy(global_data);
    }
    /* destroy module table */
    module_table_destroy(module_table);
}

static void
event_init(void)
{
#ifdef DEBUG
    uint64 max_elide_jmp  = 0;
    uint64 max_elide_call = 0;
    /* assuming no elision */
    ASSERT(dr_get_integer_option("max_elide_jmp", &max_elide_jmp) &&
           dr_get_integer_option("max_elide_call", &max_elide_jmp) &&
           max_elide_jmp == 0 && max_elide_call == 0,
           "elision is not supported");
#endif
    /* create module table */
    module_table = module_table_create();
    /* create process data if whole process bb coverage. */
    if (!bbcov_per_thread)
        global_data = global_data_create();
}

static void
options_init(client_id_t id)
{
    const char *opstr = dr_get_options(id);
    const char *s;

    char token[OPTION_MAX_LENGTH];
#ifdef WINDOWS
    /* enable nudge_kills by default */
    options.nudge_kills = true;
#endif
    for (s = dr_get_token(opstr, token, BUFFER_SIZE_ELEMENTS(token));
         s != NULL;
         s = dr_get_token(s, token, BUFFER_SIZE_ELEMENTS(token))) {
        if (strcmp(token, "-dump_text") == 0)
            options.dump_text = true;
        else if (strcmp(token, "-dump_binary") == 0)
            options.dump_binary = true;
#ifdef WINDOWS
        else if (strcmp(token, "-no_nudge_kills") == 0)
            options.nudge_kills = false;
        else if (strcmp(token, "-nudge_kills") == 0)
            options.nudge_kills = true;
#endif
        else if (strcmp(token, "-logdir") == 0) {
            s = dr_get_token(s, options.logdir,
                             BUFFER_SIZE_ELEMENTS(options.logdir));
            USAGE_CHECK(s != NULL, "missing logdir path");
        }
        else if (strcmp(token, "-native_until_thread") == 0) {
            s = dr_get_token(s, token, BUFFER_SIZE_ELEMENTS(token));
            USAGE_CHECK(s != NULL, "missing -native_until_thread number");
            if (s != NULL) {
                int res = dr_sscanf(token, "%d", &options.native_until_thread);
                if (res == 1 && options.native_until_thread > 0)
                    go_native = true;
                else {
                    options.native_until_thread = 0;
                    USAGE_CHECK(false, "invalid -native_until_thread number");
                }
            }
        }
        else if (strcmp(token, "-verbose") == 0) {
            s = dr_get_token(s, token, BUFFER_SIZE_ELEMENTS(token));
            USAGE_CHECK(s != NULL, "missing -verbose number");
            if (s != NULL) {
                int res = dr_sscanf(token, "%u", &verbose);
                USAGE_CHECK(res == 1, "invalid -verbose number");
            }
        }
#ifdef CBR_COVERAGE
        else if (strcmp(token, "-check_cbr") == 0) {
            options.check = true;
        }
        else if (strcmp(token, "-summary_only") == 0) {
            USAGE_CHECK(options.check, "check_cbr is not set");
            options.summary = true;
        }
#endif
        else {
            NOTIFY(0, "UNRECOGNIZED OPTION: \"%s\"\n", token);
            USAGE_CHECK(false, "invalid option");
        }
    }
    /* If both or neither specified, we honor the binary. */
    if ((options.dump_text && options.dump_binary) ||
        (!options.dump_text && !options.dump_binary)) {
        options.dump_text   = false;
        options.dump_binary = true;
    }
}

DR_EXPORT void 
dr_init(client_id_t id)
{
    dr_register_exit_event(event_exit);
    dr_register_thread_init_event(event_thread_init);
    dr_register_thread_exit_event(event_thread_exit);
    dr_register_bb_event(event_basic_block);
    dr_register_module_load_event(event_module_load);
    dr_register_module_unload_event(event_module_unload);
    dr_register_filter_syscall_event(event_filter_syscall);
    dr_register_pre_syscall_event(event_pre_syscall);
#ifdef WINDOWS
    sysnum_TerminateProcess = get_sysnum("NtTerminateProcess");
    dr_register_nudge_event(event_nudge, id);
#else
    dr_register_fork_init_event(event_fork);
#endif
    client_id = id;
    if (dr_using_all_private_caches())
        bbcov_per_thread = true;
    options_init(id);
    event_init();
}
