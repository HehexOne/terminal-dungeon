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
CMAKE_COMMAND = /run/media/hehexone/HehexDrive/Programs/IDEs/clion-2019.2.5/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /run/media/hehexone/HehexDrive/Programs/IDEs/clion-2019.2.5/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /run/media/hehexone/HehexDrive/Projects/terminal-game

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /run/media/hehexone/HehexDrive/Projects/terminal-game/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/terminal_game.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/terminal_game.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/terminal_game.dir/flags.make

CMakeFiles/terminal_game.dir/main.cpp.o: CMakeFiles/terminal_game.dir/flags.make
CMakeFiles/terminal_game.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/run/media/hehexone/HehexDrive/Projects/terminal-game/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/terminal_game.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/terminal_game.dir/main.cpp.o -c /run/media/hehexone/HehexDrive/Projects/terminal-game/main.cpp

CMakeFiles/terminal_game.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/terminal_game.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /run/media/hehexone/HehexDrive/Projects/terminal-game/main.cpp > CMakeFiles/terminal_game.dir/main.cpp.i

CMakeFiles/terminal_game.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/terminal_game.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /run/media/hehexone/HehexDrive/Projects/terminal-game/main.cpp -o CMakeFiles/terminal_game.dir/main.cpp.s

# Object files for target terminal_game
terminal_game_OBJECTS = \
"CMakeFiles/terminal_game.dir/main.cpp.o"

# External object files for target terminal_game
terminal_game_EXTERNAL_OBJECTS =

terminal_game: CMakeFiles/terminal_game.dir/main.cpp.o
terminal_game: CMakeFiles/terminal_game.dir/build.make
terminal_game: CMakeFiles/terminal_game.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/run/media/hehexone/HehexDrive/Projects/terminal-game/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable terminal_game"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/terminal_game.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/terminal_game.dir/build: terminal_game

.PHONY : CMakeFiles/terminal_game.dir/build

CMakeFiles/terminal_game.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/terminal_game.dir/cmake_clean.cmake
.PHONY : CMakeFiles/terminal_game.dir/clean

CMakeFiles/terminal_game.dir/depend:
	cd /run/media/hehexone/HehexDrive/Projects/terminal-game/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /run/media/hehexone/HehexDrive/Projects/terminal-game /run/media/hehexone/HehexDrive/Projects/terminal-game /run/media/hehexone/HehexDrive/Projects/terminal-game/cmake-build-debug /run/media/hehexone/HehexDrive/Projects/terminal-game/cmake-build-debug /run/media/hehexone/HehexDrive/Projects/terminal-game/cmake-build-debug/CMakeFiles/terminal_game.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/terminal_game.dir/depend

