#ifndef SKILL_EFFECT
#define SKILL_EFFECT

#include "entity.h"
#include "status_effect.h"

enum SkillType {
    Attack,
    Heal,
    Debuff,
    Buff
};

class SkillEffect {
    private:
        SkillType type;
        int hits;
        int flat_value;
        float multiplier;
        StatusEffect status_effect;
    public:
        SkillEffect(SkillType type, int hits = 1, int flat = 0, float multi = 0.0f, StatusEffect effect = StatusEffect(StatusEffectType::None, 0, 0));
        void take_action(Entity& user, Entity& target);
        SkillType get_type();

};

#endif