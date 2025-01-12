#ifndef INPUT_LISTENERS_H
#define INPUT_LISTENERS_H

#include "raylib.h"
#include "types/componentTypes.h"
#include "prototypes/movementPrototype.h"
#include "events/event.h"
#include "events/eventDispatcher.h"

void onJump(Event *context);
void onCrouch(Event *context);
void onMoveLeft(Event *context);
void onMoveRight(Event *context);

void registerInputListeners();

#endif // INPUT_LISTENERS_H