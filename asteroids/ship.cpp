#include "ship.hpp"
#include "painter.hpp"
#define _USE_MATH_DEFINES
#include <cmath>
#include "game.hpp"

Ship::Ship(): angel_(M_PI / 2)
{}

void Ship::tick(Keys keys)
{
    if (keys[KEY_LEFT])
        angel_ += 3.0f * Game::DELTA_T / 1000.0f;
    if (keys[KEY_RIGHT])
        angel_ -= 3.0f * Game::DELTA_T / 1000.0f;
    jet_[JET_FRONT] = keys[KEY_DOWN];
    jet_[JET_BACK] = keys[KEY_UP];
}

void Ship::draw(Painter &p) const
{
    p.drawShip(0, 0, angel_ * 180 / M_PI, jet_);
}

float Ship::angel() const
{
    return angel_;
}
