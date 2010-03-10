#include <GL/glut.h>
#include "painter.hpp"
#define _USE_MATH_DEFINES
#include <cmath>

void Painter::drawAsteroid(float x, float y, float size, float angle)
{
    glPushMatrix();
    glTranslatef(x, y, 0);
    glScalef(size, size, 1);
    glRotatef(angle, 0, 0, 1);
    glColor3f(0.5, 0.5, 0.5);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 5; ++i)
        glVertex2f(sin(2 * M_PI / 5 * i), cos(2 * M_PI / 5 * i));
    glEnd();
    glPopMatrix();
}

void Painter::drawShip(float x, float y, float angle, Jet state)
{
    glPushMatrix();
    glTranslatef(x, y, 0);
    glRotatef(angle - 90, 0, 0, 1);
    glColor3f(0, 1, 0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(0, 20);
    glVertex2f(10, -10);
    glVertex2f(0, 0);
    glVertex2f(-10, -10);
    glEnd();
    glColor3f(1, 0, 0);
    if (state[JET_FRONT])
    {
        glBegin(GL_LINES);
        glVertex2f(0, 20);
        glVertex2f(0, 30);
        glEnd();
    }
    if (state[JET_BACK])
    {
        glBegin(GL_LINES);
        glVertex2f(0, 0);
        glVertex2f(0, -10);
        glEnd();
    }
    glPopMatrix();
}

void Painter::drawBullet(float x, float y)
{
    glPushMatrix();
    glTranslatef(x, y, 0);
    glPointSize(3);
    glColor3f(1, 0, 1);
    glBegin(GL_POINTS);
    glVertex2f(0, 0);
    glEnd();
    glPointSize(1);
    glPopMatrix();
}
