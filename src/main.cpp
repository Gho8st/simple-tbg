#include <iostream>
#include <cstdio>
#include "team.h"
using namespace std;

void print_status(Entity, Entity);

int main() {

    Entity player(100, 20, 5);
    Entity enemy(100, 15, 5);
    bool turn = true;
    int move = 0;

    Team player_team("Player");
    Team enemy_team("Enemy");

    player_team.add_teammate(player);
    enemy_team.add_teammate(enemy);

    cout << "Welcome to Simple TBG\n";
    while (player_team.if_alive() && enemy_team.if_alive()) {
        player_team.print_status();
        enemy_team.print_status();

        if(turn) {
            cout << "Now choose which option to use ur move...\n";
            cout << "1. Attack\n";
            cout << "2. Heal\n";
            cout << "... or Skip\n";
            cin >> move;
            if (move == 1) {
                int dmg = enemy.take_damage(player.get_attack());
                printf("Player attacks with %d damage\n", dmg);
                turn = !turn;
            } else if (move == 2) {
                player.heal(20);
                printf("Player heals with 20 health\n");
                turn = !turn;
            } else {
                turn = !turn;
            }
        } else {
            int dmg = player.take_damage(enemy.get_attack());
            printf("Enemy's turn..\nNow the enemy attacks with %d damage\n", dmg);
            turn = !turn;
        }
    }

    if (player.get_health() > 0)
        cout << "Player won\n";
    else
        cout << "Player lost\n";
    return 0;

}

void print_status(Entity p, Entity e) {
    printf("Player: %d HP, %d ATK\n", p.get_health(), p.get_attack());
    printf("Enemy: %d HP, %d ATK\n", e.get_health(), e.get_attack());
}