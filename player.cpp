#pragma once

#include "raylib.h"

constexpr int PLAYER_SIZE = 40;

class Player {
public:
    int money;
    int cellIndex = 0;

    Player() = default;

    void input(){

    }

    void update() {

    }

    void draw(Color &color) {
        DrawCircle(cellIndex - 0, cellIndex - 10, PLAYER_SIZE, color);
    }
};

class Computer : public Player {
public:
};