#include "debug_overlay.h"
#include "raylib.h"
#include "imgui.h"

void DebugOverlay::toggle() {
    open = !open;
}

bool DebugOverlay::is_open() {
    return open;
}

void DebugOverlay::update() {
    if(IsKeyPressed(KEY_F1)) {
        toggle();
    }
}

void DebugOverlay::draw() {
    
    ImGui::Begin("Debug Overlay", &open);
    ImGui::Text("This is the debug window");
    ImGui::End();
}