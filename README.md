# 環境構築
1. MinGWのダウンロード
   1. https://github.com/niXman/mingw-builds-binaries/releases にアクセス
   2. `x86_64-{VERSION}-release-win32-seh-ucrt-rt_v{VERSION_PREFIX}-rev{REVISION}.7z` をダウンロード
   3. 任意の場所に解凍
   4. 解凍したフォルダの中の`mingw`フォルダを任意の場所に移動
   5. `mingw/bin`をPATHに追加
2. vcpkgのインストール
   1. `git clone https://github.com/microsoft/vcpkg.git`
   2. `cd vcpkg`
   3. `bootstrap-vcpkg.bat`
   4. `vcpkg install x64-windows`
   5. `vcpkg integrate install`
   6. `vcpkg update`
   7. 環境変数に
      1. `VCPKG_BINARY_SOURCES: clear;files,F:\.env\C_langs\vcpkg\.bin-cache,readwrite`
      2. `VCPKG_ROOT: C:\Path\To\vcpkg-root`
3. CMakeのインストール
   1. https://cmake.org/download/ にアクセス
   2. `cmake-{VERSION}-rc2-windows-x86_64.msi` をダウンロード
   3. msiファイルを起動し、指示に従ってインストール
4. VSCodeのインストール
5. VSCodeの拡張機能のインストール
   1. `C/C++`, `CMake`を追加
6. CMakeのデフォルトジェネレータを設定
   1. 環境変数に `CMAKE_GENERATOR` を作成し、 `MinGW Makefiles` を登録する

# プロジェクト作成
1. [`CMakeLists.txt`](./CMakeLists.txt)を作成する
2. [`main.cpp`](./CppStudy.cpp)を作成する
3. `src`, `src/include`, `libs`ディレクトリを作成する
