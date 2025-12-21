#ifndef ENTITY_H
#define ENTITY_H

#include <string>
#include <vector>

class Entity {
    private:
        int health, max_health;
        int attack;
        int defense;
        int speed;
        std::string id;

        std::vector<std::string> skill_set;

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
        std::string get_name() const;

        void add_skill(std::string);
        std::vector<std::string> get_skills();
};

#endif