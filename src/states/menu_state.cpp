#include "menu_state.h"
#include "battle_state.h"
#include "state_manager.h"
#include "raylib.h"

MenuState::MenuState(StateManager& manager) : manager(manager) {

}

void MenuState::update() {
    if (IsKeyPressed(KEY_ENTER)) {
        manager.change_state(std::make_unique<BattleState>(manager));
    }
}

void MenuState::draw() {
    DrawText("TURN BASED GAME", 200, 200, 30, BLACK);
    DrawText("Press Enter to Battle", 200, 300, 30, BLACK);
}