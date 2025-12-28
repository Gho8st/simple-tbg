#include "state_manager.h"

void StateManager::change_state(std::unique_ptr<GameState> state) {
    current = std::move(state);
}

void StateManager::update() {
    if (current) current->update();
}

void StateManager::draw() {
    if (current) current->draw();
}

bool StateManager::has_state() const {
    return current != nullptr;
}