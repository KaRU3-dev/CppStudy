# 実行ターゲットの設定
file(GLOB_RECURSE SRC_FILES src/*.cpp)
include_directories(./includes)


# 実行ターゲットの追加
add_executable(MultiProject ${SRC_FILES})


# ライブラリのリンク
# target_link_libraries(MultiProject PRIVATE LIB_NAME)
target_link_libraries(MultiProject PRIVATE MultiProject.Logging)
