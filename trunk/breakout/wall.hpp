#pragma once
#include "force.hpp"
#include "brick.hpp"
#include <vector>

class Painter;
class Ball;

class Wall
{
public:
  enum { ROWS_COUNT = 16,
	 COLS_COUNT = 8 * 3 };
  enum { WIDTH = ROWS_COUNT * Brick::WIDTH,
	 HEIGHT = COLS_COUNT * Brick::HEIGHT };
  Wall();
  void draw(Painter &) const;
  Force tick(const Ball &);
public:
  typedef std::vector<Brick> Bricks;
  Bricks bricks_;
};
