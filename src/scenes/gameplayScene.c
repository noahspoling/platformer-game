#include <stddef.h>
#include "gameplayScene.h"
#include "raylib.h"
#include "config.h"
#include "input/input.h"
#include "prototypes/movementPrototype.h"
#include "systems/collisionSystem.h"

static Movement movement;
static PhysicsEntity entity;
static RenderTexture2D target;

void initGameplayScene(void) {
    movement = (Movement){
        .position = {0, 0},
        .velocity = {0, 0},
        .acceleration = {0, 0}
    };
    entity.movement = movement;
    target = LoadRenderTexture(TILEMAP_WIDTH * TILE_SIZE, TILEMAP_HEIGHT * TILE_SIZE);
}

void updateGameplayScene(void) {
    handlePlatformerInput(&movement);
    handleCollision(&entity, 1, NULL, 0);

    movement.acceleration.y += GRAVITY;
    movement.velocity.x += movement.acceleration.x;
    movement.velocity.y += movement.acceleration.y;
    movement.position.x += movement.velocity.x;
    movement.position.y += movement.velocity.y;

    movement.acceleration.x = 0;
    movement.acceleration.y = 0;
    movement.velocity.x = 0;

    // Boundary checks
    if (movement.position.x < 0) movement.position.x = TILEMAP_WIDTH * TILE_SIZE;
    if (movement.position.y < 0) movement.position.y = 0;
    if (movement.position.x > TILEMAP_WIDTH * TILE_SIZE) movement.position.x = 0;
    if (movement.position.y > TILEMAP_HEIGHT * TILE_SIZE) {
        movement.velocity.y = 0;
        movement.position.y = TILEMAP_HEIGHT * TILE_SIZE;
    }
}

void drawGameplayScene(void) {
    BeginTextureMode(target);
    ClearBackground(BLANK);

    // Draw tilemap
    for (int y = 0; y < TILEMAP_HEIGHT; y++) {
        for (int x = 0; x < TILEMAP_WIDTH; x++) {
            if((x + y) % 2 == 0) {
                DrawRectangle(x * TILE_SIZE, y * TILE_SIZE, TILE_SIZE, TILE_SIZE, GRAY);
            } else {
                DrawRectangle(x * TILE_SIZE, y * TILE_SIZE, TILE_SIZE, TILE_SIZE, BLUE);
            }
        }
    }

    // Draw player
    DrawRectangle(movement.position.x, movement.position.y - 32, 32, 32, RED);
    EndTextureMode();

    // Draw scaled game
    float scaleX = (float)GetScreenWidth() / (TILEMAP_WIDTH * TILE_SIZE);
    float scaleY = (float)GetScreenHeight() / (TILEMAP_HEIGHT * TILE_SIZE);
    DrawTexturePro(target.texture,
        (Rectangle){ 0, 0, (float)target.texture.width, -(float)target.texture.height },
        (Rectangle){ 0, 0, GetScreenWidth(), GetScreenHeight() },
        (Vector2){ 0, 0 },
        0.0f,
        WHITE);
}

void unloadGameplayScene(void) {
    UnloadRenderTexture(target);
} 