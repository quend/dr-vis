# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list

# Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/andrew/Dropbox/School/rcos/dr-vis/dynamorio

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/andrew/Dropbox/School/rcos/dr-vis/dynamorio/build

# Include any dependencies generated for this target.
include libutil/CMakeFiles/drconfiglib.dir/depend.make

# Include the progress variables for this target.
include libutil/CMakeFiles/drconfiglib.dir/progress.make

# Include the compile flags for this target's objects.
include libutil/CMakeFiles/drconfiglib.dir/flags.make

libutil/CMakeFiles/drconfiglib.dir/dr_config.c.o: libutil/CMakeFiles/drconfiglib.dir/flags.make
libutil/CMakeFiles/drconfiglib.dir/dr_config.c.o: ../libutil/dr_config.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/andrew/Dropbox/School/rcos/dr-vis/dynamorio/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object libutil/CMakeFiles/drconfiglib.dir/dr_config.c.o"
	cd /home/andrew/Dropbox/School/rcos/dr-vis/dynamorio/build/libutil && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS)  -DRC_IS_DRCONFIGLIB -o CMakeFiles/drconfiglib.dir/dr_config.c.o   -c /home/andrew/Dropbox/School/rcos/dr-vis/dynamorio/libutil/dr_config.c

libutil/CMakeFiles/drconfiglib.dir/dr_config.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/drconfiglib.dir/dr_config.c.i"
	cd /home/andrew/Dropbox/School/rcos/dr-vis/dynamorio/build/libutil && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS)  -DRC_IS_DRCONFIGLIB -E /home/andrew/Dropbox/School/rcos/dr-vis/dynamorio/libutil/dr_config.c > CMakeFiles/drconfiglib.dir/dr_config.c.i

libutil/CMakeFiles/drconfiglib.dir/dr_config.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/drconfiglib.dir/dr_config.c.s"
	cd /home/andrew/Dropbox/School/rcos/dr-vis/dynamorio/build/libutil && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS)  -DRC_IS_DRCONFIGLIB -S /home/andrew/Dropbox/School/rcos/dr-vis/dynamorio/libutil/dr_config.c -o CMakeFiles/drconfiglib.dir/dr_config.c.s

libutil/CMakeFiles/drconfiglib.dir/dr_config.c.o.requires:
.PHONY : libutil/CMakeFiles/drconfiglib.dir/dr_config.c.o.requires

libutil/CMakeFiles/drconfiglib.dir/dr_config.c.o.provides: libutil/CMakeFiles/drconfiglib.dir/dr_config.c.o.requires
	$(MAKE) -f libutil/CMakeFiles/drconfiglib.dir/build.make libutil/CMakeFiles/drconfiglib.dir/dr_config.c.o.provides.build
.PHONY : libutil/CMakeFiles/drconfiglib.dir/dr_config.c.o.provides

libutil/CMakeFiles/drconfiglib.dir/dr_config.c.o.provides.build: libutil/CMakeFiles/drconfiglib.dir/dr_config.c.o

libutil/CMakeFiles/drconfiglib.dir/utils.c.o: libutil/CMakeFiles/drconfiglib.dir/flags.make
libutil/CMakeFiles/drconfiglib.dir/utils.c.o: ../libutil/utils.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/andrew/Dropbox/School/rcos/dr-vis/dynamorio/build/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object libutil/CMakeFiles/drconfiglib.dir/utils.c.o"
	cd /home/andrew/Dropbox/School/rcos/dr-vis/dynamorio/build/libutil && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS)  -DRC_IS_DRCONFIGLIB -o CMakeFiles/drconfiglib.dir/utils.c.o   -c /home/andrew/Dropbox/School/rcos/dr-vis/dynamorio/libutil/utils.c

