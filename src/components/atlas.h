#ifndef ATLAS_H
#define ATLAS_H

#include "raylib.h"

typedef struct {
    Texture2D texture;
    int rows;
    int columns;
} Atlas;

Atlas* CreateAtlas(char* filename, int rows, int columns);
Rectangle GetAtlasSpriteRect(Atlas *atlas, int column, int row);
void DestroyAtlas(Atlas* atlas);

#endif // ATLAS_H