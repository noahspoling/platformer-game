#ifndef CONFIG_H
#define CONFIG_H

#ifdef PLATFORM_WEB
    #include <emscripten/emscripten.h>
    #include <emscripten/html5.h>
#endif

#define DEFAULT_WINDOW_WIDTH 800   // Matches the game-container width
#define DEFAULT_WINDOW_HEIGHT 600  // Matches the game-container height

#define TILEMAP_WIDTH 40
#define TILEMAP_HEIGHT 30
#define TILE_SIZE 32

#define GRAVITY 1.0f
#define JUMP_FORCE -35.0f

#endif // CONFIG_H