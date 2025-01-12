#ifndef INPUT_H
#define INPUT_H


// InputCommand is a command pattern
// It is used to encapsulate the input's action
typedef struct {
    void (*execute)(void *context);
} InputCommand;

// Define the input commands
// Wrapped in ifndef to prevent inclusion in final executable
// #ifndef INPUT_CONTEXT_TOP_DOWN
// #define INPUT_CONTEXT_TOP_DOWN
// void moveUp(void *context);
// void moveDown(void *context);
// void moveLeft(void *context);
// void moveRight(void *context);
// #endif

// #ifndef INPUT_CONTEXT_PLATFORMER
// #define INPUT_CONTEXT_PLATFORMER
void jump(void *context);
void crouch(void *context);
void moveLeft(void *context);
void moveRight(void *context);
// #endif // INPUT_CONTEXT_PLATFORMER

// InputHandler is a strategy pattern
// It is used to encapsulate the input handling logic
// This allows us to change the input handling logic at runtime
// Menus and gameplay would have different input handling logic
typedef struct {
    void (*execute)(void *context);
} InputHandler;

void handlePlatformerInput(void *context);

#endif // INPUT_H