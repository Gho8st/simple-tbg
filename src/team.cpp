#include "team.h"
#include <algorithm>
#include <stdexcept>
#include <cstdio>

Team::Team(std::string name) {
    id = name;
}

void Team::add_teammate(Entity& entity) {
    teammates.push_back(&entity);
}

void Team::print_status() {
    printf("-------- %s Team ---------\n", id.c_str());
    int i = 1;
    for (Entity* member: teammates) {
        printf("---- %d: HP: %d/%d, ATK: %d \n", i++, member->get_health(), member->get_max_health(), member->get_attack());
    }
    printf("--------  ---------\n");
}

std::vector<Entity*> Team::get_team(bool alive) {
    if (alive) {
        std::vector<Entity*> alive_mates;
        std::copy_if(teammates.begin(), teammates.end(), std::back_inserter(alive_mates), [](const Entity* e) {
            return e->is_alive();
        });
        return alive_mates;
    } else {
        return teammates;
    }
}

bool Team::if_alive() const{
    for (Entity* e: teammates) {
        if (!e->is_alive()) return false;
    }
    return true;
}

Entity Team::get_team_member(int index) {
    if (index < 1 || index > teammates.size())
        throw std::runtime_error("Index is out of bounds");
    else {
        Entity member = *teammates[index-1];
        return member;
    }
}