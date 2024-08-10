#ifndef DRAWFIGURES_H_INCLUDED
#define DRAWFIGURES_H_INCLUDED
#include "constants.h"
#include "GL\freeglut.h"

void DrawPawn(char color, int x, int y)
{

    GLfloat offX = x * step;
    GLfloat offY = y * step;

    if (color == 'y')
        glColor3f((float)163 / 255, (float)158 / 255, 0.0f);
    else
        glColor3f(0.0f, 0.0f, 0.0f);

    glBegin(GL_POLYGON);
    glVertex2f(offX + 25, offY + 10);
    glVertex2f(offX + 40, offY + 40);
    glVertex2f(offX + 50, offY + 40);
    glVertex2f(offX + 65, offY + 10);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(offX + 35, offY + 40);
    glVertex2f(offX + 40, offY + 70);
    glVertex2f(offX + 50, offY + 70);
    glVertex2f(offX + 55, offY + 40);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(offX + 44, offY + 70);
    glVertex2f(offX + 42, offY + 80);
    glVertex2f(offX + 48, offY + 80);
    glVertex2f(offX + 46, offY + 70);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINE_LOOP);
    glVertex2f(offX + 25, offY + 10);
    glVertex2f(offX + 40, offY + 40);
    glVertex2f(offX + 35, offY + 40);
    glVertex2f(offX + 40, offY + 70);
    glVertex2f(offX + 44, offY + 70);
    glVertex2f(offX + 42, offY + 80);
    glVertex2f(offX + 48, offY + 80);
    glVertex2f(offX + 46, offY + 70);
    glVertex2f(offX + 50, offY + 70);
    glVertex2f(offX + 55, offY + 40);
    glVertex2f(offX + 50, offY + 40);
    glVertex2f(offX + 65, offY + 10);
    glEnd();

    glFlush();
}

void DrawCastle(char color, int x, int y)
{

    GLfloat offX = x * step;
    GLfloat offY = y * step;

    if (color == 'y')
        glColor3f((float)163 / 255, (float)158 / 255, 0.0f);
    else
        glColor3f(0.0f, 0.0f, 0.0f);

    glBegin(GL_POLYGON);
    glVertex2f(offX + 20, offY + 10);
    glVertex2f(offX + 20, offY + 20);
    glVertex2f(offX + 70, offY + 20);
    glVertex2f(offX + 70, offY + 10);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(offX + 30, offY + 20);
    glVertex2f(offX + 35, offY + 60);
    glVertex2f(offX + 55, offY + 60);
    glVertex2f(offX + 60, offY + 20);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(offX + 35, offY + 60);
    glVertex2f(offX + 20, offY + 70);
    glVertex2f(offX + 70, offY + 70);
    glVertex2f(offX + 55, offY + 60);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(offX + 20, offY + 70);
    glVertex2f(offX + 20, offY + 80);
    glVertex2f(offX + 30, offY + 80);
    glVertex2f(offX + 30, offY + 70);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(offX + 40, offY + 70);
    glVertex2f(offX + 40, offY + 80);
    glVertex2f(offX + 50, offY + 80);
    glVertex2f(offX + 50, offY + 70);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(offX + 60, offY + 70);
    glVertex2f(offX + 60, offY + 80);
    glVertex2f(offX + 70, offY + 80);
    glVertex2f(offX + 70, offY + 70);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINE_LOOP);
    glVertex2f(offX + 20, offY + 10);
    glVertex2f(offX + 20, offY + 20);
    glVertex2f(offX + 30, offY + 20);
    glVertex2f(offX + 35, offY + 60);
    glVertex2f(offX + 35, offY + 60);
    glVertex2f(offX + 20, offY + 70);

    glVertex2f(offX + 20, offY + 70);
    glVertex2f(offX + 20, offY + 80);
    glVertex2f(offX + 30, offY + 80);
    glVertex2f(offX + 30, offY + 70);
    glVertex2f(offX + 40, offY + 70);
    glVertex2f(offX + 40, offY + 80);
    glVertex2f(offX + 50, offY + 80);
    glVertex2f(offX + 50, offY + 70);
    glVertex2f(offX + 60, offY + 70);
    glVertex2f(offX + 60, offY + 80);
    glVertex2f(offX + 70, offY + 80);
    glVertex2f(offX + 70, offY + 70);

    glVertex2f(offX + 70, offY + 70);
    glVertex2f(offX + 55, offY + 60);
    glVertex2f(offX + 55, offY + 60);
    glVertex2f(offX + 60, offY + 20);
    glVertex2f(offX + 70, offY + 20);
    glVertex2f(offX + 70, offY + 10);
    glEnd();

    glFlush();
}

