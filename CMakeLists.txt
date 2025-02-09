cmake_minimum_required(VERSION 3.10)
project(Game C)

# Set C standard
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Platform detection and setting for raylib
if(EMSCRIPTEN)
    set(PLATFORM "Web")
    add_definitions(-DPLATFORM_WEB)
    add_definitions(-D__EMSCRIPTEN__)
    set(USE_X11 OFF)
    set(USE_WAYLAND OFF)
    set(OPENGL_VERSION "ES 2.0")

    add_compile_options(-Wno-implicit-function-declaration)
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

# Add raygui
add_library(raygui INTERFACE)
target_include_directories(raygui INTERFACE lib/extern/raygui/src)
target_compile_definitions(raygui INTERFACE RAYGUI_IMPLEMENTATION)

# After your existing target_link_libraries line, add:
target_link_libraries(${PROJECT_NAME} PRIVATE raygui)