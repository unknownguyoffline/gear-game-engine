cmake_minimum_required(VERSION 3.20.0)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_STANDARD 17)
project(Engine)
include_directories(${PROJECT_SOURCE_DIR}/engine/)
include_directories(${PROJECT_SOURCE_DIR}/engine/vendor/entt/single_include)
include_directories(${PROJECT_SOURCE_DIR}/engine/vendor/glm)
include_directories(${PROJECT_SOURCE_DIR}/engine/vendor/glad/include/)

add_subdirectory(engine)
add_subdirectory(project)

