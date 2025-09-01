cmake_minimum_required(VERSION 3.20.0)

include_directories("{PROJECT_SOURCE_DIR}/include")

project(glad)

add_library(glad STATIC "src/glad.c")