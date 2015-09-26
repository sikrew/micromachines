#include <stdlib.h>

#if defined(__APPLE__) || defined(MACOSX)
    #include <GLUT/glut.h>
#else
    #include <GL/glut.h>
#endif

#include "gamemanager.h"

using namespace Micromachines;

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(800, 562);

    glutCreateWindow("Micromachines");


    glutMainLoop();
    return 0;
}

