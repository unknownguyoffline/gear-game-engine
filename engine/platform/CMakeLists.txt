cmake_minimum_required(VERSION 3.20.0)

project(Platform)

file(GLOB source
	"${PROJECT_SOURCE_DIR}/linux/*.cpp"

)

add_library(platform STATIC ${source})
