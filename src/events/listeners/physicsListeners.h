#ifndef PHYSICS_LISTENERS_H
#define PHYSICS_LISTENERS_H

#include "raylib.h"
#include "prototypes/phsyicsEntityPrototype.h"

void onUpdateCollision(Event *context) {
    PhysicsEntity *entity = (PhysicsEntity *)context->data;
    entity->movement.position.x += entity->movement.velocity.x;
    entity->movement.position.y += entity->movement.velocity.y;
}

void onUpdatePosition(Event *context) {
    PhysicsEntity *entity = (PhysicsEntity *)context->data;
    if (entity->movement.position.x < 0) {
        entity->movement.position.x = TILEMAP_WIDTH * TILE_SIZE;
    }
    if (entity->movement.position.y < 0) {
        entity->movement.position.y = 0;
    }
    if (entity->movement.position.x > TILEMAP_WIDTH * TILE_SIZE) {
        entity->movement.position.x = 0;
    }
    if (entity->movement.position.y > TILEMAP_HEIGHT * TILE_SIZE) {
        entity->movement.velocity.y = 0;
        entity->movement.position.y = TILEMAP_HEIGHT * TILE_SIZE;
    }
}


#endif // PHYSICS_LISTENERS_H