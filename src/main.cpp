#include <iostream>
#include <cstdio>
#include <random>
#include "game_manager.h"
using namespace std;


int main() {

    Entity warrior("Warrior",100, 20, 5,110);
    Entity tank("Tank",110, 15, 5,95);
    Entity healer("Healer",100, 10, 5,120);
    Entity globlin("Goblin", 100, 15, 5, 100);
    Entity mob("Mob", 100, 15, 5, 105);

    Team player_team("Player");
    Team enemy_team("Enemy");

    player_team.add_teammate(warrior);
    player_team.add_teammate(tank);
    player_team.add_teammate(healer);
    enemy_team.add_teammate(globlin);
    enemy_team.add_teammate(mob);

    cout << "Welcome to Simple TBG\n";
    GameManager gameManager = GameManager(player_team, enemy_team);

    while (gameManager.still_running()) {
        gameManager.next_turn();

        gameManager.display_status();
        gameManager.display_turn_order();
        
        Entity current = gameManager.get_current();
        std::cout << current.get_name().append("'s turn\n").c_str();
        if (gameManager.if_player_turn()) {
            int move = -1;
            std::cout << "Now choose which option to use ur move...\n";
            std::cout << "1. Attack\n";
            std::cout << "2. Heal\n";
            std::cout << "... or Skip\n";
            do {
                std::cin >> move;
            } while (move < 1 && move > 2);

            std::cout << "Now choose ur target\n";
            int target = -1;
            Team targetTeam = (move == 2) ? gameManager.get_player_team() : gameManager.get_enemy_team();
            targetTeam.print_status(true);
            do {
                std::cin >> target;
            } while (target < 0 && target > targetTeam.get_team(true).size());

            gameManager.play_player_turn(move, target);
        } else {
            gameManager.play_enemy_turn();
        }
    }

    if (gameManager.check_outcome() == Outcome::Player)
        cout << "Player won\n";
    else
        cout << "Player lost\n";
    return 0;

}
