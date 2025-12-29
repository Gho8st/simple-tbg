#include <iostream>
#include <cstdio>
#include "raylib.h"
#include "rlImGui.h"
#include "imgui.h"
#include "debug_overlay.h"

using namespace std;

class Entity {
    public:
        int health;
        int attack;

        Entity(int h, int a) {
            health = h;
            attack = a;
        }
};

void print_status(Entity, Entity);

int main(int argc, char *argv[]) {

    if (argc < 2 || argc > 2) {
        cout << "Invalid arguments given";
        return 1;
    }

    int arg = atoi(argv[1]);

    if (arg == 0) {
        Entity player(100, 15);
        Entity enemy(100, 10);
        bool turn = true;
        int move = 0;

        cout << "Welcome to Simple TBG\n";
        while (player.health > 0 &&  enemy.health > 0) {
            print_status(player, enemy);

            if(turn) {
                cout << "Now choose which option to use ur move...\n";
                cout << "1. Attack\n";
                cout << "2. Heal\n";
                cout << "... or Skip\n";
                cin >> move;
                if (move == 1) {
                    printf("Player attacks with %d damage\n", player.attack);
                    enemy.health -= player.attack;
                    turn = !turn;
                } else if (move == 2) {
                    printf("Player heals with 20 health\n");
                    player.health = min(100, player.health + 20);
                    turn = !turn;
                } else {
                    turn = !turn;
                }
            } else {
                printf("Enemy's turn..\nNow the enemy attacks with %d damage\n", enemy.attack);
                player.health -= enemy.attack;
                turn = !turn;
            }
        }

        if (player.health > 0)
            cout << "Player won\n";
        else
            cout << "Player lost\n";
    } else if (arg == 1) {
        InitWindow(800, 600, "Turn Based Game");
        SetTargetFPS(60);

        rlImGuiSetup(true);
        DebugOverlay debugOverlay;

        while (!WindowShouldClose()) {
            BeginDrawing();
            ClearBackground(WHITE);

            debugOverlay.update();

            rlImGuiBegin();
                if (debugOverlay.is_open()) debugOverlay.draw();
            rlImGuiEnd();


            EndDrawing();
        }

        rlImGuiShutdown();
        CloseWindow();
    } else {
        cout << "Not proper arguement given\n";
    }
    return 0;

}

void print_status(Entity p, Entity e) {
    printf("Player: %d HP, %d ATK\n", p.health, p.attack);
    printf("Enemy: %d HP, %d ATK\n", e.health, e.attack);
}