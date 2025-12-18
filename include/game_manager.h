#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

#include "team.h"
#include "turn_manager.h"

enum Outcome {
    Player,
    Enemy,
    None
};

class GameManager {
    private:
        TurnManager* turnManager;
        Team* playerTeam;
        Team* enemyTeam;
        Outcome outcome = Outcome::None;

    public:
        GameManager(Team& player, Team& enemy);

        bool still_running() const;
        Outcome check_outcome();
        void play_turn();
};

#endif