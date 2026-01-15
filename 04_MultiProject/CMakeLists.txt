# プロジェクト全体の定義
cmake_minimum_required(VERSION 3.10.0)
project(MultiProject VERSION 0.1.0 LANGUAGES C CXX)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if (MINGW)
    message("MinGW detected")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libgcc -static-libstdc++")
endif()

# サブプロジェクトの追加（実行プロジェクトやライブラリプロジェクト）
add_subdirectory(MultiProject)
add_subdirectory(MultiProject.Logging)
