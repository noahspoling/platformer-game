#include "input.h"
#include "raylib.h"

#include "events/event.h"
#include "events/eventDispatcher.h"
#include "types/componentTypes.h"
#include "prototypes/movementPrototype.h"

void jump(void *context) {
    TraceLog(LOG_INFO, "Jumping");
    Event event = {
        .type = EVENT_JUMP,
        .data = context
    };
    dispatchEvent(&event);
}

void crouch(void *context) {
    TraceLog(LOG_INFO, "Crouching");
    Event event = {
        .type = EVENT_CROUCH,
        .data = context
    };
    dispatchEvent(&event);
}

void moveLeft(void *context) {
    TraceLog(LOG_INFO, "Moving left");
    Event event = {
        .type = EVENT_MOVE_LEFT,
        .data = context
    };
    dispatchEvent(&event);
}
void moveRight(void *context) {
    TraceLog(LOG_INFO, "Moving right");
    Event event = {
        .type = EVENT_MOVE_RIGHT,
        .data = context
    };
    dispatchEvent(&event);
}

void handlePlatformerInput(void *context) {
    Movement *movement = (Movement *)context; // CHANGE THIS IF THIS SOMEHOW IS USED MORE DYNAMICALLY
    if (IsKeyPressed(KEY_SPACE)) {
        jump(movement);
    }
    if (IsKeyDown(KEY_DOWN)) {
        crouch(movement);
    }
    if (IsKeyDown(KEY_LEFT)) {
        moveLeft(movement);
    }
    if (IsKeyDown(KEY_RIGHT)) {
        moveRight(movement);
    }
}