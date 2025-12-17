#ifndef ENTITY_H
#define ENTITY_H

#include <string>

class Entity {
    private:
        int health, max_health;
        int attack;
        int defense;
        int speed;
        std::string id;

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

        
};

#endif