#include "game.hpp"
#include "painter.hpp"

void Game::draw(Painter &p) const
{
  wall_.draw(p);
  ball_.draw(p);
  pedal_.draw(p);
}

void Game::setX(int x)
{
  pedal_.setX(x);
}
void Game::tick()
{
  Force f = wall_.tick(ball_);
  f += pedal_.tick(ball_);
  ball_.tick(f);
  if (ball_.y() > Wall::HEIGHT)
    ball_ = Ball();
}
