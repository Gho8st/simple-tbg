#include "game_manager.h"
#include <iostream>
#include <random>

int random_index(int length);

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

bool GameManager::if_player_turn() {
    return playerTeam->contains(current->get_name());
}

Entity& GameManager::get_current() {
    return *current;
}

void GameManager::next_turn() {
    current = turnManager->next_turn();
}

void GameManager::play_enemy_turn() {
    if (!enemyTeam->contains(current->get_name())) return;

    int position = random_index(playerTeam->get_team(true).size());
    Entity* targetEnemy = playerTeam->get_team_member(position-1, true);
    int dmg = targetEnemy->take_damage(current->get_attack());

    if (!playerTeam->if_alive()) outcome = Outcome::Enemy;
}

void GameManager::play_player_turn(int move, int target) {
    if (!playerTeam->contains(current->get_name())) return;

    if (move == 1) { // attack
        Entity* targetEnemy = enemyTeam->get_team_member(target-1, true);
        int dmg = targetEnemy->take_damage(current->get_attack());
    } else if (move == 2) { // heal
        Entity* targetAlly = playerTeam->get_team_member(target-1, true);
        targetAlly->heal(20);
    }

    if (!enemyTeam->if_alive()) outcome = Outcome::Player;
}

void GameManager::display_status() {playerTeam->print_status(false); enemyTeam->print_status(false);}
void GameManager::display_turn_order() {turnManager->display_turn_meter();}


Team& GameManager::get_player_team() {return *playerTeam;}
Team& GameManager::get_enemy_team() {return *enemyTeam;}

int random_index(int length) {
    std::random_device dev;
    std::mt19937 randomness_generator(dev());
    std::uniform_int_distribution<int> index_destribution(1, length);
    return index_destribution(randomness_generator);
}