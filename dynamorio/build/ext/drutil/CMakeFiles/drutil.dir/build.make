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
include ext/drutil/CMakeFiles/drutil.dir/depend.make

# Include the progress variables for this target.
include ext/drutil/CMakeFiles/drutil.dir/progress.make

# Include the compile flags for this target's objects.
include ext/drutil/CMakeFiles/drutil.dir/flags.make

ext/drutil/CMakeFiles/drutil.dir/drutil.c.o: ext/drutil/CMakeFiles/drutil.dir/flags.make
ext/drutil/CMakeFiles/drutil.dir/drutil.c.o: ../ext/drutil/drutil.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/andrew/Dropbox/School/rcos/dr-vis/dynamorio/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object ext/drutil/CMakeFiles/drutil.dir/drutil.c.o"
	cd /home/andrew/Dropbox/School/rcos/dr-vis/dynamorio/build/ext/drutil && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS)  -DX64 -DX64 -DX86_64 -DLINUX -DUSE_VISIBILITY_ATTRIBUTES -fPIC  -m64 -std=gnu99 -fno-strict-aliasing -fno-stack-protector -fvisibility=internal -O3 -g3 -Wall -Werror -Wwrite-strings -Wno-unused-but-set-variable -fno-stack-protector -o CMakeFiles/drutil.dir/drutil.c.o   -c /home/andrew/Dropbox/School/rcos/dr-vis/dynamorio/ext/drutil/drutil.c

ext/drutil/CMakeFiles/drutil.dir/drutil.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/drutil.dir/drutil.c.i"
	cd /home/andrew/Dropbox/School/rcos/dr-vis/dynamorio/build/ext/drutil && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS)  -DX64 -DX64 -DX86_64 -DLINUX -DUSE_VISIBILITY_ATTRIBUTES -fPIC  -m64 -std=gnu99 -fno-strict-aliasing -fno-stack-protector -fvisibility=internal -O3 -g3 -Wall -Werror -Wwrite-strings -Wno-unused-but-set-variable -fno-stack-protector -E /home/andrew/Dropbox/School/rcos/dr-vis/dynamorio/ext/drutil/drutil.c > CMakeFiles/drutil.dir/drutil.c.i

ext/drutil/CMakeFiles/drutil.dir/drutil.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/drutil.dir/drutil.c.s"
	cd /home/andrew/Dropbox/School/rcos/dr-vis/dynamorio/build/ext/drutil && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS)  -DX64 -DX64 -DX86_64 -DLINUX -DUSE_VISIBILITY_ATTRIBUTES -fPIC  -m64 -std=gnu99 -fno-strict-aliasing -fno-stack-protector -fvisibility=internal -O3 -g3 -Wall -Werror -Wwrite-strings -Wno-unused-but-set-variable -fno-stack-protector -S /home/andrew/Dropbox/School/rcos/dr-vis/dynamorio/ext/drutil/drutil.c -o CMakeFiles/drutil.dir/drutil.c.s

ext/drutil/CMakeFiles/drutil.dir/drutil.c.o.requires:
.PHONY : ext/drutil/CMakeFiles/drutil.dir/drutil.c.o.requires

ext/drutil/CMakeFiles/drutil.dir/drutil.c.o.provides: ext/drutil/CMakeFiles/drutil.dir/drutil.c.o.requires
	$(MAKE) -f ext/drutil/CMakeFiles/drutil.dir/build.make ext/drutil/CMakeFiles/drutil.dir/drutil.c.o.provides.build
.PHONY : ext/drutil/CMakeFiles/drutil.dir/drutil.c.o.provides

ext/drutil/CMakeFiles/drutil.dir/drutil.c.o.provides.build: ext/drutil/CMakeFiles/drutil.dir/drutil.c.o

# Object files for target drutil
drutil_OBJECTS = \
"CMakeFiles/drutil.dir/drutil.c.o"

# External object files for target drutil
drutil_EXTERNAL_OBJECTS =

ext/lib64/release/libdrutil.so: ext/drutil/CMakeFiles/drutil.dir/drutil.c.o
ext/lib64/release/libdrutil.so: ext/drutil/CMakeFiles/drutil.dir/build.make
ext/lib64/release/libdrutil.so: lib64/release/libdynamorio.so.4.1
ext/lib64/release/libdrutil.so: ext/lib64/release/libdrmgr.so
ext/lib64/release/libdrutil.so: ext/lib64/release/libdrx.so
ext/lib64/release/libdrutil.so: lib64/release/libdynamorio.so.4.1
ext/lib64/release/libdrutil.so: ext/drutil/CMakeFiles/drutil.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking C shared library ../lib64/release/libdrutil.so"
	cd /home/andrew/Dropbox/School/rcos/dr-vis/dynamorio/build/ext/drutil && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/drutil.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
ext/drutil/CMakeFiles/drutil.dir/build: ext/lib64/release/libdrutil.so
.PHONY : ext/drutil/CMakeFiles/drutil.dir/build

ext/drutil/CMakeFiles/drutil.dir/requires: ext/drutil/CMakeFiles/drutil.dir/drutil.c.o.requires
.PHONY : ext/drutil/CMakeFiles/drutil.dir/requires

ext/drutil/CMakeFiles/drutil.dir/clean:
	cd /home/andrew/Dropbox/School/rcos/dr-vis/dynamorio/build/ext/drutil && $(CMAKE_COMMAND) -P CMakeFiles/drutil.dir/cmake_clean.cmake
.PHONY : ext/drutil/CMakeFiles/drutil.dir/clean

ext/drutil/CMakeFiles/drutil.dir/depend:
	cd /home/andrew/Dropbox/School/rcos/dr-vis/dynamorio/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/andrew/Dropbox/School/rcos/dr-vis/dynamorio /home/andrew/Dropbox/School/rcos/dr-vis/dynamorio/ext/drutil /home/andrew/Dropbox/School/rcos/dr-vis/dynamorio/build /home/andrew/Dropbox/School/rcos/dr-vis/dynamorio/build/ext/drutil /home/andrew/Dropbox/School/rcos/dr-vis/dynamorio/build/ext/drutil/CMakeFiles/drutil.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : ext/drutil/CMakeFiles/drutil.dir/depend

