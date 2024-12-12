#include "player.h"
#include "field.h"
#include "game_event.h"

enum Direction {Top, Bottom, Right, Left};

class Controller
{
private:
    player& p_;
    field& f_;
    cords cords_;
public:
    Controller(player& p, field& f, cords xy) : p_(p), f_(f) cords_(xy){}
    cords get_cords_();
    void move(Direction move_direction);
    void checkAndTriggerEvent(int x, int y)
    {
        GameEvent* event = f_.get_event_at(x, y);  
        if (event)
        {
            event->triggerEvent();  
        }
    }
};
