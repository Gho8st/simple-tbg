#ifndef SKILL_EFFECT
#define SKILL_EFFECT

#include "entity.h"

enum SkillType {
    Attack,
    Heal
};

class SkillEffect {
    private:
        SkillType type;
        int flat_value;
        float multiplier;

    public:
        SkillEffect(SkillType type, int flat = 0, float multi = 0.0f);
        void take_action(Entity& user, Entity& target);

        SkillType get_type();

};

#endif