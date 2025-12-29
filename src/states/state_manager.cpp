#include "state_manager.h"

void StateManager::push(std::unique_ptr<GameState> state) {
    stack.push_back(std::move(state));
}

void StateManager::pop() {
    stack.pop_back();
}

void StateManager::replace(std::unique_ptr<GameState> state) {
    pop();
    push(std::move(state));
}

void StateManager::update() {
    stack.back()->update();
}

void StateManager::draw() {
    stack.back()->draw();
}

bool StateManager::empty() const {
    return stack.empty();
}