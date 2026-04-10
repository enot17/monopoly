#pragma once

#include "raylib.h"

constexpr int PLAYER_SIZE = 10;

class Player {
public:
    Point place;
    int money;
    int number;
    int cellIndex;

    Player() = default;

    void update(Point &p) {
        place.x = p.x;
        place.y = p.y;
    }

    void draw(Color &color) {
        DrawCircle(place.x, place.y, PLAYER_SIZE, color);
    }

};

class Computer : public Player {
public:
};