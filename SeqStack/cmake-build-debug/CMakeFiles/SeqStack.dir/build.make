# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.12

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = D:\MinGW\cmake-3.12.2-win64-x64\cmake-3.12.2-win64-x64\bin\cmake.exe

# The command to remove a file.
RM = D:\MinGW\cmake-3.12.2-win64-x64\cmake-3.12.2-win64-x64\bin\cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = F:\clion_workspace\SeqStack

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = F:\clion_workspace\SeqStack\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/SeqStack.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/SeqStack.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SeqStack.dir/flags.make

CMakeFiles/SeqStack.dir/main.cpp.obj: CMakeFiles/SeqStack.dir/flags.make
CMakeFiles/SeqStack.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=F:\clion_workspace\SeqStack\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/SeqStack.dir/main.cpp.obj"
	D:\MinGW\mingw64\bin\x86_64-w64-mingw32-c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\SeqStack.dir\main.cpp.obj -c F:\clion_workspace\SeqStack\main.cpp

CMakeFiles/SeqStack.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SeqStack.dir/main.cpp.i"
	D:\MinGW\mingw64\bin\x86_64-w64-mingw32-c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E F:\clion_workspace\SeqStack\main.cpp > CMakeFiles\SeqStack.dir\main.cpp.i

CMakeFiles/SeqStack.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SeqStack.dir/main.cpp.s"
	D:\MinGW\mingw64\bin\x86_64-w64-mingw32-c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S F:\clion_workspace\SeqStack\main.cpp -o CMakeFiles\SeqStack.dir\main.cpp.s

# Object files for target SeqStack
SeqStack_OBJECTS = \
"CMakeFiles/SeqStack.dir/main.cpp.obj"

# External object files for target SeqStack
SeqStack_EXTERNAL_OBJECTS =

SeqStack.exe: CMakeFiles/SeqStack.dir/main.cpp.obj
SeqStack.exe: CMakeFiles/SeqStack.dir/build.make
SeqStack.exe: CMakeFiles/SeqStack.dir/linklibs.rsp
SeqStack.exe: CMakeFiles/SeqStack.dir/objects1.rsp
SeqStack.exe: CMakeFiles/SeqStack.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=F:\clion_workspace\SeqStack\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable SeqStack.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\SeqStack.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SeqStack.dir/build: SeqStack.exe

.PHONY : CMakeFiles/SeqStack.dir/build

CMakeFiles/SeqStack.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\SeqStack.dir\cmake_clean.cmake
.PHONY : CMakeFiles/SeqStack.dir/clean

CMakeFiles/SeqStack.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" F:\clion_workspace\SeqStack F:\clion_workspace\SeqStack F:\clion_workspace\SeqStack\cmake-build-debug F:\clion_workspace\SeqStack\cmake-build-debug F:\clion_workspace\SeqStack\cmake-build-debug\CMakeFiles\SeqStack.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/SeqStack.dir/depend
