# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_SOURCE_DIR = "/Users/lishundong/Desktop/make future/DataStructure&Alorithm"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/lishundong/Desktop/make future/DataStructure&Alorithm/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/DataStructure_Alorithm.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/DataStructure_Alorithm.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/DataStructure_Alorithm.dir/flags.make

CMakeFiles/DataStructure_Alorithm.dir/main.cpp.o: CMakeFiles/DataStructure_Alorithm.dir/flags.make
CMakeFiles/DataStructure_Alorithm.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/lishundong/Desktop/make future/DataStructure&Alorithm/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/DataStructure_Alorithm.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/DataStructure_Alorithm.dir/main.cpp.o -c "/Users/lishundong/Desktop/make future/DataStructure&Alorithm/main.cpp"

CMakeFiles/DataStructure_Alorithm.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DataStructure_Alorithm.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/lishundong/Desktop/make future/DataStructure&Alorithm/main.cpp" > CMakeFiles/DataStructure_Alorithm.dir/main.cpp.i

CMakeFiles/DataStructure_Alorithm.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DataStructure_Alorithm.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/lishundong/Desktop/make future/DataStructure&Alorithm/main.cpp" -o CMakeFiles/DataStructure_Alorithm.dir/main.cpp.s

# Object files for target DataStructure_Alorithm
DataStructure_Alorithm_OBJECTS = \
"CMakeFiles/DataStructure_Alorithm.dir/main.cpp.o"

# External object files for target DataStructure_Alorithm
DataStructure_Alorithm_EXTERNAL_OBJECTS =

DataStructure_Alorithm: CMakeFiles/DataStructure_Alorithm.dir/main.cpp.o
DataStructure_Alorithm: CMakeFiles/DataStructure_Alorithm.dir/build.make
DataStructure_Alorithm: CMakeFiles/DataStructure_Alorithm.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/lishundong/Desktop/make future/DataStructure&Alorithm/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable DataStructure_Alorithm"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/DataStructure_Alorithm.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/DataStructure_Alorithm.dir/build: DataStructure_Alorithm

.PHONY : CMakeFiles/DataStructure_Alorithm.dir/build

CMakeFiles/DataStructure_Alorithm.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/DataStructure_Alorithm.dir/cmake_clean.cmake
.PHONY : CMakeFiles/DataStructure_Alorithm.dir/clean

CMakeFiles/DataStructure_Alorithm.dir/depend:
	cd "/Users/lishundong/Desktop/make future/DataStructure&Alorithm/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/lishundong/Desktop/make future/DataStructure&Alorithm" "/Users/lishundong/Desktop/make future/DataStructure&Alorithm" "/Users/lishundong/Desktop/make future/DataStructure&Alorithm/cmake-build-debug" "/Users/lishundong/Desktop/make future/DataStructure&Alorithm/cmake-build-debug" "/Users/lishundong/Desktop/make future/DataStructure&Alorithm/cmake-build-debug/CMakeFiles/DataStructure_Alorithm.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/DataStructure_Alorithm.dir/depend

