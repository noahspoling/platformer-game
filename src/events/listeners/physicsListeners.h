#ifndef PHYSICS_LISTENERS_H
#define PHYSICS_LISTENERS_H

#include "raylib.h"
#include "prototypes/phsyicsEntityPrototype.h"

void onUpdateCollision(Event *context);
void onUpdatePosition(Event *context);


#endif // PHYSICS_LISTENERS_H