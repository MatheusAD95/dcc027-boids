# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.8

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/m/2017_1/cg/dcc027-boids

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/m/2017_1/cg/dcc027-boids/build

# Include any dependencies generated for this target.
include CMakeFiles/boids.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/boids.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/boids.dir/flags.make

CMakeFiles/boids.dir/src/main.cc.o: CMakeFiles/boids.dir/flags.make
CMakeFiles/boids.dir/src/main.cc.o: ../src/main.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/m/2017_1/cg/dcc027-boids/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/boids.dir/src/main.cc.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/boids.dir/src/main.cc.o -c /home/m/2017_1/cg/dcc027-boids/src/main.cc

CMakeFiles/boids.dir/src/main.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/boids.dir/src/main.cc.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/m/2017_1/cg/dcc027-boids/src/main.cc > CMakeFiles/boids.dir/src/main.cc.i

CMakeFiles/boids.dir/src/main.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/boids.dir/src/main.cc.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/m/2017_1/cg/dcc027-boids/src/main.cc -o CMakeFiles/boids.dir/src/main.cc.s

CMakeFiles/boids.dir/src/main.cc.o.requires:

.PHONY : CMakeFiles/boids.dir/src/main.cc.o.requires

CMakeFiles/boids.dir/src/main.cc.o.provides: CMakeFiles/boids.dir/src/main.cc.o.requires
	$(MAKE) -f CMakeFiles/boids.dir/build.make CMakeFiles/boids.dir/src/main.cc.o.provides.build
.PHONY : CMakeFiles/boids.dir/src/main.cc.o.provides

CMakeFiles/boids.dir/src/main.cc.o.provides.build: CMakeFiles/boids.dir/src/main.cc.o


CMakeFiles/boids.dir/src/shader.cc.o: CMakeFiles/boids.dir/flags.make
CMakeFiles/boids.dir/src/shader.cc.o: ../src/shader.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/m/2017_1/cg/dcc027-boids/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/boids.dir/src/shader.cc.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/boids.dir/src/shader.cc.o -c /home/m/2017_1/cg/dcc027-boids/src/shader.cc

CMakeFiles/boids.dir/src/shader.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/boids.dir/src/shader.cc.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/m/2017_1/cg/dcc027-boids/src/shader.cc > CMakeFiles/boids.dir/src/shader.cc.i

CMakeFiles/boids.dir/src/shader.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/boids.dir/src/shader.cc.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/m/2017_1/cg/dcc027-boids/src/shader.cc -o CMakeFiles/boids.dir/src/shader.cc.s

CMakeFiles/boids.dir/src/shader.cc.o.requires:

.PHONY : CMakeFiles/boids.dir/src/shader.cc.o.requires

CMakeFiles/boids.dir/src/shader.cc.o.provides: CMakeFiles/boids.dir/src/shader.cc.o.requires
	$(MAKE) -f CMakeFiles/boids.dir/build.make CMakeFiles/boids.dir/src/shader.cc.o.provides.build
.PHONY : CMakeFiles/boids.dir/src/shader.cc.o.provides

CMakeFiles/boids.dir/src/shader.cc.o.provides.build: CMakeFiles/boids.dir/src/shader.cc.o


CMakeFiles/boids.dir/src/game.cc.o: CMakeFiles/boids.dir/flags.make
CMakeFiles/boids.dir/src/game.cc.o: ../src/game.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/m/2017_1/cg/dcc027-boids/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/boids.dir/src/game.cc.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/boids.dir/src/game.cc.o -c /home/m/2017_1/cg/dcc027-boids/src/game.cc

CMakeFiles/boids.dir/src/game.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/boids.dir/src/game.cc.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/m/2017_1/cg/dcc027-boids/src/game.cc > CMakeFiles/boids.dir/src/game.cc.i

CMakeFiles/boids.dir/src/game.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/boids.dir/src/game.cc.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/m/2017_1/cg/dcc027-boids/src/game.cc -o CMakeFiles/boids.dir/src/game.cc.s

CMakeFiles/boids.dir/src/game.cc.o.requires:

.PHONY : CMakeFiles/boids.dir/src/game.cc.o.requires

CMakeFiles/boids.dir/src/game.cc.o.provides: CMakeFiles/boids.dir/src/game.cc.o.requires
	$(MAKE) -f CMakeFiles/boids.dir/build.make CMakeFiles/boids.dir/src/game.cc.o.provides.build
.PHONY : CMakeFiles/boids.dir/src/game.cc.o.provides

CMakeFiles/boids.dir/src/game.cc.o.provides.build: CMakeFiles/boids.dir/src/game.cc.o


