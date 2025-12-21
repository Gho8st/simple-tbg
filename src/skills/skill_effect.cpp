#include "skill_effect.h"

SkillEffect::SkillEffect(SkillType type, int flat, float multi) {
    this->type = type;
    flat_value = flat;
    multiplier = multi;
}

void SkillEffect::take_action(Entity& user, Entity& target) {
    if (type == SkillType::Attack) {
        int dmg = (user.get_attack() * multiplier) + flat_value;
        int value = target.take_damage(dmg);
        std::printf("%s attacks %s with %d dmg.\n", user.get_name().c_str(), target.get_name().c_str(), value);
    } else {
        int final_heal = (user.get_health() * multiplier) + flat_value;
        int value = target.heal(final_heal);
        std::printf("%s heals %s with %d HP.\n", user.get_name().c_str(), target.get_name().c_str(), value);
    }
}

SkillType SkillEffect::get_type() {return type;}

void SkillEffect::print_effect() {
    std::string name_type;
    switch (type) {
        case SkillType::Attack:
            name_type = "Attack";
            break;
        case SkillType::Heal:
            name_type = "Heal";
            break;
        default:
            name_type = "Unknown";
            break;
    }

    std::printf("--- Type: %s | Flat: %d | Multi %.2f ---\n", name_type.c_str(), flat_value, multiplier);
}