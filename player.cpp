#pragma once
#include "raylib.h"

Color playersColor[4] = {RED,BLUE,GREEN,PINK};

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

class Computer : Player {
public:
};