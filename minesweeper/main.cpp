#include "game.hpp"
#include "painter.hpp"
#include <GL/glut.h>

Game game;

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    game.draw();
    glutSwapBuffers();
}

void mouse(int button, int state, int x, int y)
{
    if (state == GLUT_UP)
    {
        switch (button)
        {
        case GLUT_LEFT_BUTTON:
            game.open(x / Painter::CELL_WIDTH, y / Painter::CELL_HEIGHT);
            break;
        case GLUT_RIGHT_BUTTON:
            game.mark(x / Painter::CELL_WIDTH, y / Painter::CELL_HEIGHT);
            break;
        }
        glutPostRedisplay();
    }
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(Game::WIDTH * Painter::CELL_WIDTH, Game::HEIGHT * Painter::CELL_HEIGHT);
    glutInitWindowPosition(100, 120);
    glutCreateWindow("MineSweeper");
    glClearColor(0, 0, 0, 1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, Game::HEIGHT * Painter::CELL_HEIGHT, Game::WIDTH * Painter::CELL_WIDTH, 0, -1.0, 1.0);
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutMainLoop();
}
