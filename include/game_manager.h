#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

#include "team.h"
#include "turn_manager.h"
#include "skill.h"

enum Outcome {
    Failure,
    Success,
    None
};

class GameManager {
    private:
        TurnManager* turnManager;
        Team* playerTeam;
        Team* enemyTeam;
        Outcome outcome = Outcome::None;
        std::vector<Skill> skill_list;

    public:
        GameManager(Team& player, Team& enemy, std::vector<Skill> skill_list);

        bool still_running() const;
        Outcome check_outcome();
        void play_turn();
};

#endif