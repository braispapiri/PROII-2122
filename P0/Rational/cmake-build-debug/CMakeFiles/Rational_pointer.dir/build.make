# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.19

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.2.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.2.3\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\brais\OneDrive - Universidade da Coruña\UNIVERSIDAD\PRO2\Prácticas\P0\Rational"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\brais\OneDrive - Universidade da Coruña\UNIVERSIDAD\PRO2\Prácticas\P0\Rational\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Rational_pointer.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Rational_pointer.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Rational_pointer.dir/flags.make

CMakeFiles/Rational_pointer.dir/main.c.obj: CMakeFiles/Rational_pointer.dir/flags.make
CMakeFiles/Rational_pointer.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\brais\OneDrive - Universidade da Coruña\UNIVERSIDAD\PRO2\Prácticas\P0\Rational\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Rational_pointer.dir/main.c.obj"
	C:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\Rational_pointer.dir\main.c.obj -c "C:\Users\brais\OneDrive - Universidade da Coruña\UNIVERSIDAD\PRO2\Prácticas\P0\Rational\main.c"

CMakeFiles/Rational_pointer.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Rational_pointer.dir/main.c.i"
	C:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\brais\OneDrive - Universidade da Coruña\UNIVERSIDAD\PRO2\Prácticas\P0\Rational\main.c" > CMakeFiles\Rational_pointer.dir\main.c.i

CMakeFiles/Rational_pointer.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Rational_pointer.dir/main.c.s"
	C:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Users\brais\OneDrive - Universidade da Coruña\UNIVERSIDAD\PRO2\Prácticas\P0\Rational\main.c" -o CMakeFiles\Rational_pointer.dir\main.c.s

# Object files for target Rational_pointer
Rational_pointer_OBJECTS = \
"CMakeFiles/Rational_pointer.dir/main.c.obj"

# External object files for target Rational_pointer
Rational_pointer_EXTERNAL_OBJECTS =

Rational_pointer.exe: CMakeFiles/Rational_pointer.dir/main.c.obj
Rational_pointer.exe: CMakeFiles/Rational_pointer.dir/build.make
Rational_pointer.exe: CMakeFiles/Rational_pointer.dir/linklibs.rsp
Rational_pointer.exe: CMakeFiles/Rational_pointer.dir/objects1.rsp
Rational_pointer.exe: CMakeFiles/Rational_pointer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\brais\OneDrive - Universidade da Coruña\UNIVERSIDAD\PRO2\Prácticas\P0\Rational\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable Rational_pointer.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Rational_pointer.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Rational_pointer.dir/build: Rational_pointer.exe

.PHONY : CMakeFiles/Rational_pointer.dir/build

CMakeFiles/Rational_pointer.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Rational_pointer.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Rational_pointer.dir/clean

CMakeFiles/Rational_pointer.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\brais\OneDrive - Universidade da Coruña\UNIVERSIDAD\PRO2\Prácticas\P0\Rational" "C:\Users\brais\OneDrive - Universidade da Coruña\UNIVERSIDAD\PRO2\Prácticas\P0\Rational" "C:\Users\brais\OneDrive - Universidade da Coruña\UNIVERSIDAD\PRO2\Prácticas\P0\Rational\cmake-build-debug" "C:\Users\brais\OneDrive - Universidade da Coruña\UNIVERSIDAD\PRO2\Prácticas\P0\Rational\cmake-build-debug" "C:\Users\brais\OneDrive - Universidade da Coruña\UNIVERSIDAD\PRO2\Prácticas\P0\Rational\cmake-build-debug\CMakeFiles\Rational_pointer.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Rational_pointer.dir/depend

