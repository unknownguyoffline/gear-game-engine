cmake_minimum_required(VERSION 3.20.0)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_BUILD_TYPE Debug)
project(Engine)
include_directories(${PROJECT_SOURCE_DIR}/engine/)
add_subdirectory(engine)
add_subdirectory(project)

