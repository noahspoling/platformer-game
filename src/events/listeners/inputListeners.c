#include "events/event.h"
#include "events/eventDispatcher.h"
#include "config.h"
#include "prototypes/movementPrototype.h"
#include "events/listeners/inputListeners.h"

void onJump(Event *context) {
    Movement *movement = (Movement *)context->data;
    TraceLog(LOG_INFO, "Event Jumping");
    if (movement->velocity.y == 0) { // Only allow jumping if on the ground
        movement->acceleration.y = JUMP_FORCE;
        TraceLog(LOG_INFO, "Velocity: %f, %f", movement->velocity.x, movement->velocity.y);
    }
}

void onCrouch(Event *context) {
    Movement *movement = (Movement *)context->data;
    TraceLog(LOG_INFO, "Event Crouching");
    movement->velocity.y = 0;
}

void onMoveLeft(Event *context) {
    Movement *movement = (Movement *)context->data;
    TraceLog(LOG_INFO, "Event Moving left");
    movement->acceleration.x = -10;
    TraceLog(LOG_INFO, "Address of movement: %p", (void*)&movement);
    TraceLog(LOG_INFO, "Velocity: %f, %f", movement->acceleration.x, movement->acceleration.y);
}

void onMoveRight(Event *context) {
    Movement *movement = (Movement *)context->data;
    TraceLog(LOG_INFO, "Event Moving right");
    movement->acceleration.x = 10;
}

void registerInputListeners() {
    TraceLog(LOG_INFO, "Registering input listeners");
    registerListener(EVENT_JUMP, onJump);
    registerListener(EVENT_CROUCH, onCrouch);
    registerListener(EVENT_MOVE_LEFT, onMoveLeft);
    registerListener(EVENT_MOVE_RIGHT, onMoveRight);
}