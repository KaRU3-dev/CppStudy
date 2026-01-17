cmake_minimum_required(VERSION 3.20)

project(DxlibStudy
    VERSION 0.1.0
    LANGUAGES C CXX
)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE SRC_FILES CONFIGURE_DEPENDS src/*.cpp)

add_executable(DxlibStudy WIN32 ${SRC_FILES})

# DxLib include
target_include_directories(DxlibStudy PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/.libs/dxlib
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
        DxDrawFunc
        DxUseCLib

        png
        jpeg
        zlib
        tiff

        theora_static
        vorbisfile_static
        vorbis_static
        ogg_static

        opusfile
        opus
        celt

        bulletdynamics
        bulletcollision
        bulletmath

        gdi32
        user32
        winmm
        imm32
        ole32
        oleaut32
        version
        uuid
        shell32
        kernel32
        comdlg32
        advapi32

        mingwex
        msvcrt
    )
endif()
