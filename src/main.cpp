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
        gameManager.play_turn();
    }

    if (gameManager.check_outcome() == Outcome::Player)
        cout << "Player won\n";
    else
        cout << "Player lost\n";
    return 0;

}
