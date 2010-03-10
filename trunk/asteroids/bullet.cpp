#include "bullet.hpp"
#include "game.hpp"
#include "painter.hpp"

Bullet::Bullet(): live(0) {}

void Bullet::tick(Vector acel)
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
    live += Game::DELTA_T;
}

void Bullet::draw(Painter &p) const
{
    p.drawBullet(x, y);
}
