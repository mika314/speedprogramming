#pragma once
#include "force.hpp"

class Painter;
class Ball;

class Pedal
{
public:
  enum { WIDTH = 32 };
  Pedal();
  void draw(Painter &) const;
  Force tick(const Ball &);
  void setX(int x);
private:
  int x_;
};
