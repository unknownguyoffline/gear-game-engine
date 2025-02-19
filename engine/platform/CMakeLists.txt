cmake_minimum_required(VERSION 3.20.0)

project(Platform)
include_directories(${PROJECT_SOURCE_DIR}/../core/)

if (WIN32)
file(GLOB source
	"${PROJECT_SOURCE_DIR}/windows/*.cpp"
	"${PROJECT_SOURCE_DIR}/opengl/*.cpp"

)
endif (WIN32)
if (UNIX)
file(GLOB source
	"${PROJECT_SOURCE_DIR}/linux/*.cpp"
	"${PROJECT_SOURCE_DIR}/opengl/*.cpp"

)
endif (UNIX)

add_library(platform STATIC ${source})
target_link_libraries(platform glfw)

