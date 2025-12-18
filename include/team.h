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
        void print_status(bool alive);
        bool if_alive() const;
        bool contains(std::string name) const;
        std::vector<Entity*> get_team(bool alive);
        Entity* get_team_member(int index, bool alive);

};

#endif