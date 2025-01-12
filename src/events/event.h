#ifndef EVENT_H
#define EVENT_H

typedef enum {
    EVENT_JUMP,
    EVENT_CROUCH,
    EVENT_MOVE_LEFT,
    EVENT_MOVE_RIGHT,
    EVENT_PLAYER_COLLISION,

    EVENT_COUNT
} EventType;

typedef struct {
    EventType type;
    void* data;
} Event;

typedef void (*EventCallback)(Event *event);

#endif // EVENT_H