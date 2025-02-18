cmake_minimum_required(VERSION 3.20.0)

project(Project)

file(GLOB source
	"${PROJECT_SOURCE_DIR}/testbed/testbed.cpp"
)

add_executable(app ${source})
target_link_libraries(app engine)
target_link_libraries(app glad)
if (WIN32)
	target_link_libraries(app opengl32)
endif (WIN32)

if (WIN32)
	target_link_libraries(app GL)
endif (WIN32)
