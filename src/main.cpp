#include <iostream>
#include <cstdio>
#include <random>
#include "team.h"
#include "turn_manager.h"
using namespace std;

void print_status(Entity, Entity);
int random_index(vector<Entity*> list);

int main() {

    Entity player("Player #1",100, 20, 5,110);
    Entity enemy("Enemy #1", 100, 15, 5, 100);

    int move = -1;

    std::vector<Entity*> list;
    list.emplace_back(&player);
    list.emplace_back(&enemy);
    TurnManager turnManager(list);

    Team player_team("Player");
    Team enemy_team("Enemy");

    player_team.add_teammate(player);
    enemy_team.add_teammate(enemy);

    cout << "Welcome to Simple TBG\n";
    while (player_team.if_alive() && enemy_team.if_alive()) {
        player_team.print_status();
        enemy_team.print_status();

        Entity *current = turnManager.next_turn();

        if(player_team.contains(current->get_name())) {
            cout << "Now choose which option to use ur move...\n";
            cout << "1. Attack\n";
            cout << "2. Heal\n";
            cout << "... or Skip\n";
            cin >> move;
            if (move == 1) {
                int dmg = enemy.take_damage(current->get_attack());
                printf("Player attacks with %d damage\n", dmg);
            } else if (move == 2) {
                current->heal(20);
                printf("Player heals with 20 health\n");
            }
        } else {
            int position = random_index(player_team.get_team(true));
            int dmg = player_team.get_team_member(position)->take_damage(current->get_attack());
            printf("Enemy's turn..\nNow the enemy attacks with %d damage\n", dmg);
        }
    }

    if (player.get_health() > 0)
        cout << "Player won\n";
    else
        cout << "Player lost\n";
    return 0;

}

int random_index(vector<Entity*> list) {
    std::random_device dev;
    std::mt19937 randomness_generator(dev());
    std::uniform_int_distribution<int> index_destribution(0, list.size()-1);
    return index_destribution(randomness_generator);
}

void print_status(Entity p, Entity e) {
    printf("Player: %d HP, %d ATK\n", p.get_health(), p.get_attack());
    printf("Enemy: %d HP, %d ATK\n", e.get_health(), e.get_attack());
}