#include "raylib.h"
#include "config.h"
#include "events/eventDispatcher.h"
#include "events/listeners/inputListeners.h"
#include "scenes/sceneManager.h"

int main(void) {
    InitWindow(DEFAULT_WINDOW_WIDTH, DEFAULT_WINDOW_HEIGHT, "Game");
    
    initEventDispatcher(getEventDispatcher());
    registerInputListeners();
    initSceneManager();

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        updateCurrentScene();

        BeginDrawing();
        ClearBackground(RAYWHITE);
        drawCurrentScene();
        EndDrawing();
    }

    unloadCurrentScene();
    CloseWindow();
    return 0;
}