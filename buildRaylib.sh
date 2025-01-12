#!/bin/bash

# Create necessary directories
mkdir -p lib/extern
cd lib/extern

# Clone the raylib repository
# git clone https://github.com/raysan5/raylib.git

# Navigate to the raylib directory
cd raylib

# Build raylib
mkdir -p build
cd build


echo "Configuring CMake for local platform..."
cmake -S .. -B . -DPLATFORM=Desktop -DBUILD_SHARED_LIBS=OFF -DBUILD_EXAMPLES=OFF -DCMAKE_INSTALL_PREFIX=$(pwd)
if [ $? -ne 0 ]; then
    echo "Error: CMake configuration failed."
    exit 1
fi

# Build in build_local directory
echo "Building raylib for local platform..."
make
if [ $? -ne 0 ]; then
    echo "Error: make failed."
    exit 1
fi

# Move the built library to the desired location
# mv libraylib.a ../../lib/extern/

# Navigate back to the original directory
cd ../../..


echo "raylib has been built and moved to lib/extern"