#ifndef STATUS_EFFECT_H
#define STATUS_EFFECT_H

enum StatusEffectType {
    Burn,
    Poison,
    None
};

class StatusEffect {
    private:
        StatusEffectType type;
        int turns;
        int value;
    public:
        StatusEffect(StatusEffectType type, int turns, int value);
        StatusEffectType get_type();
        int get_turns();
        void take_action();
        int get_value();
};

#endif