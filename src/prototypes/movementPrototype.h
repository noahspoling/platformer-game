#ifndef MOVEMENT_PROTOTYPE_H
#define MOVEMENT_PROTOTYPE_H

#include "raylib.h"
#include "types/componentTypes.h"

typedef struct {
    Position position;
    Velocity velocity;
    Acceleration acceleration;
} Movement;

#endif // MOVEMENT_PROTOTYPE_H