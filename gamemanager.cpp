#include <iostream>
#include "gamemanager.h"
#include "orthogonalcamera.h"
#include "car.h"
#include "roadside.h"
#include "cheerio.h"
#include "butter.h"
#include "orange.h"

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

	_roadside->draw();
	for (int x = 0; x <= 202; x++) {
		_cheerio[x]->draw();
	}
	for (int x = 0; x <= 4; x++) 
		_butter[x]->draw();
	for (int x = 0; x <= 2; x++)
		_orange[x]->draw();
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
    if (key == 'a') {
        _car->toggleDrawSolidState();
	}
}

void GameManager::keyReleased(unsigned char key, int x, int y)
{

}

void GameManager::specialKeyPressed(int key, int x, int y)
{
    switch (key) {
        case GLUT_KEY_UP:
            _car->setAccState(SPEEDING);
            break;
        case GLUT_KEY_DOWN:
            _car->setAccState(BRAKING);
            break;
        case GLUT_KEY_LEFT:
            _car->setLeanState(LEFT);
            break;
        case GLUT_KEY_RIGHT:
            _car->setLeanState(RIGHT);
            break;
    }
}

void GameManager::specialKeyReleased(int key, int x, int y)
{
    switch (key) {
        case GLUT_KEY_UP:
            _car->setAccState(NONE);
            break;
        case GLUT_KEY_DOWN:
            _car->setAccState(NONE);
            break;
        case GLUT_KEY_LEFT:
            _car->setLeanState(NOLEAN);
            break;
        case GLUT_KEY_RIGHT:
            _car->setLeanState(NOLEAN);
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
	int i;
	Camera* orthogonalCamera = new OrthogonalCamera(-2., 2., -2., 2., -1., 1.);
	orthogonalCamera->setCameraUp(Vector3(0.0, 1.0, 0.0));
	orthogonalCamera->setCameraCenter(Vector3(0.0, 0.0, 1.0));
	_cameras.push_back(orthogonalCamera);

	_activeCamera = _cameras[0];
    _car = new Car();
	_roadside = new Roadside();
	//_cheerio[0] = new Cheerio(new Vector3(2.8f, -1.98f, 0.2f));
	//_cheerio[1] = new Cheerio(new Vector3(-2.8f, -1.98f, 0.2f));

	for (i = 0; i <= 24; i++) 
		_cheerio[i] = new Cheerio(new Vector3(2.8f, -1.98 + i*0.165f, 0.2f));
		//_cheerio[i + 1] = new Cheerio(new Vector3(2.4f, -1.98 + i*0.07f, 0.2f));
		//_cheerio[i + 2] = new Cheerio(new Vector3(-2.8f, -1.98 + i*0.07f, 0.2f));
		//_cheerio[i + 3] = new Cheerio(new Vector3(-2.4f, -1.98 + i*0.07f, 0.2f));

	for (i = 25; i <= 43; i++)
		_cheerio[i] = new Cheerio(new Vector3(2.2f, -1.98 + (i - 22)*0.165f, 0.2f));

	for (i = 44; i <= 69; i++)
		_cheerio[i] = new Cheerio(new Vector3(-2.8f, -1.98 + (i-44)*0.165f, 0.2f));

	for (i = 70; i <= 88; i++)
		_cheerio[i] = new Cheerio(new Vector3(-2.2f, -1.98 + (i - 67)*0.165f, 0.2f));

	for (i = 89; i <= 113; i++)
		_cheerio[i] = new Cheerio(new Vector3(-2.2+(i-88)*0.168f, -1.95+3*0.154, 0.2f));

	for (i = 114; i <= 145; i++)
		_cheerio[i] = new Cheerio(new Vector3(-2.8 + (i - 113)*0.168f, -2.445 + 3 * 0.154, 0.2f));

	for (i = 146; i <= 177; i++)
		_cheerio[i] = new Cheerio(new Vector3(-2.8 + (i - 145)*0.168f, 1.52 + 3 * 0.154, 0.2f));

	for (i = 178; i <= 202; i++)
		_cheerio[i] = new Cheerio(new Vector3(-2.2 + (i - 177)*0.168f, 1.05 + 3 * 0.154, 0.2f));

		_butter[0] = new Butter(new Vector3(2.0,1.8,0.0));
		_butter[1] = new Butter(new Vector3(2.0, -1.8, 0.0));
		_butter[2] = new Butter(new Vector3(-2.0, -1.8, 0.0));
		_butter[3] = new Butter(new Vector3(-2.0, 1.8, 0.0));
		_butter[4] = new Butter(new Vector3(0.0, -1.8, 0.0));

		_orange[0] = new Orange(new Vector3(2.4f, 0.0f, 0.0f));
		_orange[1] = new Orange(new Vector3(-2.4f, 0.0f, 0.0f));
		_orange[2] = new Orange(new Vector3(1.0f, 1.8f, 0.0f));



	std::cout << i << std::endl;




    _lastTime = 0;
}

void GameManager::drawFloor()
{

}
