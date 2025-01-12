#ifndef PHYSICS_ENTITY_PROTOTYPE_H
#define PHYSICS_ENTITY_PROTOTYPE_H

#include "raylib.h"
#include "prototypes/movementPrototype.h"
#include "components/collision.h"

typedef struct {
    Movement movement;
    Rectangle collision;
} PhysicsEntity;

#endif // PHYSICS_ENTITY_PROTOTYPE_H