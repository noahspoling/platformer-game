#include "events/eventDispatcher.h"
#include "raylib.h"
#include <stdlib.h>

static EventDispatcher *dispatcher_instance = NULL;

void initEventDispatcher(EventDispatcher *eventDispatcher) {
    for(int i = 0; i < EVENT_COUNT; i++) {
        eventDispatcher->listeners[i].listenerCount = 0;
    }
}
EventDispatcher *getEventDispatcher() {
    if (dispatcher_instance == NULL) {
        dispatcher_instance = (EventDispatcher *)malloc(sizeof(EventDispatcher));
        initEventDispatcher(dispatcher_instance);
    }
    return dispatcher_instance;
}


void registerListener(EventType eventType, void (*callback)(Event *)) {
    EventDispatcher *dispatcher = getEventDispatcher();
    EventListenerList *list = &dispatcher->listeners[eventType];

    if(list->listenerCount < MAX_EVENT_LISTENERS) {
        list->callback[list->listenerCount++] = callback;
    } else {
        TraceLog(LOG_WARNING, "Max listeners reached for event type %d", eventType);
    }
}

void dispatchEvent(Event *event) {
    TraceLog(LOG_INFO, "Dispatching event %d", event->type);
    EventDispatcher *dispatcher = getEventDispatcher();
    EventListenerList *list = &dispatcher->listeners[event->type];

    for(int i = 0; i < list->listenerCount; i++) {
        TraceLog(LOG_INFO, "Calling listener %d", i);
        list->callback[i](event);
    }
}