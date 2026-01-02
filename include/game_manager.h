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

        Entity* current;

    public:
        GameManager(Team& player, Team& enemy);

        bool still_running() const;
        Outcome check_outcome();

        Entity& get_current();
        bool if_player_turn();

        void next_turn();
        void play_enemy_turn();
        void play_player_turn(int move, int target);

        Team& get_player_team();
        Team& get_enemy_team();

        void display_status();
        void display_turn_order();
};

#endif