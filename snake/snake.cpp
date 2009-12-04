#include "snake.hpp"
#include "field.hpp"
#include <cstdlib>

Snake::Snake(): 
  direction_(static_cast<Direction>(rand() % 4))
{
  blocks_.push_back(std::pair<int, int>
		    (Field::WIDTH / 2,
		     Field::HEIGHT / 2));
}

bool Snake::tick(Field &field)
{
  std::pair<int, int> p = blocks_.front();
  switch (direction_)
  {
  case LEFT:
    p.first--;
    break;
  case UP:
    p.second--;
    break;
  case RIGHT:
    p.first++;
    break;
  case DOWN:
    p.second++;
    break;
  }
  if (p.first < 0 || 
      p.first >= Field::WIDTH ||
      p.second < 0 || 
      p.second >= Field::HEIGHT)
    return false;
  if (field.block(p.first, p.second) == 
      Field::SNAKE_BLOCK)
    return false;
  blocks_.push_front(p);
  if (field.block(p.first, p.second) != 
      Field::FRUIT)
  {
    field.setBlock(Field::SNAKE_BLOCK, p.first, p.second);
    std::pair<int, int> p = blocks_.back();
    field.setBlock(Field::EMPTY, p.first, p.second);
    blocks_.pop_back();
  }
  else
  {
    field.setBlock(Field::SNAKE_BLOCK, p.first, p.second);
    field.newFruit();
  }
  if (blocks_.size() >= Field::WIDTH * Field::HEIGHT)
    return false;
  return true;    
}

void Snake::keyEvent(Direction d)
{
  if (d == direction_)
    return;
  switch (d)
  {
  case LEFT:
    if (direction_ == RIGHT)
      return;
    break;
  case UP:
    if (direction_ == DOWN)
      return;
    break;
  case RIGHT:
    if (direction_ == LEFT)
      return;
    break;
  case DOWN:
    if (direction_ == UP)
      return;
    break;
  }
  direction_ = d;
}
