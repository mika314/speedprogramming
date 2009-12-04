#pragma once
#include <list>

class Field;

class Snake
{
public:
  enum Direction { LEFT, UP, RIGHT, DOWN };
  Snake();
  bool tick(Field &);
  void keyEvent(Direction);
private:
  typedef std::list<std::pair<int, int> > Blocks;
  Blocks blocks_;
  Direction direction_;
  Direction lastMove_;
};
