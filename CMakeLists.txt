cmake_minimum_required(VERSION 3.10.0)
project(CppStudy VERSION 0.1.0 LANGUAGES C CXX)

if (MINGW)
    message("MinGW detected")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libgcc -static-libstdc++")
endif()

# --- OSごとのビルド設定例 ---
if (WIN32)
    message("Windows build settings")
    # Windows固有の設定があればここに記述
    # 例: ライブラリパス追加
    # link_directories(${CMAKE_SOURCE_DIR}/libs/yourlib/lib/win)
elseif(UNIX)
    message("Linux build settings")
    # Linux固有の設定があればここに記述
    # 例: ライブラリパス追加
    # link_directories(${CMAKE_SOURCE_DIR}/libs/yourlib/lib/linux)
endif()


# srcディレクトリ配下の全cppファイルを自動で追加
file(GLOB_RECURSE SRC_FILES src/*.cpp)

# src/include配下のヘッダーファイルをインクルードパスに追加
include_directories(${CMAKE_SOURCE_DIR}/src/includes)

# 取得できたファイルの表示（デバッグ用）
foreach(file ${SRC_FILES})
    message(STATUS "Found source file: ${file}")
endforeach()


# 実行ファイルの作成とライブラリのリンク
add_executable(CppStudy CppStudy.cpp ${SRC_FILES})

# --- freeglut opengl ---
set(FG_ROOT "${CMAKE_SOURCE_DIR}/libs/freeglut_opengl_mingw_build_3.0.0")
set(FG_LIB "${FG_ROOT}/lib")

target_include_directories(CppStudy PRIVATE "${FG_ROOT}/include")
target_compile_definitions(CppStudy PRIVATE GLUT_DISABLE_ATEXIT_HACK)

add_custom_command(TARGET CppStudy POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    "${FG_ROOT}/bin/x64/freeglut.dll"
    $<TARGET_FILE_DIR:CppStudy>
)

# --- ImGui ---
set(IMGUI_ROOT "${CMAKE_SOURCE_DIR}/libs/imgui_source")
set(IMGUI_SOURCES
    ${IMGUI_ROOT}/imgui.cpp
    ${IMGUI_ROOT}/imgui_draw.cpp
    ${IMGUI_ROOT}/imgui_tables.cpp
    ${IMGUI_ROOT}/imgui_widgets.cpp
    ${IMGUI_ROOT}/backends/imgui_impl_glut.cpp
    ${IMGUI_ROOT}/backends/imgui_impl_opengl2.cpp
)

add_library(imgui STATIC ${IMGUI_SOURCES})
target_include_directories(imgui PUBLIC
    ${IMGUI_ROOT}
    ${IMGUI_ROOT}/backends
    ${FG_ROOT}/include
)
target_link_libraries(imgui PUBLIC
    "${FG_LIB}/x64/libfreeglut.a"
    opengl32
    glu32
)
target_compile_definitions(imgui PUBLIC GLUT_DISABLE_ATEXIT_HACK)

# --- ライブラリリンク ---
target_link_libraries(CppStudy PRIVATE
    imgui
    "${FG_LIB}/x64/libfreeglut.a"
    opengl32
    glu32
)

# --- ライブラリ追加例 ---
# find_package(ライブラリ名 REQUIRED)
# target_link_libraries(CppStudy PRIVATE ライブラリ名::ライブラリ名)
# 例: find_package(Boost REQUIRED)
#     target_link_libraries(CppStudy PRIVATE Boost::boost)

# --- 外部ライブラリのインストール例 ---
# find_packageで利用するライブラリは事前にPCへインストールが必要です。
# 例: Boostの場合
#   - Windows: vcpkgやchocoで 'vcpkg install boost' または 'choco install boost'
#   - Linux: aptで 'sudo apt install libboost-all-dev'
#   - Mac: brewで 'brew install boost'
# 他のライブラリも同様に各OSのパッケージマネージャ等でインストールしてください。

# --- プロジェクト内libsディレクトリのライブラリを使う場合 ---
# 1. ヘッダーファイルのパスを追加
#    include_directories(${CMAKE_SOURCE_DIR}/libs/yourlib/include)
# 2. ライブラリファイルのパスを追加
#    link_directories(${CMAKE_SOURCE_DIR}/libs/yourlib/lib)
# 3. 実行ファイルにライブラリをリンク
#    target_link_libraries(CppStudy PRIVATE yourlibname)
#
# ※yourlib/include, yourlib/lib, yourlibnameは実際のディレクトリ名・ライブラリ名に置き換えてください
