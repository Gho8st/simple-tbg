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

void Team::print_status(bool alive) {
    std::vector<Entity*> members = alive ? get_team(alive) : teammates;
    printf("-------- %s Team ---------\n", id.c_str());
    for (Entity* member: members) {
        printf("---- %s: HP: %d/%d, ATK: %d \n", member->get_name().c_str(), member->get_health(), member->get_max_health(), member->get_attack());
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
        if (e->is_alive()) return true;
    }
    return false;
}

bool Team::contains(std::string name) const {
    for (Entity* member : teammates)
        if (member->get_name() == name) return true;
    return false;
}

Entity* Team::get_team_member(int index, bool alive) {
    std::vector<Entity*> members = alive ? get_team(alive) : teammates;
    if (index < 0 || index > members.size())
        throw std::runtime_error("Index is out of bounds");
    else {
        return members[index];
    }
}