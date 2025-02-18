cmake_minimum_required(VERSION 3.20.0)

project(engine)

file(GLOB source
	"${PROJECT_SOURCE_DIR}/core/*.cpp"
	"${PROJECT_SOURCE_DIR}/utility/*.cpp"
)

add_subdirectory(platform)
add_subdirectory(vendor)

add_library(engine STATIC ${source})
target_link_libraries(engine platform)
