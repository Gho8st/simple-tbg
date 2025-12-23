#ifndef STATUS_EFFECT_H
#define STATUS_EFFECT_H

enum StatusEffectType {
    Burn, Poison,
    AttackUp, AttackDown,
    DefenseUp, DefenseDown,
    SpeedUp, SpeedDown,
    None
};

class StatusEffect {
    private:
        StatusEffectType type;
        int turns;
        float value;
    public:
        StatusEffect(StatusEffectType type, int turns, float value);
        StatusEffectType get_type();
        int get_turns();
        void take_action();
        int get_value();
};

#endif