# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/taofu/algorithm-c/dataStruct/huffmanTree

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/taofu/algorithm-c/dataStruct/huffmanTree/build

# Include any dependencies generated for this target.
include CMakeFiles/haffumanTree.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/haffumanTree.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/haffumanTree.dir/flags.make

CMakeFiles/haffumanTree.dir/main.cpp.o: CMakeFiles/haffumanTree.dir/flags.make
CMakeFiles/haffumanTree.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/taofu/algorithm-c/dataStruct/huffmanTree/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/haffumanTree.dir/main.cpp.o"
	/usr/bin/g++-7  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/haffumanTree.dir/main.cpp.o -c /home/taofu/algorithm-c/dataStruct/huffmanTree/main.cpp

CMakeFiles/haffumanTree.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/haffumanTree.dir/main.cpp.i"
	/usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/taofu/algorithm-c/dataStruct/huffmanTree/main.cpp > CMakeFiles/haffumanTree.dir/main.cpp.i

CMakeFiles/haffumanTree.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/haffumanTree.dir/main.cpp.s"
	/usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/taofu/algorithm-c/dataStruct/huffmanTree/main.cpp -o CMakeFiles/haffumanTree.dir/main.cpp.s

CMakeFiles/haffumanTree.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/haffumanTree.dir/main.cpp.o.requires

CMakeFiles/haffumanTree.dir/main.cpp.o.provides: CMakeFiles/haffumanTree.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/haffumanTree.dir/build.make CMakeFiles/haffumanTree.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/haffumanTree.dir/main.cpp.o.provides

CMakeFiles/haffumanTree.dir/main.cpp.o.provides.build: CMakeFiles/haffumanTree.dir/main.cpp.o


# Object files for target haffumanTree
haffumanTree_OBJECTS = \
"CMakeFiles/haffumanTree.dir/main.cpp.o"

# External object files for target haffumanTree
haffumanTree_EXTERNAL_OBJECTS =

haffumanTree: CMakeFiles/haffumanTree.dir/main.cpp.o
haffumanTree: CMakeFiles/haffumanTree.dir/build.make
haffumanTree: CMakeFiles/haffumanTree.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/taofu/algorithm-c/dataStruct/huffmanTree/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable haffumanTree"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/haffumanTree.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/haffumanTree.dir/build: haffumanTree

.PHONY : CMakeFiles/haffumanTree.dir/build

CMakeFiles/haffumanTree.dir/requires: CMakeFiles/haffumanTree.dir/main.cpp.o.requires

.PHONY : CMakeFiles/haffumanTree.dir/requires

CMakeFiles/haffumanTree.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/haffumanTree.dir/cmake_clean.cmake
.PHONY : CMakeFiles/haffumanTree.dir/clean

CMakeFiles/haffumanTree.dir/depend:
	cd /home/taofu/algorithm-c/dataStruct/huffmanTree/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/taofu/algorithm-c/dataStruct/huffmanTree /home/taofu/algorithm-c/dataStruct/huffmanTree /home/taofu/algorithm-c/dataStruct/huffmanTree/build /home/taofu/algorithm-c/dataStruct/huffmanTree/build /home/taofu/algorithm-c/dataStruct/huffmanTree/build/CMakeFiles/haffumanTree.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/haffumanTree.dir/depend

