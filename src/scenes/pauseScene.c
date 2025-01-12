#include "pauseScene.h"
#include "raylib.h"
#include "sceneManager.h"

void initPauseScene(void) {}
void updatePauseScene(void) {
    if (IsKeyPressed(KEY_ESCAPE)) changeScene(SCENE_GAMEPLAY);
}
void drawPauseScene(void) {
    DrawText("PAUSED", 190, 200, 20, LIGHTGRAY);
}
void unloadPauseScene(void) {} 