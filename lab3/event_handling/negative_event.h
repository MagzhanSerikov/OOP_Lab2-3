#include "game_event.h"
#include "player.h"

class NegativeEvent : public GameEvent
{
private:
    player& player_;

public:
    NegativeEvent(player& p) : player_(p) {}
    void triggerEvent() override
    {
        player_.decrease_health(10);
    }
};
