#include "raylib.h"
#include "board.cpp"


constexpr int SCREEN_W = CELL_W * 11;
constexpr int SCREEN_H = CELL_H * 11;

class Game {
public:
    Board b;

    Game(){}

    void update() {
        b.update();
    }

    void draw() {
        b.draw();
    }
};

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
