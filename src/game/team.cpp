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
        printf("---- %s: HP: %d/%d, ATK: %d ", member->get_name().c_str(), member->get_health(), member->get_max_health(), member->get_effective_attack());
        if (!member->get_statuses().empty()) {
            printf("| Status: ");
            for(StatusEffect status: member->get_statuses()) {
                std::string effect;
                switch (status.get_type()) {
                    case StatusEffectType::Burn: 
                        effect = "Burn";
                        break;
                    case StatusEffectType::Poison:
                        effect = "Poison";
                        break;
                    case StatusEffectType::AttackUp:
                        effect = "Attack↑";
                        break;
                    case StatusEffectType::AttackDown:
                        effect = "Attack↓";
                        break;
                    case StatusEffectType::DefenseUp:
                        effect = "Defense↑";
                        break;
                    case StatusEffectType::DefenseDown:
                        effect = "Defense↓";
                        break;
                    case StatusEffectType::SpeedUp:
                        effect = "Speed↑";
                        break;
                    case StatusEffectType::SpeedDown:
                        effect = "Speed↓";
                        break;
                    default:
                        effect = "None";
                        break;
                }
                printf("%s(%d) ", effect.c_str(), status.get_turns());
            }
        }
        printf("\n");
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