CMakeFiles/boids.dir/src/camera.cc.o: CMakeFiles/boids.dir/flags.make
CMakeFiles/boids.dir/src/camera.cc.o: ../src/camera.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/m/2017_1/cg/dcc027-boids/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/boids.dir/src/camera.cc.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/boids.dir/src/camera.cc.o -c /home/m/2017_1/cg/dcc027-boids/src/camera.cc

CMakeFiles/boids.dir/src/camera.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/boids.dir/src/camera.cc.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/m/2017_1/cg/dcc027-boids/src/camera.cc > CMakeFiles/boids.dir/src/camera.cc.i

CMakeFiles/boids.dir/src/camera.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/boids.dir/src/camera.cc.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/m/2017_1/cg/dcc027-boids/src/camera.cc -o CMakeFiles/boids.dir/src/camera.cc.s

CMakeFiles/boids.dir/src/camera.cc.o.requires:

.PHONY : CMakeFiles/boids.dir/src/camera.cc.o.requires

CMakeFiles/boids.dir/src/camera.cc.o.provides: CMakeFiles/boids.dir/src/camera.cc.o.requires
	$(MAKE) -f CMakeFiles/boids.dir/build.make CMakeFiles/boids.dir/src/camera.cc.o.provides.build
.PHONY : CMakeFiles/boids.dir/src/camera.cc.o.provides

CMakeFiles/boids.dir/src/camera.cc.o.provides.build: CMakeFiles/boids.dir/src/camera.cc.o


CMakeFiles/boids.dir/src/object.cc.o: CMakeFiles/boids.dir/flags.make
CMakeFiles/boids.dir/src/object.cc.o: ../src/object.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/m/2017_1/cg/dcc027-boids/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/boids.dir/src/object.cc.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/boids.dir/src/object.cc.o -c /home/m/2017_1/cg/dcc027-boids/src/object.cc

CMakeFiles/boids.dir/src/object.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/boids.dir/src/object.cc.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/m/2017_1/cg/dcc027-boids/src/object.cc > CMakeFiles/boids.dir/src/object.cc.i

CMakeFiles/boids.dir/src/object.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/boids.dir/src/object.cc.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/m/2017_1/cg/dcc027-boids/src/object.cc -o CMakeFiles/boids.dir/src/object.cc.s

CMakeFiles/boids.dir/src/object.cc.o.requires:

.PHONY : CMakeFiles/boids.dir/src/object.cc.o.requires

CMakeFiles/boids.dir/src/object.cc.o.provides: CMakeFiles/boids.dir/src/object.cc.o.requires
	$(MAKE) -f CMakeFiles/boids.dir/build.make CMakeFiles/boids.dir/src/object.cc.o.provides.build
.PHONY : CMakeFiles/boids.dir/src/object.cc.o.provides

CMakeFiles/boids.dir/src/object.cc.o.provides.build: CMakeFiles/boids.dir/src/object.cc.o


CMakeFiles/boids.dir/src/boid.cc.o: CMakeFiles/boids.dir/flags.make
CMakeFiles/boids.dir/src/boid.cc.o: ../src/boid.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/m/2017_1/cg/dcc027-boids/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/boids.dir/src/boid.cc.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/boids.dir/src/boid.cc.o -c /home/m/2017_1/cg/dcc027-boids/src/boid.cc

CMakeFiles/boids.dir/src/boid.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/boids.dir/src/boid.cc.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/m/2017_1/cg/dcc027-boids/src/boid.cc > CMakeFiles/boids.dir/src/boid.cc.i

CMakeFiles/boids.dir/src/boid.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/boids.dir/src/boid.cc.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/m/2017_1/cg/dcc027-boids/src/boid.cc -o CMakeFiles/boids.dir/src/boid.cc.s

CMakeFiles/boids.dir/src/boid.cc.o.requires:

.PHONY : CMakeFiles/boids.dir/src/boid.cc.o.requires

CMakeFiles/boids.dir/src/boid.cc.o.provides: CMakeFiles/boids.dir/src/boid.cc.o.requires
	$(MAKE) -f CMakeFiles/boids.dir/build.make CMakeFiles/boids.dir/src/boid.cc.o.provides.build
.PHONY : CMakeFiles/boids.dir/src/boid.cc.o.provides

CMakeFiles/boids.dir/src/boid.cc.o.provides.build: CMakeFiles/boids.dir/src/boid.cc.o


CMakeFiles/boids.dir/src/terrain.cc.o: CMakeFiles/boids.dir/flags.make
CMakeFiles/boids.dir/src/terrain.cc.o: ../src/terrain.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/m/2017_1/cg/dcc027-boids/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/boids.dir/src/terrain.cc.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/boids.dir/src/terrain.cc.o -c /home/m/2017_1/cg/dcc027-boids/src/terrain.cc

