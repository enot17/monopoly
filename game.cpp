#pragma once

#include "string"
#include "board.cpp"
#include "player.cpp"
#include "card.cpp"
#include "button.cpp"
#include "raylib.h"

using std::string;

constexpr int PLAYERS_COUNT = 2;
constexpr int BUTTON_COUNT = 1;
constexpr int CARDS_COUNT = 16;
Color playersColor[PLAYERS_COUNT] = {RED, BLUE};


string gameStrings[] = {
        "1 Player turn"
};


enum class GameState {
    begin, turn1, turn2
};

class Game {
public:
    Button buttons[BUTTON_COUNT];
    Card chanceCards[CARDS_COUNT];
    Card chestCards[CARDS_COUNT];
    Board board;
    Player players[PLAYERS_COUNT];
    GameState gameState = GameState::begin;

    Game() {
        // SetRandomSeed(0xaabbccff);
        players[0] = Player();
        players[1] = Computer();
        buttons[0] = Button("Roll Dice", 200, 200, 100, 100, rollDiceClick);

    }

    void update() {
        switch (gameState) {
            case GameState::begin:
                firstTurn();
                break;
            case GameState::turn1:
                turn(&players[0]);
                break;
            case GameState::turn2:
                turn(&players[1]);
                break;
        }
    }

    void draw() {
        board.draw();
        for (int i = 0; i < PLAYERS_COUNT; ++i) {
            players[i].draw(playersColor[i]);
        }
        for (int i = 0; i < BUTTON_COUNT; ++i) {
            buttons[i].draw();
        }
    }

    void firstTurn() {
        for (int i = 0; i < PLAYERS_COUNT; ++i) {
            players[i].money = 1500;
            players[i].cellIndex = 0;
        }
    }

    void turn(Player *p) {

    }
};