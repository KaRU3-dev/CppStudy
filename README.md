# 環境構築
1. MinGWのダウンロード
   1. https://github.com/niXman/mingw-builds-binaries/releases にアクセス
   2. `x86_64-{VERSION}-release-win32-seh-ucrt-rt_v{VERSION_PREFIX}-rev{REVISION}.7z` をダウンロード
   3. 任意の場所に解凍
   4. 解凍したフォルダの中の`mingw`フォルダを任意の場所に移動
   5. `mingw/bin`をPATHに追加
2. CMakeのインストール
   1. https://cmake.org/download/ にアクセス
   2. `cmake-{VERSION}-rc2-windows-x86_64.msi` をダウンロード
   3. msiファイルを起動し、指示に従ってインストール
3. VSCodeのインストール
4. VSCodeの拡張機能のインストール
   1. `C/C++`, `CMake`を追加
5. CMakeのデフォルトジェネレータを設定
   1. 環境変数に `CMAKE_GENERATOR` を作成し、 `MinGW Makefiles` を登録する

# プロジェクト作成
1. [`CMakeLists.txt`](./CMakeLists.txt)を作成する
2. [`main.cpp`](./CppStudy.cpp)を作成する
3. `src`, `src/include`, `libs`ディレクトリを作成する
