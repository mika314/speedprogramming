#include "asteroid.hpp"
#include "game.hpp"
#include "painter.hpp"
#include <cstdlib>

Asteroid::Asteroid(): angel_(rand() % 31400 / 1000.0f) {}

void Asteroid::tick(Vector acel)
{
    vx += acel.x * Game::DELTA_T / 1000.0f;
    vy += acel.y * Game::DELTA_T / 1000.0f;
    x += vx * Game::DELTA_T / 1000.0f;
    y += vy * Game::DELTA_T / 1000.0f;
    if (x > Game::WIDTH / 2)
        x -= Game::WIDTH;
    if (y > Game::HEIGHT / 2)
        y -= Game::HEIGHT;
    if (x < -Game::WIDTH / 2)
        x += Game::WIDTH;
    if (y < -Game::HEIGHT / 2)
        y += Game::HEIGHT;
    angel_ += 3.0f * Game::DELTA_T / 1000.0f;
}

void Asteroid::draw(Painter &p) const
{
    p.drawAsteroid(x, y, size, angel_);
}
