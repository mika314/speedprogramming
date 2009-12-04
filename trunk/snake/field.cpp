#include "field.hpp"
#include "painter.hpp"
#include <cstdlib>

Field::Field()
{
  for (int y = 0; y < HEIGHT; ++y)
    for (int x = 0; x < WIDTH; ++x)
      m_[y][x] = EMPTY;
  newFruit();
}

void Field::setBlock(Type type, int x, int y)
{
  m_[y][x] = type;
}

Field::Type Field::block(int x, int y) const
{
  return m_[y][x];
}
void Field::draw(Painter &p) const
{
  for (int y = 0; y < HEIGHT; ++y)
    for (int x = 0; x < WIDTH; ++x)
    {
      switch (m_[y][x])
      {
      case EMPTY:
	break;
      case SNAKE_BLOCK:
	p.bar(x * BLOCK_WIDTH, 
	      y * BLOCK_HEIGHT,
	      (x + 1) * BLOCK_WIDTH - 1, 
	      (y + 1) * BLOCK_HEIGHT - 1);
	break;
      case FRUIT:
	p.circle(x * BLOCK_WIDTH + BLOCK_WIDTH / 2,
		 y * BLOCK_HEIGHT + BLOCK_HEIGHT / 2, 
		 BLOCK_WIDTH / 2 - 1);
	break;
      }
    }
}

void Field::newFruit()
{
  int x;
  int y;
  do
  {
    x = rand() % WIDTH;
    y = rand() % HEIGHT;
  } while (block(x, y) != EMPTY);
  setBlock(FRUIT, x, y);
}
