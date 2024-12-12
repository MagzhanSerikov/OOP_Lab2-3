#include "controller.h"
#include "player.h"
#include "field.h"
#include "positive_event.h"
#include "negative_event.h"
#include "move_event.h"

int main()
{
    player p({1, 1});
    field f(5, 5);

    f.set_event_at(2, 2, new PositiveEvent(p));
    f.set_event_at(3, 3, new NegativeEvent(p));
    f.set_event_at(4, 4, new MoveEvent(p));

    Controller controller(p, f);

    controller.checkAndTriggerEvent(2, 2);  
    controller.checkAndTriggerEvent(3, 3); 
    controller.checkAndTriggerEvent(4, 4);  

    return 0;
}
