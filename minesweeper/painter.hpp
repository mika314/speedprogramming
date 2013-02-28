#pragma once

class Painter
{
public:
    enum { CELL_WIDTH = 16, CELL_HEIGHT = 16 };
    void drawClosedField(int x, int y);
    void drawOpenedField(int x, int y, int minesAround);
    void drawFlag(int x, int y);
    void drawMine(int x, int y);
private:
    void drawOpenedField(int x, int y);
};
