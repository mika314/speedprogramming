#pragma once
#include "snake.hpp"
#include "field.hpp"

class Painter;

class Game
{
public:
  void tick();
  void draw(Painter &) const;
  void keyEvent(Snake::Direction);
private:
  Field field_;
  Snake snake_;
};
