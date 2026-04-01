#pragma once

#include "raylib.h"

constexpr int FONT_SIZE = 30;
constexpr int CELL_W = 160;
constexpr int CELL_H = CELL_W / 2;
constexpr int BIG_CELL_SIZE = CELL_W;
constexpr int CELL_COUNT = 40;
constexpr int ROW_COUNT = 9;
constexpr int OPP_W = CELL_W * ROW_COUNT + BIG_CELL_SIZE;
constexpr int OPP_H = CELL_H * (ROW_COUNT + 1);

enum class CellType {
    none, start, chest, pay, station, utility, jail, chance, pr1 = 10, pr2, pr3, pr4, pr5, pr6, pr7, pr8
};

Color cellColors[] = {
        WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE,
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
        //down right
        DrawRectangleLines(OPP_W, OPP_H, CELL_W, CELL_H, BLACK);
        DrawText(TextFormat("%i", index), OPP_W, OPP_H, FONT_SIZE, BLACK);
        //down
        for (int i = 1; i <= ROW_COUNT; i++) {
            index++;
            DrawRectangle(OPP_W - (CELL_W * i), OPP_H, CELL_W, CELL_H, cellColorByCellType(groups[index]));
            DrawRectangleLines(OPP_W - (CELL_W * i), OPP_H, CELL_W, CELL_H, BLACK);
            DrawText(TextFormat("%i", index), OPP_W - (CELL_W * i), OPP_H, FONT_SIZE, BLACK);
        }
        //down left
        index++;
        DrawRectangleLines(0, OPP_H, CELL_W, CELL_H, BLACK);
        DrawText(TextFormat("%i", index), 0, OPP_H, FONT_SIZE, BLACK);
        //left
        for (int i = 1; i <= ROW_COUNT; i++) {
            index++;
            DrawRectangle(0, OPP_H - (CELL_H * i), CELL_W, CELL_H, cellColorByCellType(groups[index]));
            DrawRectangleLines(0, OPP_H - (CELL_H * i), CELL_W, CELL_H, BLACK);
            DrawText(TextFormat("%i", index), 0, OPP_H - (CELL_H * i), FONT_SIZE, BLACK);
        }
        //up left
        index++;
        DrawRectangleLines(0, 0, CELL_W, CELL_H, BLACK);
        DrawText(TextFormat("%i", index), 0, 0, FONT_SIZE, BLACK);
        //up
        for (int i = 0; i < ROW_COUNT; i++) {
            index++;
            DrawRectangle(BIG_CELL_SIZE + CELL_W * i, 0, CELL_W, CELL_H, cellColorByCellType(groups[index]));
            DrawRectangleLines(BIG_CELL_SIZE + CELL_W * i, 0, CELL_W, CELL_H, BLACK);
            DrawText(TextFormat("%i", index), BIG_CELL_SIZE + CELL_W * i, 0, FONT_SIZE, BLACK);
        }
        //up right
        index++;
        DrawRectangleLines(OPP_W, OPP_H, CELL_W, CELL_H, BLACK);
        DrawText(TextFormat("%i", index), OPP_W, 0, FONT_SIZE, BLACK);
        //right
        for (int i = 1; i <= ROW_COUNT; i++) {
            index++;
            DrawRectangle(OPP_W, CELL_H * i, CELL_W, CELL_H, cellColorByCellType(groups[index]));
            DrawRectangleLines(OPP_W, CELL_H * i, CELL_W, CELL_H, BLACK);
            DrawText(TextFormat("%i", index), OPP_W, CELL_H * i, FONT_SIZE, BLACK);
        }
    }
};
