#pragma once

class Game
{
public:
    enum { WIDTH = 9, HEIGHT = 9 };
    enum State { CLOSED, OPENED, FLAG };
    Game();
    void draw();
    void open(int x, int y);
    void mark(int x, int y);
private:
    struct Cell
    {
        State state;
        bool hasMine;
    };
    Cell field_[WIDTH][HEIGHT];
};
