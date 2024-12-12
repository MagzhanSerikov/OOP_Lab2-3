#include "controller.h"

controller::controller(entity& some_entity, field& game_field, cords start_cords)
    : e(some_entity), f(game_field), cords_(start_cords) {}

cords controller::get_cords() const
{
    return cords_;
}

void controller::move(Direction move_direction)
{
    int new_x = cords_.x_;
    int new_y = cords_.y_;

    switch (move_direction)
    {
    case Top:
        new_y += 1;
        break;
    case Bottom:
        new_y -= 1;
        break;
    case Right:
        new_x += 1;
        break;
    case Left:
        new_x -= 1;
        break;
    }

    if (f.touch_cell(new_x, new_y) != Barrier)
    {
        cords_.x_ = new_x;
        cords_.y_ = new_y;
    }
}
