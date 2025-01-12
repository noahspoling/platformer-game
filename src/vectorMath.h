// Vector2 scaledPosition = {
//             movement.position.x * (screenWidth / (float)(TILEMAP_WIDTH * TILE_SIZE)),
//             movement.position.y * (screenHeight / (float)(TILEMAP_HEIGHT * TILE_SIZE))
//         };

#include "raylib.h"
#include "config.h"


Vector2 getScaledPosition(Vector2 position) {
    float scaleX = (float)DEFAULT_WINDOW_WIDTH / (TILEMAP_WIDTH * TILE_SIZE);
    float scaleY = (float)DEFAULT_WINDOW_HEIGHT / (TILEMAP_HEIGHT * TILE_SIZE);
    
    return (Vector2){
        position.x * scaleX,
        position.y * scaleY
    };
}