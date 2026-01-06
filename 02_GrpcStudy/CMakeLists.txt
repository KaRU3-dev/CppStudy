cmake_minimum_required(VERSION 3.10.0)
project(GrpcStudy VERSION 0.1.0 LANGUAGES C CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# -- ライブラリの検索 ---
find_package(protobuf REQUIRED)
find_package(grpc REQUIRED)

# -- Protoファイル --
get_filename_component(hw_proto "${CMAKE_CURRENT_SOURCE_DIR}/protos/helloworld.proto" ABSOLUTE)
get_filename_component(hw_proto_path "${hw_proto}" PATH)

# -- protobufのソースを生成
protobuf_generate_cpp(hw_proto_srcs hw_proto_hdrs "${hw_proto}")
set(hw_grpc_srcs "${CMAKE_CURRENT_SOURCE_DIR}/helloworld.grpc.pb.cc")
set(hw_grpc_hdrs "${CMAKE_CURRENT_SOURCE_DIR}/helloworld.grpc.pb.h")

# -- 事前実行コマンドの登録 --
add_custom_command(
    OUTPUT "${hw_grpc_srcs}" ${hw_grpc_hdrs}
    COMMAND ${Protobuf_PROTOC_EXECUTABLE}
    ARGS --grpc_out=${CMAKE_CURRENT_SOURCE_DIR}
         --plugin=protoc-gen-grpc=$<TARGET_FILE:gRPC::grpc_cpp_plugin>
         -I ${CMAKE_CURRENT_SOURCE_DIR}/protos
         ${hw_proto}
    DEPENDS ${hw_proto}
    COMMENT "Generating gRPC sources..."
)

# -- ライブラリを登録 --
add_library(
    helloworld_proto
    ${hw_proto_srcs}
    ${hw_proto_hdrs}
    ${hw_grpc_srcs}
    ${hw_grpc_hdrs}
)
target_include_directories(helloworld_proto PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR})
target_link_libraries(helloworld_proto PRIVATE protobuf::libprotobuf gRPC::grpc++)

if (MINGW)
    message("MinGW detected")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libgcc -static-libstdc++")
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
add_executable(GrpcStudy GrpcStudy_server.cpp ${SRC_FILES})

# --- ライブラリの追加 ---
target_link_libraries(GrpcStudy PRIVATE helloworld_proto gRPC::grpc++)
