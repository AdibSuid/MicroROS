# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
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
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/humble/microros_ws/src/MicroROS

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/humble/microros_ws/src/MicroROS/build/var

# Include any dependencies generated for this target.
include CMakeFiles/var_info.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/var_info.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/var_info.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/var_info.dir/flags.make

CMakeFiles/var_info.dir/src/var_info.cpp.o: CMakeFiles/var_info.dir/flags.make
CMakeFiles/var_info.dir/src/var_info.cpp.o: ../../src/var_info.cpp
CMakeFiles/var_info.dir/src/var_info.cpp.o: CMakeFiles/var_info.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/humble/microros_ws/src/MicroROS/build/var/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/var_info.dir/src/var_info.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/var_info.dir/src/var_info.cpp.o -MF CMakeFiles/var_info.dir/src/var_info.cpp.o.d -o CMakeFiles/var_info.dir/src/var_info.cpp.o -c /home/humble/microros_ws/src/MicroROS/src/var_info.cpp

CMakeFiles/var_info.dir/src/var_info.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/var_info.dir/src/var_info.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/humble/microros_ws/src/MicroROS/src/var_info.cpp > CMakeFiles/var_info.dir/src/var_info.cpp.i

CMakeFiles/var_info.dir/src/var_info.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/var_info.dir/src/var_info.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/humble/microros_ws/src/MicroROS/src/var_info.cpp -o CMakeFiles/var_info.dir/src/var_info.cpp.s

# Object files for target var_info
var_info_OBJECTS = \
"CMakeFiles/var_info.dir/src/var_info.cpp.o"

# External object files for target var_info
var_info_EXTERNAL_OBJECTS =

var_info: CMakeFiles/var_info.dir/src/var_info.cpp.o
var_info: CMakeFiles/var_info.dir/build.make
var_info: CMakeFiles/var_info.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/humble/microros_ws/src/MicroROS/build/var/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable var_info"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/var_info.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/var_info.dir/build: var_info
.PHONY : CMakeFiles/var_info.dir/build

CMakeFiles/var_info.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/var_info.dir/cmake_clean.cmake
.PHONY : CMakeFiles/var_info.dir/clean

CMakeFiles/var_info.dir/depend:
	cd /home/humble/microros_ws/src/MicroROS/build/var && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/humble/microros_ws/src/MicroROS /home/humble/microros_ws/src/MicroROS /home/humble/microros_ws/src/MicroROS/build/var /home/humble/microros_ws/src/MicroROS/build/var /home/humble/microros_ws/src/MicroROS/build/var/CMakeFiles/var_info.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/var_info.dir/depend
