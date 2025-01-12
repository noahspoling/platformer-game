#ifndef COLLISION_H
#define COLLISION_H

#include <stdbool.h>
#include "raylib.h"
#include "components/edges.h"

typedef struct {
    Rectangle rect;
    Edges edges;
} Collision;

#endif // COLLISION_H