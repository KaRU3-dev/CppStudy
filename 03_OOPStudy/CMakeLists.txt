cmake_minimum_required(VERSION 3.10.0)
project(OOPStudy VERSION 0.1.0 LANGUAGES C CXX)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if (MINGW)
    message("MinGW detected")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libgcc -static-libstdc++")
endif()

file(GLOB_RECURSE SRC_FILES src/*.cpp)
include_directories(${CMAKE_SOURCE_DIR}/src/includes)


add_executable(OOPStudy src/main.cpp ${SRC_FILES})
