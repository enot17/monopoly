#pragma once

#include "raylib.h"

constexpr int PLAYER_SIZE = 40;

class Player {
public:
    int money = 1500;
    int cellIndex = 0;

    Player() = default;

    void update() {

    }

    void draw(Color &color) {
        DrawCircle(cellIndex - 0, cellIndex - 10, PLAYER_SIZE, color);
    }
};

class Computer : public Player {
public:
};