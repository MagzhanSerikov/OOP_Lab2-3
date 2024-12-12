#include "player.h"
#include "enemy.h"

player::player(cords start_pos, int health, int attack)
    : entity(start_pos), health_(health), attack_(attack) {}

void player::attack_enemy(entity& enemy)
{
    // Логика атаки на врага
    enemy.take_damage(attack_);
}

void player::take_damage(int damage)
{
    health_ -= damage;
    if (health_ < 0) health_ = 0;
}

int player::get_health() const
{
    return health_;
}

int player::get_attack() const
{
    return attack_;
}
