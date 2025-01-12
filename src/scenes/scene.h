#ifndef SCENE_H
#define SCENE_H

#include "raylib.h"

/******************** SceneType ********************/
/*
    File: scene.h
    Author: Noah Poling
    Date: 2025-01-12

    Description: Scenes are used to switch between different states of the game.

*/

typedef enum {
    SCENE_NONE = -1, // So it doesn't fuck up the count
    SCENE_MENU,
    SCENE_GAMEPLAY,
    SCENE_PAUSE,
    SCENE_COUNT
} SceneType;

typedef struct Scene {
    void (*init)(void);     // Initialize scene resources
    void (*update)(void);   // Update scene logic
    void (*draw)(void);     // Draw scene
    void (*unload)(void);   // Unload scene resources
} Scene;

#endif // SCENE_H 