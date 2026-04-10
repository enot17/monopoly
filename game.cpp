#pragma once

#include "string"
#include "data.cpp"
#include "board.cpp"
#include "player.cpp"
#include "card.cpp"
#include "button.cpp"
#include "raylib.h"

using std::string;

constexpr int PLAYERS_COUNT = 2;
constexpr int BUTTON_COUNT = 1;
constexpr int CARDS_COUNT = 16;
Color playersColor[4] = {RED, BLUE, GREEN, YELLOW};


enum class GameState {
    begin, turn, card
};

class Game {
public:
    int turnNumber = 1;
    int activePlayerIndex = 0;
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
        buttons[0] = Button(inGameText[2], 800, 400, 105, 100, rollDiceClick);
        reset();
    }

    void update() {
        switch (gameState) {
            case GameState::begin:
                reset();
                break;
            case GameState::turn:
                turn();
                break;
        }
        input();
    }

    void draw() {
        Point p;
        drawInterface();
        board.draw();
        for (int i = 0; i < PLAYERS_COUNT; ++i) {
            players[i].draw(playersColor[i]);
        }
    }

    void reset(){
        for (int i = 0; i < PLAYERS_COUNT; ++i) {
            players[i].money = 1500;
            players[i].cellIndex = 0;
            players[i].number = i+1;
            getPlayerPlace(players[i]);
        }
    }

    void getPlayerPlace(Player &p) {
        
    }

    void drawInterface() {
        for (int i = 0; i < PLAYERS_COUNT; ++i) {
            DrawText(TextFormat("Player %i", players[i].number), 200, 100 + i * 100, 30, BLACK);
            DrawText(TextFormat("Money: %i", players[0].money), 200, 130 + i * 100, 30, BLACK);
        }
        DrawText(inGameText[0], 600, 100, 100, BLACK);
        DrawText(TextFormat("", inGameText[1]), 500, 250, 100, BLACK);
        for (int i = 0; i < BUTTON_COUNT; ++i) {
            buttons[i].draw();
        }
    }

    void input() {
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            DrawText("CLICK", 10, 50, 50, BLACK);
        }
    }

    void turn() {
        int dice1 = rollDice();
        int dice2 = rollDice();

    }

    int rollDice() {

    }

    void movePlayer(int moveLen) {

    }

    void takeCard() {

    }

    void nextPlayer() {
        if (activePlayerIndex > PLAYERS_COUNT) {
            activePlayerIndex = 0;
        }
    }

};