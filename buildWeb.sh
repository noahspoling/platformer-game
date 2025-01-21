#!/bin/bash

# Clean and create build directory
rm -rf build_web
mkdir build_web
cd build_web

# Configure with Emscripten
emcmake cmake .. \
    -DPLATFORM=Web \
    -DCMAKE_BUILD_TYPE=Release \
    -DCMAKE_EXE_LINKER_FLAGS="-s USE_GLFW=3 -s WASM=1 -s ASYNCIFY=1 -s ERROR_ON_UNDEFINED_SYMBOLS=0 -s EXPORTED_RUNTIME_METHODS=['ccall','cwrap'] -s MINIFY_HTML=0" \
    -DCMAKE_C_FLAGS="-s USE_GLFW=3" \
    -DUSE_WAYLAND=OFF

# Build
emmake make

# Copy HTML template if you have one
# cp ../src/web/shell.html ./index.html 2>/dev/null || :