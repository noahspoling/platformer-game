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
    // SetTraceLogLevel(LOG_WARNING); // Set the log level to only log errors

    Movement movement = {
        .position = {0, 0},
        .velocity = {0, 0},
        .acceleration = {0, 0}
    };
    TraceLog(LOG_INFO, "Address of movement: %p", (void*)&movement);

    initEventDispatcher(getEventDispatcher());
    registerInputListeners();
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "raylib [core] example - basic window");

    RenderTexture2D target = LoadRenderTexture(TILEMAP_WIDTH * TILE_SIZE, TILEMAP_HEIGHT * TILE_SIZE);

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {

        handlePlatformerInput(&movement); // Handle the input
        
        handleCollision(&movement, NULL, 0); // Handle the collision

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

        for (int y = 0; y < TILEMAP_HEIGHT; y++)
        {
            for (int x = 0; x < TILEMAP_WIDTH; x++)
            {
                // Draw each tile (replace with your tile drawing logic)
                if((x + y) % 2 == 0) DrawRectangle(x * TILE_SIZE, y * TILE_SIZE, TILE_SIZE, TILE_SIZE, GRAY);
                else DrawRectangle(x * TILE_SIZE, y * TILE_SIZE, TILE_SIZE, TILE_SIZE, BLUE);
            }
        }

        DrawRectangle(movement.position.x, movement.position.y, -32, -32, RED);

        EndTextureMode();

        DrawTexturePro(target.texture, (Rectangle){0, 0, target.texture.width, -target.texture.height},
                       (Rectangle){0, 0, WINDOW_WIDTH, WINDOW_HEIGHT}, (Vector2){0, 0}, 0.0f, WHITE);

        Vector2 scaledPosition = getScaledPosition(movement.position);
        TraceLog(LOG_INFO, "Scaled position: %f, %f", scaledPosition.x, scaledPosition.y);
        


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