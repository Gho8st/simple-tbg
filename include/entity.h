#ifndef ENTITY_H
#define ENTITY_H

class Entity {
    private:
        int health, max_health;
        int attack;
        int defense;

    public:
        Entity(int hp, int atk, int def);

        int take_damage(int dmg);
        int heal(int hp);

        int get_health() const;
        int get_attack() const;
        int get_defense() const;
};

#endif