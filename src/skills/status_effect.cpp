#include "status_effect.h"
#include <algorithm>

StatusEffect::StatusEffect(StatusEffectType type, int turns, float value) {
    this->type = type;
    this->turns = turns;
    this->value = value;
}

StatusEffectType StatusEffect::get_type() {return type;}
int StatusEffect::get_turns() {return turns;}
int StatusEffect::get_value() {return value;}
void StatusEffect::take_action() {turns = std::max(0, turns - 1);}