cmake_minimum_required(VERSION 3.10)
project(Game C)

# Set C standard
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Platform detection and setting for raylib
if(EMSCRIPTEN)
    set(PLATFORM "Web")
    add_definitions(-DPLATFORM_WEB)
else()
    set(PLATFORM "Desktop")
endif()

# Build type options
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Debug")
endif()

# Add raylib
set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # Don't build raylib examples
add_subdirectory(lib/extern/raylib)

# Collect source files
file(GLOB_RECURSE SOURCES "src/*.c")

# Create executable
add_executable(${PROJECT_NAME} ${SOURCES})

# Include directories
target_include_directories(${PROJECT_NAME} PRIVATE
    src
    src/include
)

# Link libraries
target_link_libraries(${PROJECT_NAME} PRIVATE raylib)

# Platform-specific settings
if(NOT EMSCRIPTEN)  # Only add these for native builds
    if(APPLE)
        target_link_libraries(${PROJECT_NAME} PRIVATE "-framework IOKit")
        target_link_libraries(${PROJECT_NAME} PRIVATE "-framework Cocoa")
        target_link_libraries(${PROJECT_NAME} PRIVATE "-framework OpenGL")
    elseif(WIN32)
        # Windows-specific settings if needed
    elseif(UNIX AND NOT APPLE)
        # Linux-specific settings if needed
        find_package(X11 REQUIRED)
        target_link_libraries(${PROJECT_NAME} PRIVATE X11)
        find_package(OpenGL REQUIRED)
        target_link_libraries(${PROJECT_NAME} PRIVATE OpenGL::GL)
    endif()
endif()

# WebAssembly build configuration
if(EMSCRIPTEN)
    set(WEB_SHELL "${CMAKE_CURRENT_SOURCE_DIR}/shell.html")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        SUFFIX ".html"
        LINK_FLAGS "-s USE_GLFW=3 -s ASSERTIONS=1 -s WASM=1 -s ASYNCIFY -s ALLOW_MEMORY_GROWTH=1 --shell-file ${WEB_SHELL}"
    )
endif()