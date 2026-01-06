# Build cmake
cmake --build build -- -j6

# After build works
cd build
Get-ChildItem -Path "./vcpkg_installed/x64-mingw-dynamic/debug" -Recurse -File | Copy-Item -Destination . -Force

# Comeback to project folder
cd ..
