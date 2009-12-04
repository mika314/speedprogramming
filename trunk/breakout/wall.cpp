#include "wall.hpp"
#include "ball.hpp"

Wall::Wall()
{
  for (int row = 0; row < 8; ++row)
    for (int col = 0; col < COLS_COUNT; ++col)
      bricks_.push_back(Brick(col, row));
}

void Wall::draw(Painter &p) const
{
  for (Bricks::const_iterator i = bricks_.begin(); 
       i != bricks_.end(); ++i)
    i -> draw(p);
}

Force Wall::tick(const Ball &ball)
{
  Force result(0, 0);
  if (1 - ball.x() > 0)
    result += Force(1 - ball.x(), 0);
  if (WIDTH - ball.x() -1 < 0)
    result += Force(WIDTH - ball.x() -1, 0);
  if (1 - ball.y() > 0)
    result += Force(0, 1 - ball.y());

  for (Bricks::iterator i = bricks_.begin(); 
       i != bricks_.end(); ++i)
  {
    Force f = i -> tick(ball);
    result += f;
    if (f.x != 0 || f.y != 0)
      i -> destroy();
  }

  return result;
}
