#include "pedal.hpp"
#include "wall.hpp"
#include "painter.hpp"
#include "ball.hpp"

Pedal::Pedal(): x_(Wall::WIDTH / 2) {}

void Pedal::draw(Painter &p) const
{
  p.setColor(Painter::ORANGE);
  p.bar(x_ - WIDTH / 2, Wall::HEIGHT - 2, 
	 x_ + WIDTH - WIDTH / 2, Wall::HEIGHT);
}
Force Pedal::tick(const Ball &ball)
{
  float s = ball.x() - x_ + WIDTH / 2;
  if (s >= 0 && s < WIDTH && 
      Wall::HEIGHT - 3 - ball.y() < 0)
    return Force((Wall::HEIGHT - 3 - ball.y()) * (x_ - ball.x()) / WIDTH, 
		 Wall::HEIGHT - 3 - ball.y());
  else
    return Force(0, 0);
}
void Pedal::setX(int x)
{
  x_ = x;
}
