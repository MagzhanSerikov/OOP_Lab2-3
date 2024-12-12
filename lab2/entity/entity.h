#include "coordintaion.h"
#include "field.h"

class entity
{
protected:
    cords position_;

public:
    entity(cords start_pos);
    virtual void move(Direction move_direction, field& game_field); 
    virtual void take_damage(int damage); 
    cords get_position() const;  
};
