#include <stdlib.h>
#if defined(__APPLE__) || defined(MACOSX)
    #include <GLUT/glut.h>
#else
    #include <GL/glut.h>
#endif

#include "gamemanager.h"

#define SIXTY_FPS 1000.0/60.0


using namespace Micromachines;

GameManager manager;

void displayFunc();
void reshapeFunc(GLsizei w, GLsizei h);
void keyPressedFunc(unsigned char key, int x, int y);
void keyReleasedFunc(unsigned char key, int x, int y);
void specialKeyPressedFunc(int key, int x, int y);
void speciaKeyReleasedFunc(int key, int x, int y);
void idleFunc();
void timerFunc(int value);


int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(800, 562);
	//center window on a 1920x1280 screen (to see the console)
	glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH) - 990) / 2,
		(glutGet(GLUT_SCREEN_HEIGHT) - 640) / 2);

    glutCreateWindow("Micromachines");
	glEnable(GL_DEPTH_TEST);
    glutDisplayFunc(displayFunc);
    glutReshapeFunc(reshapeFunc);
    glutKeyboardFunc(keyPressedFunc);
    glutKeyboardUpFunc(keyReleasedFunc);
    glutSpecialFunc(specialKeyPressedFunc);
    glutSpecialUpFunc(speciaKeyReleasedFunc);
    glutIdleFunc(idleFunc);
	glutTimerFunc(SIXTY_FPS, timerFunc, 0);
    glutIgnoreKeyRepeat(1);

	manager.init();

    glutMainLoop();
    return 0;
}

void displayFunc()
{
    manager.display();
}

void reshapeFunc(GLsizei w, GLsizei h)
{
    manager.reshape(w,h);
}

void keyPressedFunc(unsigned char key, int x, int y)
{
    manager.keyPressed(key, x, y);
}

void keyReleasedFunc(unsigned char key, int x, int y)
{
    manager.keyReleased(key, x, y);
}

void specialKeyPressedFunc(int key, int x, int y)
{
    manager.specialKeyPressed(key, x, y);
}

void speciaKeyReleasedFunc(int key, int x, int y)
{
    manager.specialKeyReleased(key, x, y);
}

void idleFunc() {

}

void timerFunc(int value) {
    manager.update();
	glutTimerFunc(SIXTY_FPS, timerFunc, 0);
    glutPostRedisplay();
}
