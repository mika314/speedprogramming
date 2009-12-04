#include "tetromino.hpp"
#include "painter.hpp"

Tetromino::Tetromino(Name name): name_(name), 
				 angel_(0), 
				 x_(3),
				 y_(0) {}
void Tetromino::draw(Painter &p) const
{
  p.setColor(static_cast<Painter::Color>(name_));
  for (int y = 0; y < 4; ++y)
    for (int x = 0; x < 4; ++x)
      if (map(x, y))
	p.rect((x + x_) * 8 + 1, 
	       (y + y_) * 8 + 1,
	       (x + x_ + 1) * 8 - 1, 
	       (y + y_ + 1) * 8 - 1);
}

bool Tetromino::map(int x, int y) const
{
  static const char *SHAPES[] = 
    {
      "  8 " // I
      "  8 "
      "  8 "
      "  8 ", 

      "  8 " // J
      "  8 "
      " 88 "
      "    ", 

      " 8  " // L
      " 8  "
      " 88 "
      "    ", 

      "    " // O
      " 88 "
      " 88 "
      "    ", 

      "  8 " // S
      " 88 "
      " 8  "
      "    ", 

      " 8  " // Z
      " 88 "
      "  8 "
      "    ", 

      "    " // T
      " 888"
      "  8 "
      "    " 
    };
  static const struct 
  {
    int x, y;
  } ROTATE[][16] = {
    {
      { 0, 0 }, { 0, 1 }, { 0, 2 }, { 0, 3 }, 
      { 1, 0 }, { 1, 1 }, { 1, 2 }, { 1, 3 }, 
      { 2, 0 }, { 2, 1 }, { 2, 2 }, { 2, 3 }, 
      { 3, 0 }, { 3, 1 }, { 3, 2 }, { 3, 3 } 
    },
    {
      { 3, 0 }, { 2, 0 }, { 1, 0 }, { 0, 0 }, 
      { 3, 1 }, { 2, 1 }, { 1, 1 }, { 0, 1 }, 
      { 3, 2 }, { 2, 2 }, { 1, 2 }, { 0, 2 }, 
      { 3, 3 }, { 2, 3 }, { 1, 3 }, { 0, 3 } 
    },
    {
      { 3, 3 }, { 3, 2 }, { 3, 1 }, { 3, 0 }, 
      { 2, 3 }, { 2, 2 }, { 2, 1 }, { 2, 0 }, 
      { 1, 3 }, { 1, 2 }, { 1, 1 }, { 1, 0 }, 
      { 0, 3 }, { 0, 2 }, { 0, 1 }, { 0, 0 } 
    },
    {
      { 0, 3 }, { 1, 3 }, { 2, 3 }, { 3, 3 }, 
      { 0, 2 }, { 1, 2 }, { 2, 2 }, { 3, 2 }, 
      { 0, 1 }, { 1, 1 }, { 2, 1 }, { 3, 1 }, 
      { 0, 0 }, { 1, 0 }, { 2, 0 }, { 3, 0 } 
    }
  };
  return SHAPES[name_]
    [ROTATE[angel_][y * 4 + x].y * 4 +
     ROTATE[angel_][y * 4 + x].x] != ' ';
}

void Tetromino::move(int dx, int dy)
{
  x_ += dx;
  y_ += dy;
}

void Tetromino::rotate(Direction d)
{
  angel_ = (angel_ + d + 4) % 4;
}
