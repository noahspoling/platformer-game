#ifndef COLLISION_SYSTEM_H
#define COLLISION_SYSTEM_H

#include "raylib.h"

#include "types/componentTypes.h"
#include "prototypes/physicsEntityPrototype.h"

void handleCollision(PhysicsEntity *entities, int entityCount, Rectangle *platforms, int platformCount);

#endif // COLLISION_SYSTEM_H