# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.7

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/lichenyang/ClionProjects/SelectServer

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/lichenyang/ClionProjects/SelectServer/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/SelectServer.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/SelectServer.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SelectServer.dir/flags.make

CMakeFiles/SelectServer.dir/main.cpp.o: CMakeFiles/SelectServer.dir/flags.make
CMakeFiles/SelectServer.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/lichenyang/ClionProjects/SelectServer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/SelectServer.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SelectServer.dir/main.cpp.o -c /Users/lichenyang/ClionProjects/SelectServer/main.cpp

CMakeFiles/SelectServer.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SelectServer.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/lichenyang/ClionProjects/SelectServer/main.cpp > CMakeFiles/SelectServer.dir/main.cpp.i

CMakeFiles/SelectServer.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SelectServer.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/lichenyang/ClionProjects/SelectServer/main.cpp -o CMakeFiles/SelectServer.dir/main.cpp.s

CMakeFiles/SelectServer.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/SelectServer.dir/main.cpp.o.requires

CMakeFiles/SelectServer.dir/main.cpp.o.provides: CMakeFiles/SelectServer.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/SelectServer.dir/build.make CMakeFiles/SelectServer.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/SelectServer.dir/main.cpp.o.provides

CMakeFiles/SelectServer.dir/main.cpp.o.provides.build: CMakeFiles/SelectServer.dir/main.cpp.o


# Object files for target SelectServer
SelectServer_OBJECTS = \
"CMakeFiles/SelectServer.dir/main.cpp.o"

# External object files for target SelectServer
SelectServer_EXTERNAL_OBJECTS =

SelectServer: CMakeFiles/SelectServer.dir/main.cpp.o
SelectServer: CMakeFiles/SelectServer.dir/build.make
SelectServer: CMakeFiles/SelectServer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/lichenyang/ClionProjects/SelectServer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable SelectServer"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SelectServer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SelectServer.dir/build: SelectServer

.PHONY : CMakeFiles/SelectServer.dir/build

CMakeFiles/SelectServer.dir/requires: CMakeFiles/SelectServer.dir/main.cpp.o.requires

.PHONY : CMakeFiles/SelectServer.dir/requires

CMakeFiles/SelectServer.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/SelectServer.dir/cmake_clean.cmake
.PHONY : CMakeFiles/SelectServer.dir/clean

CMakeFiles/SelectServer.dir/depend:
	cd /Users/lichenyang/ClionProjects/SelectServer/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/lichenyang/ClionProjects/SelectServer /Users/lichenyang/ClionProjects/SelectServer /Users/lichenyang/ClionProjects/SelectServer/cmake-build-debug /Users/lichenyang/ClionProjects/SelectServer/cmake-build-debug /Users/lichenyang/ClionProjects/SelectServer/cmake-build-debug/CMakeFiles/SelectServer.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/SelectServer.dir/depend

