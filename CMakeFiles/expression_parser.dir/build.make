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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/amaldev/cpp_projects/Expression-parser

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/amaldev/cpp_projects/Expression-parser

# Include any dependencies generated for this target.
include CMakeFiles/expression_parser.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/expression_parser.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/expression_parser.dir/flags.make

CMakeFiles/expression_parser.dir/src/expression_parser.cpp.o: CMakeFiles/expression_parser.dir/flags.make
CMakeFiles/expression_parser.dir/src/expression_parser.cpp.o: src/expression_parser.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/amaldev/cpp_projects/Expression-parser/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/expression_parser.dir/src/expression_parser.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/expression_parser.dir/src/expression_parser.cpp.o -c /home/amaldev/cpp_projects/Expression-parser/src/expression_parser.cpp

CMakeFiles/expression_parser.dir/src/expression_parser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/expression_parser.dir/src/expression_parser.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/amaldev/cpp_projects/Expression-parser/src/expression_parser.cpp > CMakeFiles/expression_parser.dir/src/expression_parser.cpp.i

CMakeFiles/expression_parser.dir/src/expression_parser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/expression_parser.dir/src/expression_parser.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/amaldev/cpp_projects/Expression-parser/src/expression_parser.cpp -o CMakeFiles/expression_parser.dir/src/expression_parser.cpp.s

# Object files for target expression_parser
expression_parser_OBJECTS = \
"CMakeFiles/expression_parser.dir/src/expression_parser.cpp.o"

# External object files for target expression_parser
expression_parser_EXTERNAL_OBJECTS =

libexpression_parser.so: CMakeFiles/expression_parser.dir/src/expression_parser.cpp.o
libexpression_parser.so: CMakeFiles/expression_parser.dir/build.make
libexpression_parser.so: CMakeFiles/expression_parser.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/amaldev/cpp_projects/Expression-parser/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library libexpression_parser.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/expression_parser.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/expression_parser.dir/build: libexpression_parser.so

.PHONY : CMakeFiles/expression_parser.dir/build

CMakeFiles/expression_parser.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/expression_parser.dir/cmake_clean.cmake
.PHONY : CMakeFiles/expression_parser.dir/clean

CMakeFiles/expression_parser.dir/depend:
	cd /home/amaldev/cpp_projects/Expression-parser && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/amaldev/cpp_projects/Expression-parser /home/amaldev/cpp_projects/Expression-parser /home/amaldev/cpp_projects/Expression-parser /home/amaldev/cpp_projects/Expression-parser /home/amaldev/cpp_projects/Expression-parser/CMakeFiles/expression_parser.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/expression_parser.dir/depend

