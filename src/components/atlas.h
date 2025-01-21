#ifndef ATLAS_H
#define ATLAS_H

#include "raylib.h"

typedef struct {
    Texture2D texture;
    int rows;
    int columns;
} Atlas;

static inline int GetAtlasTileWidth(Atlas atlas) {
    return atlas.texture.width / atlas.columns;
}

static inline int GetAtlasTileHeight(Atlas atlas) {
    return atlas.texture.height / atlas.rows;
}

#endif // ATLAS_H