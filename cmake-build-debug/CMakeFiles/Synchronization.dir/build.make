# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

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
CMAKE_COMMAND = /opt/clion-2018.2.4/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /opt/clion-2018.2.4/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/aya/CLionProjects/Synchronization

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/aya/CLionProjects/Synchronization/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Synchronization.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Synchronization.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Synchronization.dir/flags.make

CMakeFiles/Synchronization.dir/main.c.o: CMakeFiles/Synchronization.dir/flags.make
CMakeFiles/Synchronization.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/aya/CLionProjects/Synchronization/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Synchronization.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Synchronization.dir/main.c.o   -c /home/aya/CLionProjects/Synchronization/main.c

CMakeFiles/Synchronization.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Synchronization.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/aya/CLionProjects/Synchronization/main.c > CMakeFiles/Synchronization.dir/main.c.i

CMakeFiles/Synchronization.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Synchronization.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/aya/CLionProjects/Synchronization/main.c -o CMakeFiles/Synchronization.dir/main.c.s

CMakeFiles/Synchronization.dir/BatManager.c.o: CMakeFiles/Synchronization.dir/flags.make
CMakeFiles/Synchronization.dir/BatManager.c.o: ../BatManager.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/aya/CLionProjects/Synchronization/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/Synchronization.dir/BatManager.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Synchronization.dir/BatManager.c.o   -c /home/aya/CLionProjects/Synchronization/BatManager.c

CMakeFiles/Synchronization.dir/BatManager.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Synchronization.dir/BatManager.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/aya/CLionProjects/Synchronization/BatManager.c > CMakeFiles/Synchronization.dir/BatManager.c.i

CMakeFiles/Synchronization.dir/BatManager.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Synchronization.dir/BatManager.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/aya/CLionProjects/Synchronization/BatManager.c -o CMakeFiles/Synchronization.dir/BatManager.c.s

# Object files for target Synchronization
Synchronization_OBJECTS = \
"CMakeFiles/Synchronization.dir/main.c.o" \
"CMakeFiles/Synchronization.dir/BatManager.c.o"

# External object files for target Synchronization
Synchronization_EXTERNAL_OBJECTS =

Synchronization: CMakeFiles/Synchronization.dir/main.c.o
Synchronization: CMakeFiles/Synchronization.dir/BatManager.c.o
Synchronization: CMakeFiles/Synchronization.dir/build.make
Synchronization: CMakeFiles/Synchronization.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/aya/CLionProjects/Synchronization/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable Synchronization"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Synchronization.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Synchronization.dir/build: Synchronization

.PHONY : CMakeFiles/Synchronization.dir/build

CMakeFiles/Synchronization.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Synchronization.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Synchronization.dir/clean

CMakeFiles/Synchronization.dir/depend:
	cd /home/aya/CLionProjects/Synchronization/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/aya/CLionProjects/Synchronization /home/aya/CLionProjects/Synchronization /home/aya/CLionProjects/Synchronization/cmake-build-debug /home/aya/CLionProjects/Synchronization/cmake-build-debug /home/aya/CLionProjects/Synchronization/cmake-build-debug/CMakeFiles/Synchronization.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Synchronization.dir/depend
