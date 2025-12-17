#include "entity.h"
#include <algorithm>

Entity::Entity(std::string name, int hp, int atk, int def, int spd) {
    id = name;
    max_health = health = hp;
    attack = atk;
    defense = def;
    speed = spd;
}

int Entity::take_damage(int dmg) {
    int final_dmg = std::max(0, dmg - defense);
    health = std::max(0, health - final_dmg);
    return final_dmg;
}

int Entity::heal(int hp) {
    health = std::min(max_health, health + hp);
    return hp;
}

bool Entity::is_alive() const {
    return health > 0;
}

int Entity::get_health() const {return health;}
int Entity::get_max_health() const {return max_health;}
int Entity::get_attack() const {return attack;}
int Entity::get_defense() const {return defense;}
int Entity::get_speed() const {return speed;}
std::string Entity::get_name() const {return id;}