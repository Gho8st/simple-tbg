#ifndef TURN_MANAGER_H
#define TURN_MANAGER_H

#include "entity.h"
#include <vector>

struct Turn {
    Entity* entity;
    float turn_meter;
};


class TurnManager {
    private:
        std::vector<Turn> turn_order;
        const float TURN_THRESHOLD = 1000.0f;
    public:
        Entity* next_turn();
        TurnManager(std::vector<Entity*>& list);
        void display_turn_meter();
};

#endif