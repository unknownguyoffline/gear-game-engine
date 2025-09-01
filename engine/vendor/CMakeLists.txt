cmake_minimum_required(VERSION 3.20.0)

add_subdirectory(glfw)
add_subdirectory(glad)
set(BUILD_SHARED_LIBS OFF)
add_subdirectory(assimp)