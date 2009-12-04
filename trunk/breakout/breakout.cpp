#include "painter.hpp"
#include "wall.hpp"
#include "game.hpp"
#include <GL/glut.h>

Game game;

void display()
{
  glClear(GL_COLOR_BUFFER_BIT);
  Painter p;
  game.draw(p);
  glutSwapBuffers();
}

void timer(int = 0)
{
  for (int i = 0; i < 1.0 / 25 / Ball::DT; ++i)
    game.tick();
  display();
  glutTimerFunc(1000 / 25, timer, 0);
}

void mouse(int x, int)
{
  game.setX(x);
}

int main(int argc, char **argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowSize(
		     Wall::WIDTH, 
		     Wall::HEIGHT);
  glutInitWindowPosition(100, 780);
  glutCreateWindow("Breakout");
  glClearColor(0, 0, 0, 1.0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(0, Wall::WIDTH, Wall::HEIGHT, 0, -1.0, 1.0);
  glutDisplayFunc(display);
  glutPassiveMotionFunc(mouse);
  timer();

  glutMainLoop();
}
