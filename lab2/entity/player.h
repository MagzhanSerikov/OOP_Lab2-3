#include "entity.h"

class player : public entity
{
private:
    int health_;
    int attack_;

public:
    player(cords start_pos, int health = 100, int attack = 10);
    void attack_enemy(entity& enemy);  // Атака врага
    void take_damage(int damage) override;  // Переопределяем получение урона
    int get_health() const;
    int get_attack() const;
};
