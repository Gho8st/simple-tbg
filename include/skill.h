#include <string>
#ifndef SKILL
#define SKILL

#include "skill_effect.h"
#include <vector>

class Skill {
    private:
        std::string id;
        std::vector<SkillEffect> effects;

    public:
        Skill(std::string id, std::vector<SkillEffect> effects);

        std::string get_name() const;
        std::vector<SkillEffect> get_effects();
        void print_skill();
};

#endif