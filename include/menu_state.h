#ifndef MENU_STATE_H
#define MENU_STATE_H

#include "game_state.h"

class StateManager;

class MenuState : public GameState {
    public:
        MenuState(StateManager& manager);

        void update() override;
        void draw() override;

    private:
        StateManager& manager;
};

#endif