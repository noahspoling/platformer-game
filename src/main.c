#include "raylib.h"
#include <stddef.h>

#include "config.h"
#include "vectorMath.h"
#include "input/input.h"
// #include "types/componentTypes.h"
#include "events/event.h"
#include "events/eventDispatcher.h"
#include "events/listeners/inputListeners.h"
#include "prototypes/movementPrototype.h"
#include "systems/collisionSystem.h"

int main(void)
{
    // Initialize window dimensions
    int windowWidth = DEFAULT_WINDOW_WIDTH;
    int windowHeight = DEFAULT_WINDOW_HEIGHT;

    // SetTraceLogLevel(LOG_WARNING); // Set the log level to only log errors

    Movement movement = {
        .position = {0, 0},
        .velocity = {0, 0},
        .acceleration = {0, 0}
    };
    TraceLog(LOG_INFO, "Address of movement: %p", (void*)&movement);
    PhysicsEntity entity = { .movement = movement };

    initEventDispatcher(getEventDispatcher());
    registerInputListeners();

    // Initialize window
    #ifdef PLATFORM_WEB
        InitWindow(DEFAULT_WINDOW_WIDTH, DEFAULT_WINDOW_HEIGHT, "Game");
        // No resize handling - we want fixed size
    #else
        InitWindow(DEFAULT_WINDOW_WIDTH, DEFAULT_WINDOW_HEIGHT, "Game");
    #endif

    RenderTexture2D target = LoadRenderTexture(TILEMAP_WIDTH * TILE_SIZE, TILEMAP_HEIGHT * TILE_SIZE);

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {

        handlePlatformerInput(&movement); // Handle the input
        
        handleCollision(&entity, 1, NULL, 0); // Handle the collision

        TraceLog(LOG_INFO, "Position: %f, %f", movement.position.x, movement.position.y);
        TraceLog(LOG_INFO, "Velocity: %f, %f", movement.velocity.x, movement.velocity.y);
        TraceLog(LOG_INFO, "Acceleration: %f, %f", movement.acceleration.x, movement.acceleration.y);

        movement.acceleration.y += GRAVITY;

        TraceLog(LOG_INFO, "Position: %f, %f", movement.position.x, movement.position.y);
        TraceLog(LOG_INFO, "Velocity: %f, %f", movement.velocity.x, movement.velocity.y);
        TraceLog(LOG_INFO, "Acceleration: %f, %f", movement.acceleration.x, movement.acceleration.y);

        if (movement.position.y < TILEMAP_HEIGHT * TILE_SIZE) {
            movement.velocity.y += GRAVITY;
        }

        movement.velocity.x += movement.acceleration.x;
        movement.velocity.y += movement.acceleration.y;

        movement.position.x += movement.velocity.x;
        movement.position.y += movement.velocity.y;

        movement.acceleration.x = 0; // Reset after applying
        movement.acceleration.y = 0; // Reset after applying

        // movement.velocity.y = 0;

        movement.velocity.x = 0;
        movement.acceleration.x = 0;
        

        if (movement.position.x < 0) {
            // map change will go here
            movement.position.x = TILEMAP_WIDTH * TILE_SIZE;
        }
        if (movement.position.y < 0) {
            // map change will go here
            movement.position.y = 0;
        }
        if (movement.position.x > TILEMAP_WIDTH * TILE_SIZE) {
            // map change will go here
            movement.position.x = 0;
        }
        if (movement.position.y > TILEMAP_HEIGHT * TILE_SIZE) {
            // map change will go here
            movement.velocity.y = 0;
            movement.position.y = TILEMAP_HEIGHT * TILE_SIZE;
        }

        // TraceLog(LOG_INFO, "Position: %f, %f", movement.position.x, movement.position.y);
        // TraceLog(LOG_INFO, "Velocity: %f, %f", movement.velocity.x, movement.velocity.y);

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();
        ClearBackground(RAYWHITE);

        BeginTextureMode(target);     // Enable drawing to texture for scaling
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

        // Draw the player rectangle from top-left corner instead of bottom-right
        DrawRectangle(movement.position.x, movement.position.y - 32, 32, 32, RED);

        EndTextureMode();

        // Calculate the scale factor
        float scaleX = (float)windowWidth / (TILEMAP_WIDTH * TILE_SIZE);
        float scaleY = (float)windowHeight / (TILEMAP_HEIGHT * TILE_SIZE);

        // Draw the scaled texture
        DrawTexturePro(target.texture, 
            (Rectangle){ 0, 0, (float)target.texture.width, -(float)target.texture.height },
            (Rectangle){ 0, 0, (float)windowWidth, (float)windowHeight },
            (Vector2){ 0, 0 }, 
            0.0f, 
            WHITE);

        // Draw text on top of the scaled game
        DrawText("Hello, world!", 190, 200, 20, LIGHTGRAY);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}