void DrawKnight(char color, int x, int y)
{

    GLfloat offX = x * step;
    GLfloat offY = y * step;

    if (color == 'y')
        glColor3f((float)163 / 255, (float)158 / 255, 0.0f);
    else
        glColor3f(0.0f, 0.0f, 0.0f);

    glBegin(GL_POLYGON);
    glVertex2f(offX + 28, offY + 10);
    glVertex2f(offX + 28, offY + 20);
    glVertex2f(offX + 62, offY + 20);
    glVertex2f(offX + 62, offY + 10);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(offX + 37, offY + 20);
    glVertex2f(offX + 32, offY + 30);
    glVertex2f(offX + 31, offY + 34);
    glVertex2f(offX + 43, offY + 58);
    glVertex2f(offX + 59, offY + 71);
    glVertex2f(offX + 65, offY + 54);
    glVertex2f(offX + 50, offY + 20);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(offX + 49, offY + 58);
    glVertex2f(offX + 29, offY + 57);
    glVertex2f(offX + 20, offY + 61);
    glVertex2f(offX + 30, offY + 68);
    glVertex2f(offX + 45, offY + 74);
    glVertex2f(offX + 59, offY + 71);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2f(offX + 53, offY + 73);
    glVertex2f(offX + 55, offY + 71);
    glVertex2f(offX + 57, offY + 77);
    glEnd();

    glLineWidth(1.5);
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINE_LOOP);
    glVertex2f(offX + 28, offY + 10);
    glVertex2f(offX + 28, offY + 20);
    glVertex2f(offX + 37, offY + 20);
    glVertex2f(offX + 32, offY + 30);
    glVertex2f(offX + 31, offY + 34);
    glVertex2f(offX + 43, offY + 58);
    glVertex2f(offX + 29, offY + 57);
    glVertex2f(offX + 20, offY + 61);
    glVertex2f(offX + 30, offY + 68);
    glVertex2f(offX + 45, offY + 74);
    glVertex2f(offX + 53, offY + 73);
    glVertex2f(offX + 55, offY + 71);
    glVertex2f(offX + 57, offY + 77);
    glVertex2f(offX + 59, offY + 71);
    glVertex2f(offX + 65, offY + 54);
    glVertex2f(offX + 50, offY + 20);
    glVertex2f(offX + 62, offY + 20);
    glVertex2f(offX + 62, offY + 10);
    glEnd();

    glFlush();
}

