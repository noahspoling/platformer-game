#ifndef EVENT_DISPATCHER_H
#define EVENT_DISPATCHER_H

#include <stddef.h>
#include "events/event.h"

#define MAX_EVENT_LISTENERS 10

typedef struct {
    EventCallback callback[MAX_EVENT_LISTENERS];
    int listenerCount;
} EventListenerList;

typedef struct {
    EventListenerList listeners[EVENT_COUNT];
} EventDispatcher;
// static EventDispatcher *dispatcher_instance = NULL;

// Get the singleton instance of the event dispatcher
EventDispatcher *getEventDispatcher();


void initEventDispatcher(EventDispatcher *eventDispatcher);
void registerListener(EventType eventType, EventCallback callback);
void dispatchEvent(Event *event);
void unloadEventDispatcher();

#endif // EVENT_DISPATCHER_H