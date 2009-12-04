#include "painter.hpp"
#include "GL/gl.h"

void Painter::bar(int x1, int y1, int x2, int y2)
{
  glColor3f(0, 1, 0);
  glBegin(GL_QUADS);
  glVertex2f(x1, y1);
  glVertex2f(x2, y1);
  glVertex2f(x2, y2);
  glVertex2f(x1, y2);
  glEnd();
}

void Painter::circle(int x, int y, int radius)
{
  glColor3f(1, 0, 0);
  glBegin(GL_POLYGON);
  glVertex2f(x + radius, y);
  glVertex2f(x, y + radius);
  glVertex2f(x - radius, y);
  glVertex2f(x, y - radius);
  glEnd();
}