void DrawBishop(char color, int x, int y)
{

    GLfloat offX = x * step;
    GLfloat offY = y * step;

    if (color == 'y')
        glColor3f((float)163 / 255, (float)158 / 255, 0.0f);
    else
        glColor3f(0.0f, 0.0f, 0.0f);

    glBegin(GL_POLYGON);
    glVertex2f(offX + 20, offY + 10);
    glVertex2f(offX + 20, offY + 20);
    glVertex2f(offX + 70, offY + 20);
    glVertex2f(offX + 70, offY + 10);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(offX + 30, offY + 20);
    glVertex2f(offX + 16, offY + 30);
    glVertex2f(offX + 15, offY + 36);
    glVertex2f(offX + 18, offY + 44);
    glVertex2f(offX + 22, offY + 52);
    glVertex2f(offX + 33, offY + 59);

    glVertex2f(offX + 45, offY + 70);

    glVertex2f(offX + 57, offY + 59);
    glVertex2f(offX + 68, offY + 52);
    glVertex2f(offX + 72, offY + 44);
    glVertex2f(offX + 75, offY + 36);
    glVertex2f(offX + 74, offY + 30);
    glVertex2f(offX + 60, offY + 20);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(offX + 45, offY + 70);
    glVertex2f(offX + 48, offY + 73);
    glVertex2f(offX + 45, offY + 76);
    glVertex2f(offX + 42, offY + 73);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINE_LOOP);
    glVertex2f(offX + 20, offY + 10);
    glVertex2f(offX + 20, offY + 20);
    glVertex2f(offX + 30, offY + 20);
    glVertex2f(offX + 16, offY + 30);
    glVertex2f(offX + 15, offY + 36);
    glVertex2f(offX + 18, offY + 44);
    glVertex2f(offX + 22, offY + 52);
    glVertex2f(offX + 33, offY + 59);

    glVertex2f(offX + 45, offY + 70);
    glVertex2f(offX + 48, offY + 73);
    glVertex2f(offX + 45, offY + 76);
    glVertex2f(offX + 42, offY + 73);
    glVertex2f(offX + 45, offY + 70);

    glVertex2f(offX + 57, offY + 59);
    glVertex2f(offX + 68, offY + 52);
    glVertex2f(offX + 72, offY + 44);
    glVertex2f(offX + 75, offY + 36);
    glVertex2f(offX + 74, offY + 30);
    glVertex2f(offX + 60, offY + 20);
    glVertex2f(offX + 70, offY + 20);
    glVertex2f(offX + 70, offY + 10);
    glEnd();

    glFlush();
}

