#ifndef STATE_MANAGER_H
#define STATE_MANAGER_H

#include <memory>
#include <vector>
#include "game_state.h"

class StateManager {
    public:
        void replace(std::unique_ptr<GameState> state);
        void push(std::unique_ptr<GameState> state);
        void pop();

        void update();
        void draw();

        bool empty() const;

    private:
        std::vector<std::unique_ptr<GameState>> stack;
};

#endif