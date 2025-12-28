#include "battle_state.h"
#include "state_manager.h"
#include "raylib.h"

BattleState::BattleState(StateManager& manager) : manager(manager) {

}

void BattleState::update() {

}

void BattleState::draw() {
    DrawText("Battle In Progress", 200, 200, 15, BLACK);
}