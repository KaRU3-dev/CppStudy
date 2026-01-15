# ファイルの取得
file(GLOB_RECURSE SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
include_directories(./includes)

# ファイルの表示
foreach(file ${SRC_FILES})
    message(STATUS "MultiProject.Logging source: ${file}")
endforeach(file ${SRC_FILES})


# ライブラリを構成
add_library(MultiProject.Logging STATIC ${SRC_FILES})
target_include_directories(
    MultiProject.Logging
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/includes
)
