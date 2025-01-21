#include "mapEditorScene.h"

MapEditorState editorState;

typedef enum {
    MAP_EDIT_MAP_TILE_MODE,
    
    MAP_EDIT_LEVEL_MODE,

} MapEditMode;


void initMapEditorScene(void) {
    editorState.currentEditMode = MAP_EDITOR_LEVEL;
    editorState.camera = (Camera2D) { 0 };
    editorState.camera.target = (Vector2) { 0 };
    editorState.camera.offset = (Vector2) { 0 };
    editorState.camera.rotation = 0.0f;
    editorState.camera.zoom = 1.0f;
}

void updateMapEditorScene(void) {
    // Update map editor logic
}

void drawMapEditorScene(void) {
    // Draw map editor
}

void unloadMapEditorScene(void) {
    // Unload map editor resources
}   