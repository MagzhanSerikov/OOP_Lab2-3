#include "entity.h"

class enemy : public entity
{
private:
    int health_;  
    int attack_; 

public:
    enemy(cords start_pos, int health = 100, int attack = 10);
    void attack_player(entity& player);  
    void take_damage(int damage);  
    int get_health() const;  
    int get_attack() const;  
};
