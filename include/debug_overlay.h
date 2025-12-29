#ifndef DEBUG_OVERLAY_H
#define DEBUG_OVERLAY_H

class DebugOverlay {
    public:
        void toggle();
        void update();
        void draw();

        bool is_open();

    private:
        bool open = false;
};

#endif