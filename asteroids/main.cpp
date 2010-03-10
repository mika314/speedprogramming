// game Asteroids
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

Keys keys;

void keyEvent(int key, int, int)
{
    switch (key)
    {
    case GLUT_KEY_LEFT:
        keys.set(KEY_LEFT);
        break;
    case GLUT_KEY_RIGHT:
        keys.set(KEY_RIGHT);
        break;
    case GLUT_KEY_DOWN:
        keys.set(KEY_DOWN);
        break;
    case GLUT_KEY_UP:
        keys.set(KEY_UP);
        break;
    }
}

void keyUpEvent(int key, int, int)
{
    switch (key)
    {
    case GLUT_KEY_LEFT:
        keys.reset(KEY_LEFT);
        break;
    case GLUT_KEY_RIGHT:
        keys.reset(KEY_RIGHT);
        break;
    case GLUT_KEY_DOWN:
        keys.reset(KEY_DOWN);
        break;
    case GLUT_KEY_UP:
        keys.reset(KEY_UP);
        break;
    }
}

void spaceEvent(unsigned char key, int, int)
{
    if (key == ' ')
        keys.set(KEY_FIRE);
}

void upSpaceEvent(unsigned char key, int, int)
{
    if (key == ' ')
        keys.reset(KEY_FIRE);
}

void timer(int = 0)
{
    static int t = 0;
    int d;
    do
    {
        int ct = glutGet(GLUT_ELAPSED_TIME);
        if (t == 0)
            t = ct;
        game.tick(keys);
        t += Game::DELTA_T;
        d = t - ct;
        if (d > 0)
            display();
    } while (d <= 0);
    glutTimerFunc(d, timer, 0);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(854, 480);
    glutInitWindowPosition(4, 570);
    glutCreateWindow("Asteroids");
    glClearColor(0, 0, 0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-Game::WIDTH / 2, Game::WIDTH / 2, -Game::HEIGHT / 2, Game::HEIGHT / 2, -1.0, 1.0);
    glutDisplayFunc(display);
    glutSpecialFunc(keyEvent);
    glutSpecialUpFunc(keyUpEvent);
    glutKeyboardFunc(spaceEvent);
    glutKeyboardUpFunc(upSpaceEvent);
    timer();
    
    glutMainLoop();
}
