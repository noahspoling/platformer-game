#include "menuScene.h"
#include "raylib.h"
#include "sceneManager.h"
#include "gui.h"

void initMenuScene(void) {}
void updateMenuScene(void) {
    if (IsKeyPressed(KEY_ENTER)) changeScene(SCENE_GAMEPLAY);
}
void drawMenuScene(void) {
    if (GuiButton((Rectangle){ 190, 200, 120, 40 }, "Start Game")) {
        changeScene(SCENE_GAMEPLAY);
    }
    if (GuiButton((Rectangle){ 190, 250, 120, 40 }, "Map Editor")) {
        changeScene(SCENE_MAP_EDITOR);
    }
}
void unloadMenuScene(void) {} 