#include "systems/collisionSystem.h"
#include <stddef.h>

#include "raylib.h"
#include "config.h"
#include "types/componentTypes.h"

#include "prototypes/physicsEntityPrototype.h"



void handleCollision(PhysicsEntity *entities, int entityCount, Rectangle *platforms, int platformCount) {
    // Checks against platforms / bounds / projectiles
    for (int i = 0; i < entityCount; i++) { 
        if (entities[i].movement.position.x < 0) {
            entities[i].movement.position.x = TILEMAP_WIDTH * TILE_SIZE;
        }
        if (entities[i].movement.position.y < 0) {
            entities[i].movement.position.y = 0;
        }
        if (entities[i].movement.position.x > TILEMAP_WIDTH * TILE_SIZE) {
            entities[i].movement.position.x = 0;
        }
        if (entities[i].movement.position.y > TILEMAP_HEIGHT * TILE_SIZE) {
            entities[i].movement.velocity.y = 0;
            entities[i].movement.position.y = TILEMAP_HEIGHT * TILE_SIZE;
        }
        // Checks against other entities
        for (int j = 0; j < entityCount; j++) {
            if (i != j) {

            }
        }
    }
}