// Vector2 scaledPosition = {
//             movement.position.x * (screenWidth / (float)(TILEMAP_WIDTH * TILE_SIZE)),
//             movement.position.y * (screenHeight / (float)(TILEMAP_HEIGHT * TILE_SIZE))
//         };

#include "raylib.h"
#include "config.h"


Vector2 getScaledPosition(Vector2 position) {
    return (Vector2){
        position.x * (WINDOW_WIDTH / (float)(TILEMAP_WIDTH * TILE_SIZE)),
        position.y * (WINDOW_HEIGHT / (float)(TILEMAP_HEIGHT * TILE_SIZE))
    };
}