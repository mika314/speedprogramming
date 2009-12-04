#pragma once
#include "force.hpp"

class Painter;
class Ball;

class Brick
{
public:
  enum { WIDTH = 20,
	 HEIGHT = 8 };
  Brick(int col, int row);
  void draw(Painter &) const;
  void destroy();
  Force tick(const Ball &);
private:
  int col_;
  int row_;
  int countDownTimer_;
};