void DrawQueen(char color, int x, int y)
{

    GLfloat offX = x * step;
    GLfloat offY = y * step;

    if (color == 'y')
        glColor3f((float)163 / 255, (float)158 / 255, 0.0f);
    else
        glColor3f(0.0f, 0.0f, 0.0f);

    glBegin(GL_POLYGON);
    glVertex2f(offX + 25, offY + 10);
    glVertex2f(offX + 25, offY + 20);
    glVertex2f(offX + 29, offY + 30);
    glVertex2f(offX + 31, offY + 31);
    glVertex2f(offX + 40, offY + 32.5f);

    glVertex2f(offX + 42.5f, offY + 33.5f);
    glVertex2f(offX + 47.5f, offY + 33.5f);

    glVertex2f(offX + 50, offY + 32.5f);
    glVertex2f(offX + 59, offY + 31);
    glVertex2f(offX + 61, offY + 30);
    glVertex2f(offX + 65, offY + 20);
    glVertex2f(offX + 65, offY + 10);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2f(offX + 25, offY + 20);
    glVertex2f(offX + 10, offY + 52);
    glVertex2f(offX + 29, offY + 30);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2f(offX + 31, offY + 31);
    glVertex2f(offX + 27, offY + 67);
    glVertex2f(offX + 40, offY + 32.5f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2f(offX + 42.5f, offY + 33.5f);
    glVertex2f(offX + 45, offY + 80);
    glVertex2f(offX + 47.2f, offY + 33.5f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2f(offX + 50, offY + 32.5f);
    glVertex2f(offX + 63, offY + 67);
    glVertex2f(offX + 59, offY + 31);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2f(offX + 61, offY + 30);
    glVertex2f(offX + 80, offY + 52);
    glVertex2f(offX + 65, offY + 20);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINE_LOOP);
    glVertex2f(offX + 25, offY + 10);
    glVertex2f(offX + 25, offY + 20);
    glVertex2f(offX + 10, offY + 52);
    glVertex2f(offX + 29, offY + 30);
    glVertex2f(offX + 31, offY + 31);
    glVertex2f(offX + 27, offY + 67);
    glVertex2f(offX + 40, offY + 32.5f);
    glVertex2f(offX + 42.5f, offY + 35);
    glVertex2f(offX + 45, offY + 80);
    glVertex2f(offX + 47.5f, offY + 35);
    glVertex2f(offX + 50, offY + 32.5f);
    glVertex2f(offX + 63, offY + 67);
    glVertex2f(offX + 59, offY + 31);
    glVertex2f(offX + 61, offY + 30);
    glVertex2f(offX + 80, offY + 52);
    glVertex2f(offX + 65, offY + 20);
    glVertex2f(offX + 65, offY + 10);
    glEnd();

    glFlush();
}

void DrawKing(char color, int x, int y)
{

    GLfloat offX = x * step;
    GLfloat offY = y * step;

    if (color == 'y')
        glColor3f((float)163 / 255, (float)158 / 255, 0.0f);
    else
        glColor3f(0.0f, 0.0f, 0.0f);

    glBegin(GL_POLYGON);
    glVertex2f(offX + 25, offY + 10);
    glVertex2f(offX + 25, offY + 20);
    glVertex2f(offX + 65, offY + 20);
    glVertex2f(offX + 65, offY + 10);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(offX + 25, offY + 20);
    glVertex2f(offX + 20, offY + 25);
    glVertex2f(offX + 10, offY + 45);
    glVertex2f(offX + 4, offY + 60);
    glVertex2f(offX + 6, offY + 65);
    glVertex2f(offX + 8, offY + 70);
    glVertex2f(offX + 12, offY + 75);
    glVertex2f(offX + 22, offY + 77);
    glVertex2f(offX + 34, offY + 78.5f);

    glVertex2f(offX + 45, offY + 80);

    glVertex2f(offX + 56, offY + 78.5f);
    glVertex2f(offX + 68, offY + 77);
    glVertex2f(offX + 78, offY + 75);
    glVertex2f(offX + 82, offY + 70);
    glVertex2f(offX + 84, offY + 65);
    glVertex2f(offX + 86, offY + 60);
    glVertex2f(offX + 80, offY + 45);
    glVertex2f(offX + 70, offY + 25);
    glVertex2f(offX + 65, offY + 20);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(offX + 45, offY + 80);
    glVertex2f(offX + 49, offY + 83);
    glVertex2f(offX + 45, offY + 86);
    glVertex2f(offX + 41, offY + 83);
    glEnd();


    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINE_LOOP);
    glVertex2f(offX + 25, offY + 10);
    glVertex2f(offX + 25, offY + 20);
    glVertex2f(offX + 20, offY + 25);
    glVertex2f(offX + 10, offY + 45);
    glVertex2f(offX + 4, offY + 60);
    glVertex2f(offX + 6, offY + 65);
    glVertex2f(offX + 8, offY + 70);
    glVertex2f(offX + 12, offY + 75);
    glVertex2f(offX + 22, offY + 77);
    glVertex2f(offX + 34, offY + 78.5f);

    glVertex2f(offX + 45, offY + 80);
    glVertex2f(offX + 49, offY + 83);
    glVertex2f(offX + 45, offY + 86);
    glVertex2f(offX + 41, offY + 83);
    glVertex2f(offX + 45, offY + 80);

    glVertex2f(offX + 56, offY + 78.5f);
    glVertex2f(offX + 68, offY + 77);
    glVertex2f(offX + 78, offY + 75);
    glVertex2f(offX + 82, offY + 70);
    glVertex2f(offX + 84, offY + 65);
    glVertex2f(offX + 86, offY + 60);
    glVertex2f(offX + 80, offY + 45);
    glVertex2f(offX + 70, offY + 25);
    glVertex2f(offX + 65, offY + 20);
    glVertex2f(offX + 65, offY + 10);
    glEnd();

    glFlush();
}
#endif // DRAWFIGURES_H_INCLUDED
#pragma once
