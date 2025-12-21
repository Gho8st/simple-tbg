#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

#include "team.h"
#include "turn_manager.h"
#include "skill.h"

enum Outcome {
    Failure,
    Success,
    NoOutcome
};

class GameManager {
    private:
        TurnManager* turnManager;
        Team* playerTeam;
        Team* enemyTeam;
        Outcome outcome = Outcome::NoOutcome;
        std::vector<Skill> skill_list;

        void use_skill(Entity& current, Entity& target, Skill& skill);

    public:
        GameManager(Team& player, Team& enemy, std::vector<Skill> skill_list);

        bool still_running() const;
        Outcome check_outcome();
        void play_turn();
};

#endif