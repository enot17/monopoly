#pragma once


#include "board.cpp"
#include "player.cpp"
#include "card.cpp"
#include "raylib.h"


Color playersColor[4] = {RED, BLUE, GREEN, PINK};

enum class GameState {
    begin, turn1, turn2, turn3, turn4
};

class Game {
public:
    Card chance[16];
    Card chest[16];
    Board board;
    Player players[4];

    Game(){
        players[0] = Player();
        players[1] = Computer();
        players[2] = Computer();
        players[3] = Computer();
    }

    void update() {

    }

    void draw() {
        board.draw();
    }
};