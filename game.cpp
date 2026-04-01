#pragma once


#include "board.cpp"
#include "player.cpp"
#include "card.cpp"
#include "raylib.h"


constexpr int PLAYERS_COUNT = 4;
constexpr int CARDS_COUNT = 16;
Color playersColor[PLAYERS_COUNT] = {RED, BLUE, GREEN, PINK};

enum class GameState {
    begin, turn1, turn2, turn3, turn4
};

class Game {
public:
    Card chance[CARDS_COUNT];
    Card chest[CARDS_COUNT];
    Board board;
    Player players[PLAYERS_COUNT];
    GameState state = GameState::begin;

    Game(){
        // SetRandomSeed(0xaabbccff);
        players[0] = Player();
        players[1] = Computer();
        players[2] = Computer();
        players[3] = Computer();
    }

    void update() {

    }

    int getDice(){
        return GetRandomValue(1,6) + GetRandomValue(1,6);
    }

    void draw() {
        board.draw();
        for (int i = 0; i < PLAYERS_COUNT; ++i) {
            players[i].draw(playersColor[i]);
        }
    }
};