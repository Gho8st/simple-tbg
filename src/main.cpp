#include <iostream>
#include <cstdio>
#include <random>
#include "game_manager.h"
#include "skill.h"
using namespace std;


int main() {

    Entity warrior("Warrior",100, 20, 5,110);
    Entity tank("Tank",110, 15, 15,95);
    Entity healer("Healer",100, 10, 5,120);
    Entity mage("Mage", 100, 15, 5, 115);
    Entity globlin("Goblin", 100, 15, 5, 100);
    Entity mob("Mob", 100, 15, 5, 105);

    Team player_team("Player");
    Team enemy_team("Enemy");

    warrior.add_skill("Swipe");
    warrior.add_skill("Multi Slash");
    tank.add_skill("Ravage");
    healer.add_skill("First Aid");
    mage.add_skill("Fireball");

    player_team.add_teammate(warrior);
    player_team.add_teammate(tank);
    player_team.add_teammate(healer);
    player_team.add_teammate(mage);
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

    SkillEffect slash_effect(SkillType::Attack,1,  20);
    SkillEffect heal_effect(SkillType::Heal,1, 20);
    SkillEffect super_heal_effect(SkillType::Heal,1, 20);
    SkillEffect burn_mark(SkillType::Attack,1,  10);
    SkillEffect multi_hit(SkillType::Attack, 3, 20);
    SkillEffect burn(SkillType::Debuff,1,  10, 0.0f, StatusEffect(StatusEffectType::Burn, 2, 5));
    SkillEffect ravage(SkillType::Buff,1, 0, 0.0f, StatusEffect(StatusEffectType::AttackUp, 2, 1.5f));
  
    Skill slash("Slash", TargetType::Enemy, {slash_effect});
    Skill multi_slash("Multi Slash", TargetType::Enemy, {multi_hit});
    Skill fire_ball("Fireball", TargetType::Enemy, {burn_mark, burn});
    Skill swipe("Swipe", TargetType::AOE_Enemy, {slash_effect});
    Skill heal("Heal", TargetType::Ally, {heal_effect});
    Skill first_aid("First Aid", TargetType::Self, {super_heal_effect});
    Skill ravage_buff("Ravage", TargetType::Self, {ravage});

    cout << "Welcome to Simple TBG\n";
    GameManager gameManager = GameManager(player_team, enemy_team, {slash, heal, swipe, first_aid, fire_ball, ravage_buff, multi_slash});
    while (gameManager.still_running()) {
        gameManager.play_turn();
    }

    if (gameManager.check_outcome() == Outcome::Success)
        cout << "Player won\n";
    else
        cout << "Player lost\n";
    return 0;

}
