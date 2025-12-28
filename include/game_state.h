#ifndef GAME_STATE_H
#define GAME_STATE_H

class GameState {
    public:
        virtual ~GameState() = default;

        virtual void update() = 0;
        virtual void draw() = 0;
};

#endif