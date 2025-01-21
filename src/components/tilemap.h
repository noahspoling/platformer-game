#ifndef TILEMAP_H
#define TILEMAP_H

#include "raylib.h"

#include "config.h"

#include "tile.h"


typedef struct {
    Tile tilemap[TILEMAP_WIDTH][TILEMAP_HEIGHT];
    int width;
    int height;
    int tileSize;
} Tilemap;


#endif // TILEMAP_H