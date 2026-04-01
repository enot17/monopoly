#pragma once


class Card {
public:
    char *description = nullptr;

    void (*action)(Player &p) = nullptr;

    Card() = default;

    Card(char *str, void (*act)(Player &p)) {
        description = str;
        action = act;
    }
};