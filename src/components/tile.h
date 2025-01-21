#ifndef TILE_H
#define TILE_H

#include "raylib.h"
#include "config.h"

typedef enum {
    TILE_EMPTY,
    TILE_BLOCK,
    TILE_COUNT
} TileType;

typedef struct {
    TileType type;
} Tile;

#endif // TILE_H