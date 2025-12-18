#include "turn_manager.h"
#include <cstdio>
#include <algorithm>

bool turn_cmp(const Turn& a, const Turn& b);

TurnManager::TurnManager(std::vector<Entity*>& list) {
    for (Entity* member: list) {
        Turn turn;
        turn.entity = member;
        float spd = member->get_speed();
        turn.turn_meter = spd;
        turn_order.push_back(turn);
    }
}


Entity* TurnManager::next_turn() {
    while(true) {
        // running on the track
        for (Turn& turn: turn_order) {
            if (!turn.entity->is_alive()) continue;
            turn.turn_meter += turn.entity->get_speed();
        }
        // checking who reached the destination
        Entity* best = nullptr;
        float highest_meter = -1.0f;
        for (Turn& turn: turn_order) {
            if (!turn.entity->is_alive()) continue;
            if (turn.turn_meter >= TURN_THRESHOLD && turn.turn_meter > highest_meter) {
                best = turn.entity;
                highest_meter = turn.turn_meter;
            }
        }

        if (best != nullptr) {
            for (Turn& turn: turn_order) {
                if (best->get_name() == turn.entity->get_name()) {
                    turn.turn_meter -= TURN_THRESHOLD;
                    return best;
                }
            }
        }
        
    }
}

void TurnManager::display_turn_meter() {
    std::vector<Turn> display = turn_order;
    std::sort(display.begin(), display.end(), turn_cmp);
    int i = 1;
    for(Turn turn: display) {
        printf("#%d: %.0f AV\n", i++, turn.turn_meter);
    }
}

bool turn_cmp(const Turn& a, const Turn& b) {
    return a.turn_meter > b.turn_meter;
}