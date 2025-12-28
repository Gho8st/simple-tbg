#ifndef BATTLE_STATE_H
#define BATTLE_STATE_H

#include "game_state.h"

class StateManager;

class BattleState : public GameState {
    public:
        BattleState(StateManager& manager);

        void update() override;
        void draw() override;

    private:
        StateManager& manager;
};

#endif