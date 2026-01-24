cmake_minimum_required(VERSION 3.20)

project(DxlibStudy
    VERSION 0.1.0
    LANGUAGES C CXX
)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE SRC_FILES CONFIGURE_DEPENDS src/*.cpp)

add_executable(DxlibStudy WIN32 ${SRC_FILES})

# Include Directories
target_include_directories(DxlibStudy PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/.libs/dxlib
    ${CMAKE_CURRENT_SOURCE_DIR}/.libs/PerlinNoise
    ${CMAKE_CURRENT_SOURCE_DIR}/src/includes
)

# DxLib library path
target_link_directories(DxlibStudy PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/.libs/dxlib
)

if (MINGW)
    message(STATUS "MinGW detected")

    # DxLib を GCC 用に切り替えるため必須
    target_compile_definitions(DxlibStudy PRIVATE DX_GCC_COMPILE)

    # MinGW static runtime
    target_link_options(DxlibStudy PRIVATE
        -static-libgcc
        -static-libstdc++
    )

    # ライブラリは依存順を厳密に
    target_link_libraries(DxlibStudy PRIVATE
        DxLib
        DxUseCLib
        DxDrawFunc
        jpeg
        png
        zlib
        tiff
        theora_static
        vorbis_static
        vorbisfile_static
        ogg_static
        bulletdynamics
        bulletcollision
        bulletmath
        opusfile
        opus
        silk_common
        celt
    )
endif()

# Copy ./assets folder
add_custom_command(
    TARGET DxlibStudy
    POST_BUILD
    COMMAND
        ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/assets
        $<TARGET_FILE_DIR:DxlibStudy>/assets
)
