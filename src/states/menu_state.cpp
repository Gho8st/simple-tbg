#include "menu_state.h"
#include "battle_state.h"
#include "state_manager.h"
#include "raylib.h"
#include "raygui.h"

MenuState::MenuState(StateManager& manager) : manager(manager) {

}

void MenuState::update() {

}

void MenuState::draw() {
    DrawText("TURN BASED GAME", 200, 200, 30, BLACK);
    Rectangle btn = { 300, 300, 200, 40 };

    if (GuiButton(btn, "Start Game")) {
        manager.change_state(std::make_unique<BattleState>(manager));
    }
}