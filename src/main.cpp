#include <iostream>
#include <cstdio>
#include <random>
#include "game_manager.h"
#include "skill.h"
using namespace std;


int main() {

    Entity warrior("Warrior",100, 20, 5,110);
    Entity tank("Tank",110, 15, 5,95);
    Entity healer("Healer",100, 10, 5,120);
    Entity globlin("Goblin", 100, 15, 5, 100);
    Entity mob("Mob", 100, 15, 5, 105);

    Team player_team("Player");
    Team enemy_team("Enemy");

    warrior.add_skill("Swipe");
    healer.add_skill("First Aid");

    player_team.add_teammate(warrior);
    player_team.add_teammate(tank);
    player_team.add_teammate(healer);
    enemy_team.add_teammate(globlin);
    enemy_team.add_teammate(mob);

    for (Entity* entity: player_team.get_team(false)) {
        entity->add_skill("Slash");
        entity->add_skill("Heal");
    }
    for (Entity* entity: enemy_team.get_team(false)) {
        entity->add_skill("Slash");
        entity->add_skill("Heal");
    }

    SkillEffect slash_effect(SkillType::Attack, 20);
    SkillEffect heal_effect(SkillType::Heal, 20);
    SkillEffect super_heal_effect(SkillType::Heal, 20);
    Skill slash("Slash", TargetType::Enemy, {slash_effect});
    Skill swipe("Swipe", TargetType::AOE_Enemy, {slash_effect});
    Skill heal("Heal", TargetType::Ally, {heal_effect});
    Skill first_aid("First Aid", TargetType::Self, {super_heal_effect});

    cout << "Welcome to Simple TBG\n";
    GameManager gameManager = GameManager(player_team, enemy_team, {slash, heal, swipe, first_aid});
    while (gameManager.still_running()) {
        gameManager.play_turn();
    }

    if (gameManager.check_outcome() == Outcome::Success)
        cout << "Player won\n";
    else
        cout << "Player lost\n";
    return 0;

}
