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

void Entity::add_skill(std::string skill) {
    skill_set.emplace_back(skill);
}

void Entity::add_status_effect(StatusEffect status) {
    status_effect_list.emplace_back(status);
}

void Entity::inflict_status() {
    std::vector<StatusEffect> new_status;

    for (StatusEffect& effect: status_effect_list) {
        effect.take_action();
        
        switch(effect.get_type()) {
            case StatusEffectType::Burn: {
                health = std::max(0, health-effect.get_value());
                std::printf("Burn inflicted on %s for %d damage", id.c_str(), effect.get_value());
            }
                break;
            case StatusEffectType::Poison: {
                health = std::max(0, health-effect.get_value());
                std::printf("Poison inflicted on %s for %d damage", id.c_str(), effect.get_value());
            }
                break;
            default:
                break;
        }
        
        if (effect.get_turns() != 0) {
            new_status.emplace_back(effect);
        }
    }

    status_effect_list = new_status;
}

int Entity::get_health() const {return health;}
int Entity::get_max_health() const {return max_health;}
int Entity::get_attack() const {return attack;}
int Entity::get_defense() const {return defense;}
int Entity::get_speed() const {return speed;}
std::string Entity::get_name() const {return id;}
std::vector<std::string> Entity::get_skills() {return skill_set;};
std::vector<StatusEffect> Entity::get_statuses() {return status_effect_list;};