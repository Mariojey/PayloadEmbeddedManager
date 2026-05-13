#ifndef EVENT_LISTENER_H
#define EVENT_LISTENER_H

#include "Config.h"

class EventListener
{
  public:
    bool begin();
    bool ready();
    void update();
};

#endif