#include "GL/freeglut.h"
#include "DrawFunctions.h"
#include "keyboardEvents.h"
#include <cmath>
#include <string>
#include <dos.h>
#include "constants.h"
#include "windows.h"
using namespace std;

void Lighting()
{
    float ambient[] = { 254.0 / 255, 227.0 / 255, 180.0 / 255, 1 };

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);

    glEnable(GL_COLOR_MATERIAL);
    glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
}

void renderScene()
{
    glClearColor(1, 1, 1, 0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    DrawChessboard();

    Sleep(3000/60);

    glutSwapBuffers();
    glutPostRedisplay();
    glFlush();
}

void Init()
{
    glClearColor(0, 0, 0, 0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluOrtho2D(0, 1ll * 8 * step, 0, 1ll * 8 * step);
    Lighting();
}

void ChangeSize(int w, int h)
{
    glutReshapeWindow(8 * step, 8 * step);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
    glutInitWindowPosition(700, 50);
    glutInitWindowSize(8 * step, 8 * step);
    glutCreateWindow("Chess");
    glutDisplayFunc(renderScene);
    glutReshapeFunc(ChangeSize);
    glutKeyboardFunc(keyPressed);
    glutKeyboardUpFunc(keyUp);
    Init();

    glEnable(GL_DEPTH_TEST);
    glutMainLoop();

    return 0;
}
