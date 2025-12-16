#ifndef TEAM_H
#define TEAM_H

#include "entity.h"
#include <vector>
#include <string>

class Team {

    private:
        std::vector<Entity *> teammates;
        std::string id;

    public:
        Team(std::string name);

        void add_teammate(Entity& member);
        void print_status();
        bool if_alive() const;
        std::vector<Entity*> get_team(bool alive);
        Entity get_team_member(int index);

};

#endif