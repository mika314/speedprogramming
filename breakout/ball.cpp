#include "ball.hpp"
#include "painter.hpp"
#include "wall.hpp"

Ball::Ball(): x_(Wall::WIDTH / 2), 
	      y_(Wall::HEIGHT - 3), 
	      vx_(80), 
	      vy_(-80) {}

void Ball::draw(Painter &p) const
{
  p.setColor(Painter::WHITE);
  p.ball(x_, y_);
}

void Ball::tick(Force f)
{
  float x = f.x;
  float y = f.y;
  const float LIM = .2;
  if (x > LIM)
    x = LIM;
  if (x < -LIM)
    x = -LIM;
  if (y > LIM)
    y = LIM;
  if (y < -LIM)
    y = -LIM;

  vx_ += 20 * x;
  vy_ += 20 * y;
  x_ += vx_ * DT;
  y_ += vy_ * DT;
}
