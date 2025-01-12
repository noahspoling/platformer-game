#include "sceneManager.h"
#include "scenes/gameplayScene.h"
#include "scenes/menuScene.h"
#include "scenes/pauseScene.h"
#include <stdlib.h>

static SceneType currentSceneType = SCENE_NONE;
static Scene *currentScene = NULL;
static Scene scenes[SCENE_COUNT];

void initSceneManager(void) {
    // Initialize all scenes
    scenes[SCENE_MENU] = (Scene){
        .init = initMenuScene,
        .update = updateMenuScene,
        .draw = drawMenuScene,
        .unload = unloadMenuScene
    };

    scenes[SCENE_GAMEPLAY] = (Scene){
        .init = initGameplayScene,
        .update = updateGameplayScene,
        .draw = drawGameplayScene,
        .unload = unloadGameplayScene
    };

    scenes[SCENE_PAUSE] = (Scene){
        .init = initPauseScene,
        .update = updatePauseScene,
        .draw = drawPauseScene,
        .unload = unloadPauseScene
    };

    // Start with menu scene
    changeScene(SCENE_MENU);
}

void changeScene(SceneType newScene) {
    if (newScene >= SCENE_COUNT) return;
    
    // Unload current scene if it exists
    if (currentScene != NULL && currentScene->unload != NULL) {
        currentScene->unload();
    }

    currentSceneType = newScene;
    currentScene = &scenes[newScene];

    // Initialize new scene
    if (currentScene->init != NULL) {
        currentScene->init();
    }
}

void updateCurrentScene(void) {
    if (currentScene != NULL && currentScene->update != NULL) {
        currentScene->update();
    }
}

void drawCurrentScene(void) {
    if (currentScene != NULL && currentScene->draw != NULL) {
        currentScene->draw();
    }
}

void unloadCurrentScene(void) {
    if (currentScene != NULL && currentScene->unload != NULL) {
        currentScene->unload();
    }
}

SceneType getCurrentScene(void) {
    return currentSceneType;
} 