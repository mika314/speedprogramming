#pragma once

class Painter
{
public:
  enum Color { RED, WHITE, MAGENTA, DARK_BLUE, 
	       GREEN, BROWN, CYAN, BLACK };
  void rect(int x1, int y1, int x2, int y2);
  void setColor(Color);
};
