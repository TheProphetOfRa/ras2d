cmake_minimum_required(VERSION 3.15)

project(ras2d VERSION 0.1)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_BUILD_TYPE Release)

add_subdirectory(lib/glew/build/cmake)
add_subdirectory(lib/glfw)

include_directories(lib/glew/include)
include_directories(lib/glfw/include)

include_directories(src)

set(SOURCES src/Application/RasApplication.cpp
    src/Controller/Director.cpp
    src/Controller/InputManager.cpp
    src/Controller/RenderManager.cpp
    src/Math/BaseMath.cpp
    src/Util/Log.cpp
    src/View/Node.cpp
    src/View/Scene.cpp)

if (APPLE)
    list(APPEND SOURCES src/Platform/OSX/Util/FileUtils.cpp)
elseif(WIN32)
    list(APPEND SOURCES src/Platform/Win32/Util/FileUtils.cpp)
endif()

add_library(ras2d STATIC ${SOURCES})
