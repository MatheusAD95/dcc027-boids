# CMake entry point
cmake_minimum_required (VERSION 2.6)
project (Tutorials)

find_package(OpenGL REQUIRED)


if( CMAKE_BINARY_DIR STREQUAL CMAKE_SOURCE_DIR )
  message( FATAL_ERROR "Please select another Build Directory ! (and give it a clever name, like bin_Visual2012_64bits/)" )
endif()
if( CMAKE_SOURCE_DIR MATCHES " " )
  message( "Your Source Directory contains spaces. If you experience problems when compiling, this can be the cause." )
endif()
if( CMAKE_BINARY_DIR MATCHES " " )
  message( "Your Build Directory contains spaces. If you experience problems when compiling, this can be the cause." )
endif()



# Compile external dependencies 
add_subdirectory (external)

# On Visual 2005 and above, this module can set the debug working directory
cmake_policy(SET CMP0026 OLD)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/external/rpavlik-cmake-modules-fe2273")

if(INCLUDE_DISTRIB)
  add_subdirectory(distrib)
endif(INCLUDE_DISTRIB)



include_directories(
  external/soil/src/
  external/glfw-3.1.2/include/GLFW/
  external/glm-0.9.7.1/
  external/glew-1.13.0/include/
  external/SFML-2.4.2/include/
  external/freetype-2.7/include/
  .
  )

set(ALL_LIBS
  ${OPENGL_LIBRARY}
  glfw
  GLEW_1130
  SOIL
  sfml-audio
  freetype

  )

add_definitions(
  -DTW_STATIC
  -DTW_NO_LIB_PRAGMA
  -DTW_NO_DIRECT3D
  -DGLEW_STATIC
  -D_CRT_SECURE_NO_WARNINGS
  )

add_executable(boids
  src/main.cc
  src/shader.cc
  src/game.cc
  src/camera.cc
  src/object.cc
  src/boid.cc
  src/terrain.cc
  src/cone.cc
  src/texture.cpp
  src/object_texture.cc
  src/obj_model.cc
  )
target_link_libraries(boids
  ${ALL_LIBS}
  )