CMakeFiles/boids.dir/src/terrain.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/boids.dir/src/terrain.cc.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/m/2017_1/cg/dcc027-boids/src/terrain.cc > CMakeFiles/boids.dir/src/terrain.cc.i

CMakeFiles/boids.dir/src/terrain.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/boids.dir/src/terrain.cc.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/m/2017_1/cg/dcc027-boids/src/terrain.cc -o CMakeFiles/boids.dir/src/terrain.cc.s

CMakeFiles/boids.dir/src/terrain.cc.o.requires:

.PHONY : CMakeFiles/boids.dir/src/terrain.cc.o.requires

CMakeFiles/boids.dir/src/terrain.cc.o.provides: CMakeFiles/boids.dir/src/terrain.cc.o.requires
	$(MAKE) -f CMakeFiles/boids.dir/build.make CMakeFiles/boids.dir/src/terrain.cc.o.provides.build
.PHONY : CMakeFiles/boids.dir/src/terrain.cc.o.provides

CMakeFiles/boids.dir/src/terrain.cc.o.provides.build: CMakeFiles/boids.dir/src/terrain.cc.o


CMakeFiles/boids.dir/src/cone.cc.o: CMakeFiles/boids.dir/flags.make
CMakeFiles/boids.dir/src/cone.cc.o: ../src/cone.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/m/2017_1/cg/dcc027-boids/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/boids.dir/src/cone.cc.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/boids.dir/src/cone.cc.o -c /home/m/2017_1/cg/dcc027-boids/src/cone.cc

CMakeFiles/boids.dir/src/cone.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/boids.dir/src/cone.cc.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/m/2017_1/cg/dcc027-boids/src/cone.cc > CMakeFiles/boids.dir/src/cone.cc.i

CMakeFiles/boids.dir/src/cone.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/boids.dir/src/cone.cc.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/m/2017_1/cg/dcc027-boids/src/cone.cc -o CMakeFiles/boids.dir/src/cone.cc.s

CMakeFiles/boids.dir/src/cone.cc.o.requires:

.PHONY : CMakeFiles/boids.dir/src/cone.cc.o.requires

CMakeFiles/boids.dir/src/cone.cc.o.provides: CMakeFiles/boids.dir/src/cone.cc.o.requires
	$(MAKE) -f CMakeFiles/boids.dir/build.make CMakeFiles/boids.dir/src/cone.cc.o.provides.build
.PHONY : CMakeFiles/boids.dir/src/cone.cc.o.provides

CMakeFiles/boids.dir/src/cone.cc.o.provides.build: CMakeFiles/boids.dir/src/cone.cc.o


CMakeFiles/boids.dir/src/texture.cpp.o: CMakeFiles/boids.dir/flags.make
CMakeFiles/boids.dir/src/texture.cpp.o: ../src/texture.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/m/2017_1/cg/dcc027-boids/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/boids.dir/src/texture.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/boids.dir/src/texture.cpp.o -c /home/m/2017_1/cg/dcc027-boids/src/texture.cpp

CMakeFiles/boids.dir/src/texture.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/boids.dir/src/texture.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/m/2017_1/cg/dcc027-boids/src/texture.cpp > CMakeFiles/boids.dir/src/texture.cpp.i

CMakeFiles/boids.dir/src/texture.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/boids.dir/src/texture.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/m/2017_1/cg/dcc027-boids/src/texture.cpp -o CMakeFiles/boids.dir/src/texture.cpp.s

CMakeFiles/boids.dir/src/texture.cpp.o.requires:

.PHONY : CMakeFiles/boids.dir/src/texture.cpp.o.requires

CMakeFiles/boids.dir/src/texture.cpp.o.provides: CMakeFiles/boids.dir/src/texture.cpp.o.requires
	$(MAKE) -f CMakeFiles/boids.dir/build.make CMakeFiles/boids.dir/src/texture.cpp.o.provides.build
.PHONY : CMakeFiles/boids.dir/src/texture.cpp.o.provides

CMakeFiles/boids.dir/src/texture.cpp.o.provides.build: CMakeFiles/boids.dir/src/texture.cpp.o


CMakeFiles/boids.dir/src/object_texture.cc.o: CMakeFiles/boids.dir/flags.make
CMakeFiles/boids.dir/src/object_texture.cc.o: ../src/object_texture.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/m/2017_1/cg/dcc027-boids/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/boids.dir/src/object_texture.cc.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/boids.dir/src/object_texture.cc.o -c /home/m/2017_1/cg/dcc027-boids/src/object_texture.cc