libutil/CMakeFiles/drconfiglib.dir/utils.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/drconfiglib.dir/utils.c.i"
	cd /home/andrew/Dropbox/School/rcos/dr-vis/dynamorio/build/libutil && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS)  -DRC_IS_DRCONFIGLIB -E /home/andrew/Dropbox/School/rcos/dr-vis/dynamorio/libutil/utils.c > CMakeFiles/drconfiglib.dir/utils.c.i

libutil/CMakeFiles/drconfiglib.dir/utils.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/drconfiglib.dir/utils.c.s"
	cd /home/andrew/Dropbox/School/rcos/dr-vis/dynamorio/build/libutil && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS)  -DRC_IS_DRCONFIGLIB -S /home/andrew/Dropbox/School/rcos/dr-vis/dynamorio/libutil/utils.c -o CMakeFiles/drconfiglib.dir/utils.c.s

libutil/CMakeFiles/drconfiglib.dir/utils.c.o.requires:
.PHONY : libutil/CMakeFiles/drconfiglib.dir/utils.c.o.requires

libutil/CMakeFiles/drconfiglib.dir/utils.c.o.provides: libutil/CMakeFiles/drconfiglib.dir/utils.c.o.requires
	$(MAKE) -f libutil/CMakeFiles/drconfiglib.dir/build.make libutil/CMakeFiles/drconfiglib.dir/utils.c.o.provides.build
.PHONY : libutil/CMakeFiles/drconfiglib.dir/utils.c.o.provides

libutil/CMakeFiles/drconfiglib.dir/utils.c.o.provides.build: libutil/CMakeFiles/drconfiglib.dir/utils.c.o

# Object files for target drconfiglib
drconfiglib_OBJECTS = \
"CMakeFiles/drconfiglib.dir/dr_config.c.o" \
"CMakeFiles/drconfiglib.dir/utils.c.o"

# External object files for target drconfiglib
drconfiglib_EXTERNAL_OBJECTS =

lib64/libdrconfiglib.so: libutil/CMakeFiles/drconfiglib.dir/dr_config.c.o
lib64/libdrconfiglib.so: libutil/CMakeFiles/drconfiglib.dir/utils.c.o
lib64/libdrconfiglib.so: libutil/CMakeFiles/drconfiglib.dir/build.make
lib64/libdrconfiglib.so: libutil/CMakeFiles/drconfiglib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking C shared library ../lib64/libdrconfiglib.so"
	cd /home/andrew/Dropbox/School/rcos/dr-vis/dynamorio/build/libutil && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/drconfiglib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
libutil/CMakeFiles/drconfiglib.dir/build: lib64/libdrconfiglib.so
.PHONY : libutil/CMakeFiles/drconfiglib.dir/build

libutil/CMakeFiles/drconfiglib.dir/requires: libutil/CMakeFiles/drconfiglib.dir/dr_config.c.o.requires
libutil/CMakeFiles/drconfiglib.dir/requires: libutil/CMakeFiles/drconfiglib.dir/utils.c.o.requires
.PHONY : libutil/CMakeFiles/drconfiglib.dir/requires

libutil/CMakeFiles/drconfiglib.dir/clean:
	cd /home/andrew/Dropbox/School/rcos/dr-vis/dynamorio/build/libutil && $(CMAKE_COMMAND) -P CMakeFiles/drconfiglib.dir/cmake_clean.cmake
.PHONY : libutil/CMakeFiles/drconfiglib.dir/clean

libutil/CMakeFiles/drconfiglib.dir/depend:
	cd /home/andrew/Dropbox/School/rcos/dr-vis/dynamorio/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/andrew/Dropbox/School/rcos/dr-vis/dynamorio /home/andrew/Dropbox/School/rcos/dr-vis/dynamorio/libutil /home/andrew/Dropbox/School/rcos/dr-vis/dynamorio/build /home/andrew/Dropbox/School/rcos/dr-vis/dynamorio/build/libutil /home/andrew/Dropbox/School/rcos/dr-vis/dynamorio/build/libutil/CMakeFiles/drconfiglib.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : libutil/CMakeFiles/drconfiglib.dir/depend

