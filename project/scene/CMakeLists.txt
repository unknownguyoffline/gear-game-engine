cmake_minimum_required(VERSION 3.20.0)

project(scene)

include_directories(${PROJECT_SOURCE_DIR}/imgui)

file(GLOB source
	"${PROJECT_SOURCE_DIR}/scene.cpp"
	"${PROJECT_SOURCE_DIR}/imgui/*.cpp"
    "${PROJECT_SOURCE_DIR}/imgui/backends/imgui_impl_glfw.cpp"
    "${PROJECT_SOURCE_DIR}/imgui/backends/imgui_impl_opengl3.cpp"
)

add_executable(scene ${source})
target_link_libraries(scene engine)
