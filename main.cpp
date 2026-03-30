#include "raylib.h"
#include "game.cpp"

constexpr int SCREEN_W = CELL_W * 11;
constexpr int SCREEN_H = CELL_H * 11;

int main() {
    InitWindow(SCREEN_W, SCREEN_H, "Monopoly");
    SetTargetFPS(60);
    Game g;
    while (!WindowShouldClose()) {
        g.update();
        BeginDrawing();
        ClearBackground(WHITE);
        g.draw();
        EndDrawing();
    }
    CloseWindow();
    return 0;
}
