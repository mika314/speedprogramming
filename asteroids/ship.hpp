#pragma once
#include "vector.hpp"
#include "keys.hpp"
#include "jet.hpp"

class Painter;

class Ship
{
private:
    float angel_;
    Jet jet_;
public:
    Ship();
    void tick(Keys );
    void draw(Painter &) const;
    float angel() const;
};
