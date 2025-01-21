#include "menuScene.h"
#include "raylib.h"
#include "sceneManager.h"
#include "gui.h"

static bool shouldExit = false;

void initMenuScene(void) {}
void updateMenuScene(void) {
    if (IsKeyPressed(KEY_ENTER)) changeScene(SCENE_GAMEPLAY);
}
void drawMenuScene(void) {

    if (GuiButton((Rectangle) {190, 150, 120, 40}, "Play")) {
        changeScene(SCENE_GAMEPLAY);
    }
    if (GuiButton((Rectangle){ 190, 200, 120, 40 }, "Options")) {
        changeScene(SCENE_GAMEPLAY);
    }
    if (GuiButton((Rectangle){ 190, 250, 120, 40 }, "Map Editor")) {
        changeScene(SCENE_MAP_EDITOR);
    }
    if (GuiButton((Rectangle){ 190, 300, 120, 40 }, "Exit")) {
        shouldExit = true;
    }
}
void unloadMenuScene(void) {
}

bool shouldExitGame(void) {
    return shouldExit;
} 