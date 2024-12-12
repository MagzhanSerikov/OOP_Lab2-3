#include "game_event.h"
#include "player.h"

class PositiveEvent : public GameEvent
{
private:
    player& player_;

public:
    PositiveEvent(player& p) : player_(p) {}
    void triggerEvent() override
    {
        player_.increase_health(10);
    }
};
