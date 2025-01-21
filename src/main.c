#include "raylib.h"
#include "config.h"
#include "events/eventDispatcher.h"
#include "events/listeners/inputListeners.h"
#include "scenes/sceneManager.h"

#ifndef PLATFORM_WEB
#include "util/glfw_wrapper.h"  // Only include for desktop builds
#endif

int main(void) {
    InitWindow(DEFAULT_WINDOW_WIDTH, DEFAULT_WINDOW_HEIGHT, "Game");
    SetExitKey(KEY_F4);
    
    initEventDispatcher(getEventDispatcher());
    registerInputListeners();
    initSceneManager();

    SetTargetFPS(60);

    while (!WindowShouldClose() && !shouldExitGame()) {
        updateCurrentScene();

        BeginDrawing();
        ClearBackground(RAYWHITE);
        drawCurrentScene();
        EndDrawing();
    }

    unloadCurrentScene();
    unloadInputListeners();
    unloadEventDispatcher();
    CloseWindow();
    return 0;
}