CMakeFiles/boids.dir/src/object_texture.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/boids.dir/src/object_texture.cc.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/m/2017_1/cg/dcc027-boids/src/object_texture.cc > CMakeFiles/boids.dir/src/object_texture.cc.i

CMakeFiles/boids.dir/src/object_texture.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/boids.dir/src/object_texture.cc.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/m/2017_1/cg/dcc027-boids/src/object_texture.cc -o CMakeFiles/boids.dir/src/object_texture.cc.s

CMakeFiles/boids.dir/src/object_texture.cc.o.requires:

.PHONY : CMakeFiles/boids.dir/src/object_texture.cc.o.requires

CMakeFiles/boids.dir/src/object_texture.cc.o.provides: CMakeFiles/boids.dir/src/object_texture.cc.o.requires
	$(MAKE) -f CMakeFiles/boids.dir/build.make CMakeFiles/boids.dir/src/object_texture.cc.o.provides.build
.PHONY : CMakeFiles/boids.dir/src/object_texture.cc.o.provides

CMakeFiles/boids.dir/src/object_texture.cc.o.provides.build: CMakeFiles/boids.dir/src/object_texture.cc.o


CMakeFiles/boids.dir/src/obj_model.cc.o: CMakeFiles/boids.dir/flags.make
CMakeFiles/boids.dir/src/obj_model.cc.o: ../src/obj_model.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/m/2017_1/cg/dcc027-boids/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/boids.dir/src/obj_model.cc.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/boids.dir/src/obj_model.cc.o -c /home/m/2017_1/cg/dcc027-boids/src/obj_model.cc

CMakeFiles/boids.dir/src/obj_model.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/boids.dir/src/obj_model.cc.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/m/2017_1/cg/dcc027-boids/src/obj_model.cc > CMakeFiles/boids.dir/src/obj_model.cc.i

CMakeFiles/boids.dir/src/obj_model.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/boids.dir/src/obj_model.cc.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/m/2017_1/cg/dcc027-boids/src/obj_model.cc -o CMakeFiles/boids.dir/src/obj_model.cc.s

CMakeFiles/boids.dir/src/obj_model.cc.o.requires:

.PHONY : CMakeFiles/boids.dir/src/obj_model.cc.o.requires

CMakeFiles/boids.dir/src/obj_model.cc.o.provides: CMakeFiles/boids.dir/src/obj_model.cc.o.requires
	$(MAKE) -f CMakeFiles/boids.dir/build.make CMakeFiles/boids.dir/src/obj_model.cc.o.provides.build
.PHONY : CMakeFiles/boids.dir/src/obj_model.cc.o.provides

CMakeFiles/boids.dir/src/obj_model.cc.o.provides.build: CMakeFiles/boids.dir/src/obj_model.cc.o


# Object files for target boids
boids_OBJECTS = \
"CMakeFiles/boids.dir/src/main.cc.o" \
"CMakeFiles/boids.dir/src/shader.cc.o" \
"CMakeFiles/boids.dir/src/game.cc.o" \
"CMakeFiles/boids.dir/src/camera.cc.o" \
"CMakeFiles/boids.dir/src/object.cc.o" \
"CMakeFiles/boids.dir/src/boid.cc.o" \
"CMakeFiles/boids.dir/src/terrain.cc.o" \
"CMakeFiles/boids.dir/src/cone.cc.o" \
"CMakeFiles/boids.dir/src/texture.cpp.o" \
"CMakeFiles/boids.dir/src/object_texture.cc.o" \
"CMakeFiles/boids.dir/src/obj_model.cc.o"

# External object files for target boids
boids_EXTERNAL_OBJECTS =

