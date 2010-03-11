#pragma once
#include "vector.hpp"

class Painter;

struct Star
{
    Star();
    void tick(Vector acel);
    void draw(Painter &) const;
    float vx;
    float vy;
    float x;
    float y;
};
