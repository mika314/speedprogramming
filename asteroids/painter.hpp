#pragma once
#include "jet.hpp"
class Painter
{
public:
    void drawAsteroid(float x, float y, float size, float angle);
    void drawShip(float x, float y, float angle, Jet );
    void drawBullet(float x, float y);
};
