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

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /data/scratch/charithm/projects/revec/regression_tests/simd/prj/cmake

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /data/scratch/charithm/projects/revec/regression_tests/simd/prj/cmake

# Include any dependencies generated for this target.
include CMakeFiles/TestCheckC.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/TestCheckC.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/TestCheckC.dir/flags.make

CMakeFiles/TestCheckC.dir/data/scratch/charithm/projects/revec/regression_tests/simd/src/Test/TestCheckC.c.o: CMakeFiles/TestCheckC.dir/flags.make
CMakeFiles/TestCheckC.dir/data/scratch/charithm/projects/revec/regression_tests/simd/src/Test/TestCheckC.c.o: /data/scratch/charithm/projects/revec/regression_tests/simd/src/Test/TestCheckC.c
	$(CMAKE_COMMAND) -E cmake_progress_report /data/scratch/charithm/projects/revec/regression_tests/simd/prj/cmake/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/TestCheckC.dir/data/scratch/charithm/projects/revec/regression_tests/simd/src/Test/TestCheckC.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/TestCheckC.dir/data/scratch/charithm/projects/revec/regression_tests/simd/src/Test/TestCheckC.c.o   -c /data/scratch/charithm/projects/revec/regression_tests/simd/src/Test/TestCheckC.c

CMakeFiles/TestCheckC.dir/data/scratch/charithm/projects/revec/regression_tests/simd/src/Test/TestCheckC.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/TestCheckC.dir/data/scratch/charithm/projects/revec/regression_tests/simd/src/Test/TestCheckC.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /data/scratch/charithm/projects/revec/regression_tests/simd/src/Test/TestCheckC.c > CMakeFiles/TestCheckC.dir/data/scratch/charithm/projects/revec/regression_tests/simd/src/Test/TestCheckC.c.i

CMakeFiles/TestCheckC.dir/data/scratch/charithm/projects/revec/regression_tests/simd/src/Test/TestCheckC.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/TestCheckC.dir/data/scratch/charithm/projects/revec/regression_tests/simd/src/Test/TestCheckC.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /data/scratch/charithm/projects/revec/regression_tests/simd/src/Test/TestCheckC.c -o CMakeFiles/TestCheckC.dir/data/scratch/charithm/projects/revec/regression_tests/simd/src/Test/TestCheckC.c.s

CMakeFiles/TestCheckC.dir/data/scratch/charithm/projects/revec/regression_tests/simd/src/Test/TestCheckC.c.o.requires:
.PHONY : CMakeFiles/TestCheckC.dir/data/scratch/charithm/projects/revec/regression_tests/simd/src/Test/TestCheckC.c.o.requires

CMakeFiles/TestCheckC.dir/data/scratch/charithm/projects/revec/regression_tests/simd/src/Test/TestCheckC.c.o.provides: CMakeFiles/TestCheckC.dir/data/scratch/charithm/projects/revec/regression_tests/simd/src/Test/TestCheckC.c.o.requires
	$(MAKE) -f CMakeFiles/TestCheckC.dir/build.make CMakeFiles/TestCheckC.dir/data/scratch/charithm/projects/revec/regression_tests/simd/src/Test/TestCheckC.c.o.provides.build
.PHONY : CMakeFiles/TestCheckC.dir/data/scratch/charithm/projects/revec/regression_tests/simd/src/Test/TestCheckC.c.o.provides

CMakeFiles/TestCheckC.dir/data/scratch/charithm/projects/revec/regression_tests/simd/src/Test/TestCheckC.c.o.provides.build: CMakeFiles/TestCheckC.dir/data/scratch/charithm/projects/revec/regression_tests/simd/src/Test/TestCheckC.c.o

# Object files for target TestCheckC
TestCheckC_OBJECTS = \
"CMakeFiles/TestCheckC.dir/data/scratch/charithm/projects/revec/regression_tests/simd/src/Test/TestCheckC.c.o"

# External object files for target TestCheckC
TestCheckC_EXTERNAL_OBJECTS =

libTestCheckC.a: CMakeFiles/TestCheckC.dir/data/scratch/charithm/projects/revec/regression_tests/simd/src/Test/TestCheckC.c.o
libTestCheckC.a: CMakeFiles/TestCheckC.dir/build.make
libTestCheckC.a: CMakeFiles/TestCheckC.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking C static library libTestCheckC.a"
	$(CMAKE_COMMAND) -P CMakeFiles/TestCheckC.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TestCheckC.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/TestCheckC.dir/build: libTestCheckC.a
.PHONY : CMakeFiles/TestCheckC.dir/build

CMakeFiles/TestCheckC.dir/requires: CMakeFiles/TestCheckC.dir/data/scratch/charithm/projects/revec/regression_tests/simd/src/Test/TestCheckC.c.o.requires
.PHONY : CMakeFiles/TestCheckC.dir/requires

CMakeFiles/TestCheckC.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/TestCheckC.dir/cmake_clean.cmake
.PHONY : CMakeFiles/TestCheckC.dir/clean

CMakeFiles/TestCheckC.dir/depend:
	cd /data/scratch/charithm/projects/revec/regression_tests/simd/prj/cmake && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /data/scratch/charithm/projects/revec/regression_tests/simd/prj/cmake /data/scratch/charithm/projects/revec/regression_tests/simd/prj/cmake /data/scratch/charithm/projects/revec/regression_tests/simd/prj/cmake /data/scratch/charithm/projects/revec/regression_tests/simd/prj/cmake /data/scratch/charithm/projects/revec/regression_tests/simd/prj/cmake/CMakeFiles/TestCheckC.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/TestCheckC.dir/depend

