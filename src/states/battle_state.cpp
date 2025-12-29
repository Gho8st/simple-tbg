#include "battle_state.h"
#include "state_manager.h"
#include "raylib.h"

BattleState::BattleState(StateManager& manager) : manager(manager) {

}

void BattleState::update() {
    if (IsKeyPressed(KEY_ESCAPE)) {
        manager.pop();
    }
}

void BattleState::draw() {
    DrawText("Battle In Progress", 200, 200, 15, BLACK);
}