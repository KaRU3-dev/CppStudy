# Init
1. https://github.com/niXman/mingw-builds-binaries/releases -> `x86_64-v13.1.0-release-win32-seh-ucrt-rt_v13-rev0.7z`をダウンロードして解凍する
2. 中の`mingw/bin`フォルダを環境変数に登録
3. https://dxlib.xsrv.jp/dxdload.html -> `ＤＸライブラリ Windows版 Gnu C++( MinGW )用(Ver3.24f)`をダウンロードして解凍する
4. 中の`DxLib_GCC/プロジェクトに追加すべきファイル_GCC(MinGW)用/12_2_0_x86_64_release_win32_seh_ucrt_rt_v10_rev2`をプロジェクトにコピーする
5. プロジェクトの`CMakePresets.json`を編集する
    ```json
    {
        ...
        "configurePresets": [
            {
                ...
                "cacheVariables": {
                    "CMAKE_C_COMPILER": "C:/Path/to/mingw64-v13.1.0/bin/gcc.exe",
                    "CMAKE_CXX_COMPILER": "C:/Path/to/mingw64-v13.1.0/bin/g++.exe",
                    ...
                }
            } ...
        ]
    }
    ```
6. プロジェクトの`CMakeLists.txt`を編集する
    ```cmake
    ...

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
    ```
