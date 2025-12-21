#include "skill.h"

Skill::Skill(std::string id, std::vector<SkillEffect> effect) {
    this->id = id;
    this->effects = effect;
}

std::string Skill::get_name() const {return id;}
std::vector<SkillEffect> Skill::get_effects() {return effects;}

void Skill::print_skill() {
    printf("Name: %s\n", id.c_str());
    for(SkillEffect effect: effects) {
        effect.print_effect();
    }
}