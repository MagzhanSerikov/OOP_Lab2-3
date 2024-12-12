#include "enemy.h"
#include "player.h"  

enemy::enemy(cords start_pos, int health, int attack)
    : entity(start_pos), health_(health), attack_(attack) {}

void enemy::attack_player(entity& player)
{
    player.take_damage(attack_);
}

void enemy::take_damage(int damage)
{
    health_ -= damage;
    if (health_ < 0) health_ = 0;
}

int enemy::get_health() const
{
    return health_;
}

int enemy::get_attack() const
{
    return attack_;
}
