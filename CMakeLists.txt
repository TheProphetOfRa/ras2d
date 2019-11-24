cmake_minimum_required(VERSION 3.15)

project(ras2d VERSION 0.1)

# Require C++ 11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_BUILD_TYPE Release)

set(CMAKE_PREFIX_PATH /usr/local/Cellar/cmake/3.15.5/share/cmake/Modules)

message(CMAKE_PREFIX_PATH: ${CMAKE_PREFIX_PATH})
message(CMAKE_FRAMEWORK_PATH: ${CMAKE_FRAMEWORK_PATH})
message(CMAKE_APPBUNDLE_PATH: ${CMAKE_APPBUNDLE_PATH})

message(CMAKE_SYSTEM_PREFIX_PATH: ${CMAKE_SYSTEM_PREFIX_PATH})
message(CMAKE_SYSTEM_FRAMEWORK_PATH: ${CMAKE_SYSTEM_FRAMEWORK_PATH})
message(CMAKE_SYSTEM_APPBUNDLE_PATH: ${CMAKE_SYSTEM_APPBUNDLE_PATH})

set(CMAKE_MODULE_PATH /usr/local/Cellar/cmake/3.15.5/share/cmake/Modules/)
message(CMAKE_MODULE_PATH: ${CMAKE_MODULE_PATH})

# GLEW and GLFW includes
find_package(OPENGL REQUIRED)
#find_package(GLEW REQUIRED NO_DEFAULT_PATH)
find_package(GLEW REQUIRED)
if (NOT ${GLEW_FOUND})
    build_error("Missing: GLEW")
endif()
find_package(glfw3 REQUIRED)
if (NOT ${glfw3_FOUND})
    build_error("Missing: glfw3")
endif()

message(GLEW: ${GLEW_FOUND}. Includes: ${GLEW_INCLUDE_DIRS})
message(GLFW: ${glfw3_FOUND}. Includes: ${glfw3_INCLUDE_DIRS})

file(GLOB SOURCES "src/Application/*.cpp" "src/Controller/*.cpp" "src/Math/*.cpp" "src/Platform/*.cpp" "src/Util/*.cpp" "src/View/*.cpp")

#Create a library
add_library(ras2d SHARED ${SOURCES})

target_include_directories(ras2d PUBLIC ${GLEW_INCLUDE_DIRS} ${OPENGL_INCLUDE_DIRS} src)
target_link_libraries(ras2d PUBLIC ${GLEW_LIBRARIES} ${OPENGL_LIBRARIES} glfw3)

install(TARGETS ras2d DESTINATION ./lib)
