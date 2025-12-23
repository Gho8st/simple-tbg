#ifndef ENTITY_H
#define ENTITY_H

#include <string>
#include <vector>
#include "status_effect.h"


class Entity {
    private:
        int health, max_health;
        int attack;
        int defense;
        int speed;
        std::string id;

        std::vector<std::string> skill_set;
        std::vector<StatusEffect> status_effect_list;

    public:
        Entity(std::string name, int hp, int atk, int def, int spd);

        int take_damage(int dmg);
        int heal(int hp);
        bool is_alive() const;

        int get_health() const;
        int get_max_health() const;
        int get_attack() const;
        int get_defense() const;
        int get_speed() const;

        int get_effective_speed();
        int get_effective_attack();
        int get_effective_defense();
        std::string get_name() const;

        void add_skill(std::string);
        std::vector<std::string> get_skills();

        void add_status_effect(StatusEffect effect);
        void inflict_status();
        std::vector<StatusEffect> get_statuses();
};

#endif