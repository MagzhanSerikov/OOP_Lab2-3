#include "game_event.h"
#include "player.h"

class MoveEvent : public GameEvent
{
private:
    player& player_;

public:
    MoveEvent(player& p) : player_(p) {}
    void triggerEvent() override
    {
        // Пример события, которое меняет координаты игрока
        player_.move(Direction::Right);
    }
};
