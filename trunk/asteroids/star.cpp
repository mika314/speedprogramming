#include "star.hpp"
#include "game.hpp"
#include "painter.hpp"
Star::Star(): vx(0), vy(0) {}

void Star::tick(Vector acel)
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
}

void Star::draw(Painter &p) const
{
    p.drawStar(x, y);
}
