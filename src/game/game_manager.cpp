#include "game_manager.h"
#include <iostream>
#include <random>
#include <algorithm>

int random_index(std::vector<Entity*> list);
int choose_action(Entity& current, bool random);
void print_skills(Entity& current);
Skill find_skill_at(Entity& current, std::vector<Skill>& list, int index);

GameManager::GameManager(Team& player, Team& enemy, std::vector<Skill> list) {
    playerTeam = &player;
    enemyTeam = &enemy;
    skill_list = list;

    std::vector<Entity*> list1 = playerTeam->get_team(false);
    std::vector<Entity*> list2 = enemyTeam->get_team(false);
    list1.insert(list1.end(), list2.begin(), list2.end());
    turnManager = new TurnManager(list1);
}

bool GameManager::still_running() const {
    return playerTeam->if_alive() && enemyTeam->if_alive();
}

Outcome GameManager::check_outcome() {
    return outcome;
}

void GameManager::play_turn() {
    playerTeam->print_status(false);
    enemyTeam->print_status(false);

    Entity* current = turnManager->next_turn();

    int move = -1, target = -1;
    // each skill is assumed to only have one effect for testing
    if(playerTeam->contains(current->get_name())) {
        std::cout << "Now choose which option to use ur move...\n";
        print_skills(*current);
        move = choose_action(*current, false);
        Skill chosen_skill = find_skill_at(*current, skill_list, move);
        
        if (chosen_skill.get_effects()[0].get_type() == SkillType::Attack) {
            std::cout << "Now choose who to attack...\n";
            enemyTeam->print_status(true);
            while (target < 1 || target > enemyTeam->get_team(true).size())
                std::cin >> target;
            Entity* chosen_target = enemyTeam->get_team_member(target-1, true);
            chosen_skill.get_effects()[0].take_action(*current, *chosen_target);
        } else {
            std::cout << "Now choose who to heal...\n";
            playerTeam->print_status(true);
            while (target < 1 || target > playerTeam->get_team(true).size())
                std::cin >> target;
            Entity* chosen_target = playerTeam->get_team_member(target-1, true);
            chosen_skill.get_effects()[0].take_action(*current, *chosen_target);
        }

    } else {
        move = choose_action(*current, true);
        Skill chosen_skill = find_skill_at(*current, skill_list, move);
        Team* chosen_team;
        if (chosen_skill.get_effects()[0].get_type() == SkillType::Attack) {
            chosen_team = playerTeam;
        } else {
            chosen_team = enemyTeam;
        }
        int position = random_index(chosen_team->get_team(true));
        Entity* target = chosen_team->get_team_member(position, true);
        chosen_skill.get_effects()[0].take_action(*current, *target);
    }

    if (!playerTeam->if_alive()) outcome = Outcome::Enemy;
    if (!enemyTeam->if_alive()) outcome = Outcome::Player;
}

int random_index(std::vector<Entity*> list) {
    std::random_device dev;
    std::mt19937 randomness_generator(dev());
    std::uniform_int_distribution<int> index_destribution(0, list.size()-1);
    return index_destribution(randomness_generator);
}

int choose_action(Entity& entity, bool random) {
    int action = -1, length = entity.get_skills().size();
    if (!random) {
        while (action < 1 || action > length) {
            std::cin >> action;
        }
    } else {
        std::random_device dev;
        std::mt19937 randomness_generator(dev());
        std::uniform_int_distribution<int> index_destribution(1, length);
        return index_destribution(randomness_generator);
    }
    return action;
}

Skill find_skill_at(Entity& current, std::vector<Skill>& list, int index) {
    std::string name = current.get_skills()[index-1];
    for (Skill skill: list) {
        if (skill.get_name() == name) return skill;
    }
    throw std::runtime_error("Index is out of bounds");
}

void print_skills(Entity& current) {
    int i = 1;
    printf("--- Choose skills ---\n");
    for (std::string skill: current.get_skills()) {
        printf(" #%d: %s\n", i++, skill.c_str());
    }
}