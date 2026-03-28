#pragma once

#include "raylib.h"

constexpr int FONT_SIZE = 30;
constexpr int BIG_FONT_SIZE = FONT_SIZE * 2;
constexpr int CELL_W = 75;
constexpr int CELL_H = CELL_W * 2;
constexpr int BIG_CELL_SIZE = CELL_W * 2;
constexpr int CELL_COUNT = 40;
constexpr int ROW_COUNT = 9;
constexpr int OPP_SIDE = CELL_W * (ROW_COUNT + 2);
constexpr int CELL_SIZE = CELL_W + CELL_H;

enum class CellType {
    none, start, chest, pay, station, utility, jail, chance, pr1 = 10, pr2, pr3, pr4, pr5, pr6, pr7, pr8
};

Color cellColors[] = {
        WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE,
        BROWN, SKYBLUE, PINK, ORANGE, RED, YELLOW, GREEN, BLUE
};

Color cellColorByCellType(CellType ct) {
    return cellColors[(int) ct];
}


class Board {
public:
    int prices[CELL_COUNT] = {
            140,
            160,
            200,
            180,
            0,
            180,
            200,
            0,
            220,
            0,
            220,
            240,
            200,
            260,
            260,
            150,
            280,
            0,
            300,
            300,
            0,
            320,
            200,
            0,
            350,
            100,
            400
    };

    CellType groups[CELL_COUNT] = {
            CellType::start,
            CellType::pr1,
            CellType::chest,
            CellType::pr1,
            CellType::pay,
            CellType::station,
            CellType::pr2,
            CellType::chance,
            CellType::pr2,
            CellType::pr2,
            CellType::jail,
            CellType::pr3,
            CellType::utility,
            CellType::pr3,
            CellType::pr3,
            CellType::station,
            CellType::pr4,
            CellType::chest,
            CellType::pr4,
            CellType::pr4,
            CellType::none,
            CellType::pr5,
            CellType::chance,
            CellType::pr5,
            CellType::pr5,
            CellType::station,
            CellType::pr6,
            CellType::pr6,
            CellType::utility,
            CellType::pr6,
            CellType::jail,
            CellType::pr7,
            CellType::pr7,
            CellType::chest,
            CellType::pr7,
            CellType::station,
            CellType::chance,
            CellType::pr8,
            CellType::pay,
            CellType::pr8
    };
    const char *names[CELL_COUNT] = {
            "START",
            "Old Kent Road",
            "Community Chest",
            "Whitechapel Road",
            "Income Tax",
            "Kings Cross Station",
            "Islington",
            "Chance",
            "Euston Road",
            "Pentonville Road",
            "Jail",
            "Pall Mall",
            "Electric Company",
            "Whitehall",
            "Northumrl Avenue",
            "Marylbone Station",
            "Bow Street",
            "Community Chest",
            "Marlborough Street",
            "Vine Street",
            "Parking",
            "Strand",
            "Chance",
            "Fleet Street",
            "Trafalgar Square",
            "Fenchurch Station",
            "Leicester Square",
            "Coventry Street",
            "Water Works",
            "Piccadilly",
            "Go To Jail",
            "Regent Street",
            "Oxford Street",
            "Community Chest",
            "Bond Street",
            "Liverpool Station",
            "Chance",
            "Park Lane",
            "Super Tax",
            "MayFair"
    };
    int owners[CELL_COUNT] = {0};


    void update() {
    }

    void draw() {
        int index = 0;
        DrawRectangleLines(OPP_SIDE, OPP_SIDE, CELL_H, CELL_H, BLACK);
        DrawText(TextFormat("%i",index++), OPP_SIDE + CELL_W - 50, OPP_SIDE + (CELL_H / 2 - FONT_SIZE), BIG_FONT_SIZE, BLACK);

        for (int i = 0; i < ROW_COUNT; i++) {
            DrawRectangleLines(BIG_CELL_SIZE + CELL_W * i, OPP_SIDE, CELL_W, CELL_H, RED);
            DrawRectangle(BIG_CELL_SIZE + CELL_W * i, OPP_SIDE, CELL_W, CELL_H, cellColorByCellType(groups[index]));
            DrawText(TextFormat("%i",index++), BIG_CELL_SIZE + CELL_W * i, OPP_SIDE + 20, FONT_SIZE, BLACK);
        }

        DrawRectangleLines(0, OPP_SIDE, CELL_H, CELL_H, BLACK);
        DrawText(TextFormat("%i",index++), 0, OPP_SIDE, BIG_FONT_SIZE, BLACK);

        for (int i = 1; i < ROW_COUNT; i++) {
            DrawRectangleLines(CELL_H + CELL_W * i, 0, CELL_W, CELL_H, PURPLE);
            DrawText(TextFormat("%i",index++), 0, OPP_SIDE - (CELL_W * i), FONT_SIZE, BLACK);
            DrawRectangle(CELL_W - 50, OPP_SIDE - (CELL_W * i), CELL_W, CELL_H, cellColorByCellType(groups[index]));
        }

        for (int i = 0; i < ROW_COUNT; i++) {
            DrawRectangleLines(0, CELL_H + CELL_W * i, CELL_H, CELL_W, BLACK);
        }
        for (int i = 0; i < ROW_COUNT; i++) {
            DrawRectangleLines(OPP_SIDE, CELL_H + CELL_W * i, CELL_H, CELL_W, BLUE);
        }


        DrawRectangleLines(0, 0, CELL_H, CELL_H, BLACK);

        DrawRectangleLines(0, OPP_SIDE, CELL_H, CELL_H, BLACK);
    }
};
