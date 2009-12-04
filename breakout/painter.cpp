#include "painter.hpp"
#include <GL/gl.h>

void Painter::bar(int x1, int y1, int x2, int y2)
{
  glBegin(GL_QUADS);
  glVertex2f(x1, y1);
  glVertex2f(x2, y1);
  glVertex2f(x2, y2);
  glVertex2f(x1, y2);
  glEnd();
}

void Painter::ball(int x, int y)
{
  glBegin(GL_POLYGON);
  glVertex2f(x + 3, y);
  glVertex2f(x, y + 3);
  glVertex2f(x - 3, y);
  glVertex2f(x, y - 3);
  glEnd();
}

void Painter::setColor(Color color)
{
  static const struct
  {
    float r, g, b;
  } colors[] = 
      {
	{ 1, 1, 0 }, // yellow
	{ 0, 1, 0 }, // green
	{ 1, 0.5, 0 }, // orange
	{ 1, 0, 0 }, // red
	{ 1, 1, 1 }, // yellow
	{ 0, 0, 0 }, // black
      };
  glColor3f(colors[color].r, 
	    colors[color].g, 
	    colors[color].b);
}
