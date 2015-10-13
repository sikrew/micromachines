#include <iostream>
#include "gamemanager.h"
#include "orthogonalcamera.h"
#include "car.h"

using namespace Micromachines;

GameManager::GameManager()
{
}

GameManager::~GameManager()
{

}

void GameManager::display()
{
	//drawFloor();

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    _car->draw();

    glFlush();
    glutSwapBuffers();

    glutPostRedisplay();
}

void GameManager::reshape(GLsizei w, GLsizei h)
{
    float aspect =  w / ((float) h);

    glViewport(0, 0, w, h);

	_activeCamera->computeProjectionMatrix();
	_activeCamera->computeVisualizationMatrix(aspect);

}

void GameManager::keyPressed(unsigned char key, int x, int y)
{

}

void GameManager::keyReleased(unsigned char key, int x, int y)
{

}

void GameManager::specialKeyPressed(int key, int x, int y)
{
    switch (key) {
        case GLUT_KEY_UP:
            _car->setAcceleration(_car->getMaxAbsSpeed()/10);
            break;
        case GLUT_KEY_DOWN:
            _car->setAcceleration(-(_car->getMaxAbsSpeed()/2));
            break;
        case GLUT_KEY_LEFT:
            _car->setLean(LEFT);
            break;
        case GLUT_KEY_RIGHT:
            _car->setLean(RIGHT);
            break;
    }
}

void GameManager::specialKeyReleased(int key, int x, int y)
{
    switch (key) {
        case GLUT_KEY_UP:
            _car->setAcceleration(0);
            break;
        case GLUT_KEY_DOWN:
            _car->setAcceleration(0);
            break;
        case GLUT_KEY_LEFT:
            _car->setLean(NOLEAN);
            break;
        case GLUT_KEY_RIGHT:
            _car->setLean(NOLEAN);
            break;
    }
}

void GameManager::onTimer()
{

}

void GameManager::idle()
{

}

void GameManager::update()
{
    int timeNow = glutGet(GLUT_ELAPSED_TIME);
    int deltaTime = timeNow - _lastTime;
    _lastTime = timeNow;

    _car->update(deltaTime);
}

void GameManager::init()
{
	Camera* orthogonalCamera = new OrthogonalCamera(-2., 2., -2., 2., -1., 1.);
	orthogonalCamera->setCameraUp(Vector3(0.0, 1.0, 0.0));
	orthogonalCamera->setCameraCenter(Vector3(0.0, 0.0, 1.0));
	_cameras.push_back(orthogonalCamera);

	_activeCamera = _cameras[0];
    _car = new Car();

    _lastTime = 0;
}

void GameManager::drawFloor()
{

}