boids: CMakeFiles/boids.dir/src/main.cc.o
boids: CMakeFiles/boids.dir/src/shader.cc.o
boids: CMakeFiles/boids.dir/src/game.cc.o
boids: CMakeFiles/boids.dir/src/camera.cc.o
boids: CMakeFiles/boids.dir/src/object.cc.o
boids: CMakeFiles/boids.dir/src/boid.cc.o
boids: CMakeFiles/boids.dir/src/terrain.cc.o
boids: CMakeFiles/boids.dir/src/cone.cc.o
boids: CMakeFiles/boids.dir/src/texture.cpp.o
boids: CMakeFiles/boids.dir/src/object_texture.cc.o
boids: CMakeFiles/boids.dir/src/obj_model.cc.o
boids: CMakeFiles/boids.dir/build.make
boids: /usr/lib/x86_64-linux-gnu/libGLU.so
boids: /usr/lib/x86_64-linux-gnu/libGL.so
boids: external/glfw-3.1.2/src/libglfw3.a
boids: external/libGLEW_1130.a
boids: external/libSOIL.a
boids: external/SFML-2.4.2/lib/libsfml-audio.a
boids: external/freetype-2.7/libfreetype.a
boids: /usr/lib/x86_64-linux-gnu/libGLU.so
boids: /usr/lib/x86_64-linux-gnu/librt.so
boids: /usr/lib/x86_64-linux-gnu/libm.so
boids: /usr/lib/x86_64-linux-gnu/libX11.so
boids: /usr/lib/x86_64-linux-gnu/libXrandr.so
boids: /usr/lib/x86_64-linux-gnu/libXinerama.so
boids: /usr/lib/x86_64-linux-gnu/libXi.so
boids: /usr/lib/x86_64-linux-gnu/libXxf86vm.so
boids: /usr/lib/x86_64-linux-gnu/libXcursor.so
boids: /usr/lib/x86_64-linux-gnu/librt.so
boids: /usr/lib/x86_64-linux-gnu/libm.so
boids: /usr/lib/x86_64-linux-gnu/libX11.so
boids: /usr/lib/x86_64-linux-gnu/libXrandr.so
boids: /usr/lib/x86_64-linux-gnu/libXinerama.so
boids: /usr/lib/x86_64-linux-gnu/libXi.so
boids: /usr/lib/x86_64-linux-gnu/libXxf86vm.so
boids: /usr/lib/x86_64-linux-gnu/libXcursor.so
boids: /usr/lib/x86_64-linux-gnu/libGL.so
boids: external/SFML-2.4.2/lib/libsfml-system.a
boids: /usr/lib/x86_64-linux-gnu/libopenal.so
boids: /usr/lib/x86_64-linux-gnu/libvorbisenc.so
boids: /usr/lib/x86_64-linux-gnu/libvorbisfile.so
boids: /usr/lib/x86_64-linux-gnu/libvorbis.so
boids: /usr/lib/x86_64-linux-gnu/libogg.so
boids: /usr/lib/x86_64-linux-gnu/libFLAC.so
boids: /usr/lib/x86_64-linux-gnu/libz.so
boids: /usr/lib/x86_64-linux-gnu/libbz2.so
boids: /usr/lib/x86_64-linux-gnu/libpng.so
boids: /usr/lib/x86_64-linux-gnu/libz.so
boids: /usr/lib/x86_64-linux-gnu/libbz2.so
boids: /usr/lib/x86_64-linux-gnu/libpng.so
boids: CMakeFiles/boids.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/m/2017_1/cg/dcc027-boids/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Linking CXX executable boids"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/boids.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/boids.dir/build: boids

.PHONY : CMakeFiles/boids.dir/build

CMakeFiles/boids.dir/requires: CMakeFiles/boids.dir/src/main.cc.o.requires
CMakeFiles/boids.dir/requires: CMakeFiles/boids.dir/src/shader.cc.o.requires
CMakeFiles/boids.dir/requires: CMakeFiles/boids.dir/src/game.cc.o.requires
CMakeFiles/boids.dir/requires: CMakeFiles/boids.dir/src/camera.cc.o.requires
CMakeFiles/boids.dir/requires: CMakeFiles/boids.dir/src/object.cc.o.requires
CMakeFiles/boids.dir/requires: CMakeFiles/boids.dir/src/boid.cc.o.requires
CMakeFiles/boids.dir/requires: CMakeFiles/boids.dir/src/terrain.cc.o.requires
CMakeFiles/boids.dir/requires: CMakeFiles/boids.dir/src/cone.cc.o.requires
CMakeFiles/boids.dir/requires: CMakeFiles/boids.dir/src/texture.cpp.o.requires
CMakeFiles/boids.dir/requires: CMakeFiles/boids.dir/src/object_texture.cc.o.requires
CMakeFiles/boids.dir/requires: CMakeFiles/boids.dir/src/obj_model.cc.o.requires

.PHONY : CMakeFiles/boids.dir/requires

CMakeFiles/boids.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/boids.dir/cmake_clean.cmake
.PHONY : CMakeFiles/boids.dir/clean

CMakeFiles/boids.dir/depend:
	cd /home/m/2017_1/cg/dcc027-boids/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/m/2017_1/cg/dcc027-boids /home/m/2017_1/cg/dcc027-boids /home/m/2017_1/cg/dcc027-boids/build /home/m/2017_1/cg/dcc027-boids/build /home/m/2017_1/cg/dcc027-boids/build/CMakeFiles/boids.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/boids.dir/depend
