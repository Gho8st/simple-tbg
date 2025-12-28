#ifndef STATE_MANAGER_H
#define STATE_MANAGER_H

#include <memory>
#include "game_state.h"

class StateManager {
    public:
        void change_state(std::unique_ptr<GameState> state);
        void update();
        void draw();

        bool has_state() const;

    private:
        std::unique_ptr<GameState> current;
};

#endif