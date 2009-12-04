#pragma once
#include "ball.hpp"
#include "wall.hpp"
#include "pedal.hpp"

class Game
{
public:
  void draw(Painter &) const;
  void setX(int x);
  void tick();
private:
  Ball ball_;
  Wall wall_;
  Pedal pedal_;
};
