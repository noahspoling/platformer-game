#ifndef TILEMAP_H
#define TILEMAP_H

#include "raylib.h"
#include "config.h"


typedef struct {
    int tilemap[TILEMAP_WIDTH][TILEMAP_HEIGHT];
    int width;
    int height;
    int tileSize;
} Tilemap;


#endif // TILEMAP_H