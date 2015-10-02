#include <stdlib.h>

#if defined(__APPLE__) || defined(MACOSX)
    #include <GLUT/glut.h>
#else
    #include <GL/glut.h>
#endif

#include "gamemanager.h"


using namespace Micromachines;

GameManager manager;

void displayFunc();
void reshapeFunc(GLsizei w, GLsizei h);

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(800, 562);

    glutCreateWindow("Micromachines");

    glutDisplayFunc(displayFunc);
    glutReshapeFunc(reshapeFunc);
	manager.init();
    glutMainLoop();
    return 0;
}

void displayFunc()
{
    manager.display();
}

void reshapeFunc(GLsizei w, GLsizei h) {
    manager.reshape(w,h);
}
