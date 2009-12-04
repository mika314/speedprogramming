#pragma once

class Painter;

class Field
{
public:
  enum { WIDTH = 20, HEIGHT = 20 };
  enum { BLOCK_WIDTH = 10, BLOCK_HEIGHT = 10 };
  enum Type { EMPTY, SNAKE_BLOCK, FRUIT };
  Field();
  void setBlock(Type type, int x, int y);
  Type block(int x, int y) const;
  void draw(Painter &) const;
  void newFruit();
private:
  Type m_[HEIGHT][WIDTH];
};
