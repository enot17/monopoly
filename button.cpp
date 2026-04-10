#pragma once

#include "raylib.h"


Color colors[2] = {PINK, GRAY};
constexpr int FONT_LEN = 10;
constexpr int PADDING = 10;

enum class State {
    normal, press
};

class Button {
public:
    bool visible = true;
    int x;
    int y;
    int w;
    int h;
    State state = State::normal;
    void (*click)(Player &p) = nullptr;
    char *name;

    Button() = default;

    Button(char *name, int x, int y, int w, int h, void (*click)(Player &p)) {
        this->name = name;
        this->x = x;
        this->y = y;
        this->w = w;
        this->h = h;
        this->click = click;
    };

    void draw() {
        DrawRectangle(x, y, w, h, colors[0]);
        DrawText(name, x + PADDING, y + PADDING, 20, BLACK);
    }

};


void rollDiceClick(Player &p) {
    int a = GetRandomValue(1, 6) + GetRandomValue(1, 6);
}