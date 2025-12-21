#include "skill.h"

Skill::Skill(std::string id, TargetType target, std::vector<SkillEffect> effect) {
    this->id = id;
    this->effects = effect;
    this->target = target;
}

std::string Skill::get_name() const {return id;}
std::vector<SkillEffect> Skill::get_effects() {return effects;}
TargetType Skill::get_target() {return target;}