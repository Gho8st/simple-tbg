#include <string>
#ifndef SKILL
#define SKILL

#include "skill_effect.h"
#include <vector>

enum TargetType {
    Enemy,
    Self,
    Ally,
    AOE_Ally,
    AOE_Enemy
};

class Skill {
    private:
        std::string id;
        std::vector<SkillEffect> effects;
        TargetType target;

    public:
        Skill(std::string id, TargetType target, std::vector<SkillEffect> effects);

        std::string get_name() const;
        std::vector<SkillEffect> get_effects();
        TargetType get_target();
        void print_skill();
};

#endif