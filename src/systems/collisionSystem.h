#ifndef COLLISION_SYSTEM_H
#define COLLISION_SYSTEM_H

#include "raylib.h"

#include "types/componentTypes.h"
#include "prototypes/movementPrototype.h"

void handleCollision(Movement *movement, Rectangle *platforms, int platformCount);

#endif // COLLISION_SYSTEM_H