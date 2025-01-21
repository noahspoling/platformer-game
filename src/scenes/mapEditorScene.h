#ifndef MAP_EDITOR_SCENE_H
#define MAP_EDITOR_SCENE_H

#include "raylib.h"

typedef enum {
    MAP_EDITOR_LEVEL, // Editor for connecting tilemaps on a level
    MAP_EDITOR_TILEMAP, // Editor for tilemap presets
    MAP_EDITOR_TILEMAP_INSTANCE, // Editor for tilemap instances for entities and items
} EditMode;

typedef struct {
    EditMode currentEditMode;
    Camera2D camera;
    //Vector2 maxCameraRange;
} MapEditorState;

// Remove global variables
extern MapEditorState editorState;

void initMapEditorScene(void);
void updateMapEditorScene(void);
void drawMapEditorScene(void);
void unloadMapEditorScene(void);

#endif // MAP_EDITOR_SCENE_H