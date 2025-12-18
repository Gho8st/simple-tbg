#include <iostream>
#include <cstdio>
#include <random>
#include "game_manager.h"
using namespace std;


int main() {

    Entity player("Player #1",100, 20, 5,110);
    Entity enemy("Enemy #1", 100, 15, 5, 100);

    Team player_team("Player");
    Team enemy_team("Enemy");

    player_team.add_teammate(player);
    enemy_team.add_teammate(enemy);

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
