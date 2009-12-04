#include "painter.hpp"
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

void timer(int)
{
  game.tick();
  display();
  glutTimerFunc(1000, timer, 0);
}

void keyEvent(int key, int x, int y)
{
  switch (key)
  {
  case GLUT_KEY_LEFT:
    game.keyEvent(Game::LEFT);
    break;
  case GLUT_KEY_RIGHT:
    game.keyEvent(Game::RIGHT);
    break;
  case GLUT_KEY_UP:
    game.keyEvent(Game::UP);
    break;
  case GLUT_KEY_DOWN:
    game.keyEvent(Game::DOWN);
    break;
  }
  display();
}

int main(int argc, char **argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowSize(Well::WIDTH * 8, Well::HEIGHT * 8); 
  glutInitWindowPosition(100, 780);
  glutCreateWindow("Tetris");
  glClearColor(0, 0, 0, 1);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(0, Well::WIDTH * 8, 
	  Well::HEIGHT * 8, 0, 
	  -1.0, 1.0);
  glutDisplayFunc(display);
  timer(0);
  glutSpecialFunc(keyEvent);

  glutMainLoop();
}
