#pragma once
#include "vector.hpp"

class Painter;

class Asteroid
{
    float angel_;
public:
    Asteroid();
    void tick(Vector acel);
    void draw(Painter &) const;
    float vx;
    float vy;
    float x;
    float y;
    float size;
};
