#include "game_manager.h"
#include <iostream>
#include <random>

int random_index(std::vector<Entity*> list);

GameManager::GameManager(Team& player, Team& enemy) {
    playerTeam = &player;
    enemyTeam = &enemy;

    std::vector<Entity*> list = playerTeam->get_team(false);
    std::vector<Entity*> list2 = enemyTeam->get_team(false);
    list.insert(list.end(), list2.begin(), list2.end());
    turnManager = new TurnManager(list);
}

bool GameManager::still_running() const {
    return playerTeam->if_alive() && enemyTeam->if_alive();
}

Outcome GameManager::check_outcome() {
    return outcome;
}

void GameManager::play_turn() {
    playerTeam->print_status(false);
    enemyTeam->print_status(false);

    Entity* current = turnManager->next_turn();

    int move = -1;
    if(playerTeam->contains(current->get_name())) {
        std::cout << "Now choose which option to use ur move...\n";
        std::cout << "1. Attack\n";
        std::cout << "2. Heal\n";
        std::cout << "... or Skip\n";
        std::cin >> move;
        if (move == 1) {
            int target = 0;
            std::cout << "Now choose ur target...\n";
            enemyTeam->print_status(true);

            while(target < 1 || target > enemyTeam->get_team(true).size())
                std::cin >> target;
            Entity* targetEnemy = enemyTeam->get_team_member(target-1, true);
            int dmg = targetEnemy->take_damage(current->get_attack());
            printf("%s attacks %s with %d damage\n", current->get_name().c_str(), targetEnemy->get_name().c_str(),dmg);
        } else if (move == 2) {
            current->heal(20);
            printf("%s heals with 20 health\n", current->get_name().c_str());
        }

    } else {
        int position = random_index(playerTeam->get_team(true));
        Entity* targetEnemy = playerTeam->get_team_member(position, true);
        int dmg = targetEnemy->take_damage(current->get_attack());
        printf("Enemy's turn..\nNow %s attacks %s with %d damage\n", current->get_name().c_str(), targetEnemy->get_name().c_str(), dmg);
    }

    if (!playerTeam->if_alive()) outcome = Outcome::Enemy;
    if (!enemyTeam->if_alive()) outcome = Outcome::Player;
}

int random_index(std::vector<Entity*> list) {
    std::random_device dev;
    std::mt19937 randomness_generator(dev());
    std::uniform_int_distribution<int> index_destribution(0, list.size()-1);
    return index_destribution(randomness_generator);
}