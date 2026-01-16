cmake_minimum_required(VERSION 3.10.0)
project(ThreadStudy VERSION 0.1.0 LANGUAGES C CXX)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if (MINGW)
    message("MinGW detected")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libgcc -static-libstdc++")
endif()

file(GLOB_RECURSE SRC_FILES src/*.cpp)
include_directories(${CMAKE_SOURCE_DIR}/src/includes)

add_executable(ThreadStudy ${SRC_FILES})


# スレッドサニタイザー向け設定の有効化
# if (CMAKE_CXX_COMPILER_ID MATCHES "Clang|GNU" AND CMAKE_BUILD_TYPE STREQUAL "Debug") # MSVCでは使えないのでコンパイラを指定し、デバッグ時のみ有効化
#     target_compile_options(ThreadStudy PRIVATE -fsanitize=thread -g -O1)
#     target_link_options(ThreadStudy PRIVATE -fsanitize=thread)
# endif()
