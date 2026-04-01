#pragma once

class Button {
public:
    int x;
    int y;
    int w;
    int h;

    void (*click)() = nullptr;

    Button() = default;

    Button(int x, int y, int w, int h, void (&click)()) : x(x), y(y), w(w), h(h), click(click) {};
};