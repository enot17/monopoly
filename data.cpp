#pragma once

#include <string>
#include "board.cpp"

using std::string;

class Point {
public:
    Point() = default;

    int x = 0;
    int y = 0;
};

char *inGameText[] = {
        "Monopoly",
        "1 Player turn",
        "Roll Dice",
        "Turn"
};

char *chanceCardDescriptions = {

};

char *chestCardDescription = {

};

string cellNamesEng[CELL_COUNT] = {
        "Start",
        "Old Kent Road",
        "Community Chest",
        "Whitechapel Road",
        "Income Tax",
        "Kings Cross Station",
        "Islington",
        "Chance",
        "Easton Road",
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


