#include "entity.h"
#include "field.h"

entity::entity(cords start_pos) : position_(start_pos) {}

void entity::move(Direction move_direction, field& game_field)
{
    int new_x = position_.x_;
    int new_y = position_.y_;

    switch (move_direction)
    {
    case Top: new_y += 1; break;
    case Bottom: new_y -= 1; break;
    case Right: new_x += 1; break;
    case Left: new_x -= 1; break;
    }

    if (game_field.touch_cell(new_x, new_y) != Barrier)
    {
        position_.x_ = new_x;
        position_.y_ = new_y;
    }
}

void entity::take_damage(int damage)
{
}
 
cords entity::get_position() const
{
    return position_;
}
