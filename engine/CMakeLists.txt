cmake_minimum_required(VERSION 3.20.0)

project(engine)

include_directories("${PROJECT_SOURCE_DIR}/vendor")

file(GLOB source
	"${PROJECT_SOURCE_DIR}/core/*.cpp"
	"${PROJECT_SOURCE_DIR}/utility/*.cpp"
	"${PROJECT_SOURCE_DIR}/renderer/*.cpp"
	"${PROJECT_SOURCE_DIR}/input/*.cpp"
	"${PROJECT_SOURCE_DIR}/assets/*.cpp"
	"${PROJECT_SOURCE_DIR}/ecs/*.cpp"
	"${PROJECT_SOURCE_DIR}/vendor/stb/*.cpp"
)

add_subdirectory(platform)
add_subdirectory(vendor)

add_library(engine STATIC ${source})
target_link_libraries(engine platform)
target_link_libraries(engine glad)
target_link_libraries(engine assimp)
target_link_libraries(engine EnTT)
