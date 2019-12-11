cmake_minimum_required(VERSION 3.15)

project(ras2d VERSION 0.1)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_BUILD_TYPE Release)

add_subdirectory(lib/glew/build/cmake)
add_subdirectory(lib/glfw)

include_directories(lib/glew/include)
include_directories(lib/glfw/include)

include_directories(src)

file(GLOB_RECURSE SOURCES "src" "*.cpp" "*.h")

add_library(ras2d STATIC ${SOURCES})
