cmake_minimum_required(VERSION 3.10.0)
project(DataLoad VERSION 0.1.0 LANGUAGES C CXX)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(DataLoad src/main.cpp)

find_package(RapidJSON CONFIG REQUIRED)
find_package(tinyxml2 CONFIG REQUIRED)

if (MINGW)
    message("MinGW detected")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libgcc -static-libstdc++")
endif()

# Copy ./data folder
add_custom_command(
    TARGET DataLoad
    POST_BUILD
    COMMAND
        ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/data
        $<TARGET_FILE_DIR:DataLoad>/data
)

target_include_directories(DataLoad PRIVATE ${CMAKE_SOURCE_DIR}/src/includes)

target_link_libraries(DataLoad PRIVATE tinyxml2::tinyxml2 rapidjson)
