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
include ext/drmgr/CMakeFiles/drmgr.dir/depend.make

# Include the progress variables for this target.
include ext/drmgr/CMakeFiles/drmgr.dir/progress.make

# Include the compile flags for this target's objects.
include ext/drmgr/CMakeFiles/drmgr.dir/flags.make

ext/drmgr/CMakeFiles/drmgr.dir/drmgr.c.o: ext/drmgr/CMakeFiles/drmgr.dir/flags.make
ext/drmgr/CMakeFiles/drmgr.dir/drmgr.c.o: ../ext/drmgr/drmgr.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/andrew/Dropbox/School/rcos/dr-vis/dynamorio/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object ext/drmgr/CMakeFiles/drmgr.dir/drmgr.c.o"
	cd /home/andrew/Dropbox/School/rcos/dr-vis/dynamorio/build/ext/drmgr && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS)  -DX64 -DX64 -DX86_64 -DLINUX -DUSE_VISIBILITY_ATTRIBUTES -fPIC  -m64 -std=gnu99 -fno-strict-aliasing -fno-stack-protector -fvisibility=internal -O3 -g3 -Wall -Werror -Wwrite-strings -Wno-unused-but-set-variable -fno-stack-protector -o CMakeFiles/drmgr.dir/drmgr.c.o   -c /home/andrew/Dropbox/School/rcos/dr-vis/dynamorio/ext/drmgr/drmgr.c

ext/drmgr/CMakeFiles/drmgr.dir/drmgr.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/drmgr.dir/drmgr.c.i"
	cd /home/andrew/Dropbox/School/rcos/dr-vis/dynamorio/build/ext/drmgr && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS)  -DX64 -DX64 -DX86_64 -DLINUX -DUSE_VISIBILITY_ATTRIBUTES -fPIC  -m64 -std=gnu99 -fno-strict-aliasing -fno-stack-protector -fvisibility=internal -O3 -g3 -Wall -Werror -Wwrite-strings -Wno-unused-but-set-variable -fno-stack-protector -E /home/andrew/Dropbox/School/rcos/dr-vis/dynamorio/ext/drmgr/drmgr.c > CMakeFiles/drmgr.dir/drmgr.c.i

ext/drmgr/CMakeFiles/drmgr.dir/drmgr.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/drmgr.dir/drmgr.c.s"
	cd /home/andrew/Dropbox/School/rcos/dr-vis/dynamorio/build/ext/drmgr && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS)  -DX64 -DX64 -DX86_64 -DLINUX -DUSE_VISIBILITY_ATTRIBUTES -fPIC  -m64 -std=gnu99 -fno-strict-aliasing -fno-stack-protector -fvisibility=internal -O3 -g3 -Wall -Werror -Wwrite-strings -Wno-unused-but-set-variable -fno-stack-protector -S /home/andrew/Dropbox/School/rcos/dr-vis/dynamorio/ext/drmgr/drmgr.c -o CMakeFiles/drmgr.dir/drmgr.c.s

ext/drmgr/CMakeFiles/drmgr.dir/drmgr.c.o.requires:
.PHONY : ext/drmgr/CMakeFiles/drmgr.dir/drmgr.c.o.requires

ext/drmgr/CMakeFiles/drmgr.dir/drmgr.c.o.provides: ext/drmgr/CMakeFiles/drmgr.dir/drmgr.c.o.requires
	$(MAKE) -f ext/drmgr/CMakeFiles/drmgr.dir/build.make ext/drmgr/CMakeFiles/drmgr.dir/drmgr.c.o.provides.build
.PHONY : ext/drmgr/CMakeFiles/drmgr.dir/drmgr.c.o.provides

ext/drmgr/CMakeFiles/drmgr.dir/drmgr.c.o.provides.build: ext/drmgr/CMakeFiles/drmgr.dir/drmgr.c.o

# Object files for target drmgr
drmgr_OBJECTS = \
"CMakeFiles/drmgr.dir/drmgr.c.o"

# External object files for target drmgr
drmgr_EXTERNAL_OBJECTS =

ext/lib64/release/libdrmgr.so: ext/drmgr/CMakeFiles/drmgr.dir/drmgr.c.o
ext/lib64/release/libdrmgr.so: ext/drmgr/CMakeFiles/drmgr.dir/build.make
ext/lib64/release/libdrmgr.so: lib64/release/libdynamorio.so.4.1
ext/lib64/release/libdrmgr.so: ext/lib64/release/libdrx.so
ext/lib64/release/libdrmgr.so: lib64/release/libdynamorio.so.4.1
ext/lib64/release/libdrmgr.so: ext/drmgr/CMakeFiles/drmgr.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking C shared library ../lib64/release/libdrmgr.so"
	cd /home/andrew/Dropbox/School/rcos/dr-vis/dynamorio/build/ext/drmgr && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/drmgr.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
ext/drmgr/CMakeFiles/drmgr.dir/build: ext/lib64/release/libdrmgr.so
.PHONY : ext/drmgr/CMakeFiles/drmgr.dir/build

ext/drmgr/CMakeFiles/drmgr.dir/requires: ext/drmgr/CMakeFiles/drmgr.dir/drmgr.c.o.requires
.PHONY : ext/drmgr/CMakeFiles/drmgr.dir/requires

ext/drmgr/CMakeFiles/drmgr.dir/clean:
	cd /home/andrew/Dropbox/School/rcos/dr-vis/dynamorio/build/ext/drmgr && $(CMAKE_COMMAND) -P CMakeFiles/drmgr.dir/cmake_clean.cmake
.PHONY : ext/drmgr/CMakeFiles/drmgr.dir/clean

ext/drmgr/CMakeFiles/drmgr.dir/depend:
	cd /home/andrew/Dropbox/School/rcos/dr-vis/dynamorio/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/andrew/Dropbox/School/rcos/dr-vis/dynamorio /home/andrew/Dropbox/School/rcos/dr-vis/dynamorio/ext/drmgr /home/andrew/Dropbox/School/rcos/dr-vis/dynamorio/build /home/andrew/Dropbox/School/rcos/dr-vis/dynamorio/build/ext/drmgr /home/andrew/Dropbox/School/rcos/dr-vis/dynamorio/build/ext/drmgr/CMakeFiles/drmgr.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : ext/drmgr/CMakeFiles/drmgr.dir/depend

