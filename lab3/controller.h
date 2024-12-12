#include "player.h"
#include "field.h"
#include "game_event.h"

class Controller
{
private:
    player& p_;
    field& f_;

public:
    Controller(player& p, field& f) : p_(p), f_(f) {}

    void checkAndTriggerEvent(int x, int y)
    {
        GameEvent* event = f_.get_event_at(x, y);  
        if (event)
        {
            event->triggerEvent();  
        }
    }
};
