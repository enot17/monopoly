#pragma once


#include "board.cpp"
#include "player.cpp"
#include "raylib.h"

enum class GameState{
    begin,turn1,turn2,turn3,turn4
};

class Game{
public:
    Board b;
    void update(){

    }

    void draw(){
        b.draw();
    }
};