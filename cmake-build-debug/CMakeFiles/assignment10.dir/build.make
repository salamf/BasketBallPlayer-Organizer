# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/salam/CLionProjects/secondtime/assignment10

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/salam/CLionProjects/secondtime/assignment10/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/assignment10.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/assignment10.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/assignment10.dir/flags.make

CMakeFiles/assignment10.dir/assignment10.c.o: CMakeFiles/assignment10.dir/flags.make
CMakeFiles/assignment10.dir/assignment10.c.o: ../assignment10.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/salam/CLionProjects/secondtime/assignment10/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/assignment10.dir/assignment10.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/assignment10.dir/assignment10.c.o   -c /Users/salam/CLionProjects/secondtime/assignment10/assignment10.c

CMakeFiles/assignment10.dir/assignment10.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/assignment10.dir/assignment10.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/salam/CLionProjects/secondtime/assignment10/assignment10.c > CMakeFiles/assignment10.dir/assignment10.c.i

CMakeFiles/assignment10.dir/assignment10.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/assignment10.dir/assignment10.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/salam/CLionProjects/secondtime/assignment10/assignment10.c -o CMakeFiles/assignment10.dir/assignment10.c.s

# Object files for target assignment10
assignment10_OBJECTS = \
"CMakeFiles/assignment10.dir/assignment10.c.o"

# External object files for target assignment10
assignment10_EXTERNAL_OBJECTS =

assignment10: CMakeFiles/assignment10.dir/assignment10.c.o
assignment10: CMakeFiles/assignment10.dir/build.make
assignment10: CMakeFiles/assignment10.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/salam/CLionProjects/secondtime/assignment10/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable assignment10"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/assignment10.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/assignment10.dir/build: assignment10

.PHONY : CMakeFiles/assignment10.dir/build

CMakeFiles/assignment10.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/assignment10.dir/cmake_clean.cmake
.PHONY : CMakeFiles/assignment10.dir/clean

CMakeFiles/assignment10.dir/depend:
	cd /Users/salam/CLionProjects/secondtime/assignment10/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/salam/CLionProjects/secondtime/assignment10 /Users/salam/CLionProjects/secondtime/assignment10 /Users/salam/CLionProjects/secondtime/assignment10/cmake-build-debug /Users/salam/CLionProjects/secondtime/assignment10/cmake-build-debug /Users/salam/CLionProjects/secondtime/assignment10/cmake-build-debug/CMakeFiles/assignment10.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/assignment10.dir/depend
