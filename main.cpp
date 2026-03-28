#include "raylib.h"
#include "data.cpp"
#include "board.cpp"


constexpr int SCREEN_W = CELL_W * 13;
constexpr int SCREEN_H = CELL_W * 13;

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
