#pragma once
#include "raylib.h"

class Player {
public:
    int money = 1500;
    int cellIndex = 0;

    Player()=default;

    void update(){

    }

    void draw(){

    }


};

class Computer : public Player {
public:
};