#include <iostream>
#include <random>
#include <ctime>
#include "gamemanager.h"
#include "orthogonalcamera.h"
#include "perspectivecamera.h"
#include "car.h"
#include "roadside.h"
#include "cheerio.h"
#include "butter.h"
#include "orange.h"

using namespace Micromachines;


float aspect;
//there's probably a better place to put this...
std::mt19937 rng(time(NULL));
std::uniform_real_distribution<float> gen(-2.f, 2.f);
std::uniform_real_distribution<float> gen2(0.f, 360.f);



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
}

void GameManager::reshape(GLsizei w, GLsizei h)
{
	aspect =  w / ((float) h);

    glViewport(0, 0, w, h);

	_activeCamera->computeProjectionMatrix();
	_activeCamera->computeVisualizationMatrix(aspect);


}

void GameManager::keyPressed(unsigned char key, int x, int y)
{

	switch (key) {
	case 'a':
		_car->toggleDrawSolidState();
		break;
	case '1':
		_activeCamera = _cameras[0];
		break;
	case '2':
		_activeCamera = _cameras[1];
		break;
	case '3':
		_activeCamera = _cameras[2];
		break;
	}
    
}

void GameManager::keyReleased(unsigned char key, int x, int y)
{

}

void GameManager::specialKeyPressed(int key, int x, int y)
{
    std::cout << "p";
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
    std::cout << "r";
    switch (key) {
        case GLUT_KEY_UP:
            _car->setAccState(NONE);
            break;
        case GLUT_KEY_DOWN:
            _car->setAccState(NONE);
            break;
        case GLUT_KEY_LEFT:
			if(_car->getLeanState() != RIGHT)
				_car->setLeanState(NOLEAN);
            break;
        case GLUT_KEY_RIGHT:
			if (_car->getLeanState() != LEFT)
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


	_cameras[2]->setPosition(_car->getPosition() + Vector3(-6.0f, 0.0f, 4.0f));

    for (int i = 0; i < 3; i++) //3 is NUM_ORANGES
		_orange[i]->update(deltaTime);

	_cameras[2]->setCameraCenter(Vector3(_car->getPosition().getX(), _car->getPosition().getY(), _car->getPosition().getZ()));

	_activeCamera->computeProjectionMatrix();
	_activeCamera->computeVisualizationMatrix(aspect);



    glutPostRedisplay();
}

void GameManager::init()
{
	int i;
	_car = new Car();


	//Ortho Camera

	Camera* orthogonalCamera = new OrthogonalCamera(-2., 2., -2., 2., -1., 1.);
	orthogonalCamera->setCameraUp(Vector3(0.0, 1.0, 0.0));
	orthogonalCamera->setCameraCenter(Vector3(0.0, 0.0, 1.0));
	_cameras.push_back(orthogonalCamera);

	//Fixed Perspective Camera	
	
	Camera* persp1 = new PerspectiveCamera(30.0f, 0.1f, 100.0f);
	persp1->setCameraUp(Vector3(0.0f, 0.0f, 1.0f));
	persp1->setCameraCenter(Vector3(0.0f, 0.0f, 0.0f));
	persp1->setPosition(Vector3(0.0f, -8.0f, 8.0f));
	_cameras.push_back(persp1);

	//Moving Perspective Camera	

	Camera* persp2 = new PerspectiveCamera(30.0f, 0.1f, 100.0f);
	persp2->setCameraUp(Vector3(0.0f, 0.0f, 1.0f));
	persp2->setCameraCenter(Vector3(_car->getPosition().getX(), _car->getPosition().getY(), _car->getPosition().getZ()));
	persp2->setPosition(_car->getPosition() + Vector3(-6.0f, 0.0f, 2.0f));
	_cameras.push_back(persp2);

	_activeCamera = _cameras[0];
    
	_roadside = new Roadside();
			
	for (i = 0; i <= 24; i++) 
		_cheerio[i] = new Cheerio(Vector3(2.8f, -1.98 + i*0.165f, 0.01f));

	for (i = 0; i <= 18; i++) //right left
		_cheerio[i+25] = new Cheerio(Vector3(2.2f, -1.5 + i*0.165f, 0.01f));

	for (i = 0; i <= 25; i++) //left left
		_cheerio[i + 44] = new Cheerio(Vector3(-2.8f, -1.98 + i*0.165f, 0.01f));

	for (i = 0; i <= 18; i++)//left right
		_cheerio[i + 70] = new Cheerio(Vector3(-2.2f, -1.5 + i*0.165f, 0.01f));

	for (i = 0; i <= 24; i++) //bottom top
		_cheerio[i + 89] = new Cheerio(Vector3(-2.0 + i*0.168f, -1.95 + 3 * 0.154, 0.01f));

	for (i = 0; i <= 31; i++) //bottom-bottom
		_cheerio[i + 114] = new Cheerio(Vector3(-2.6 + i *0.168f, -2.445 + 3 * 0.154, 0.01f));

	for (i = 0; i <= 31; i++)//top top
		_cheerio[i + 146] = new Cheerio(Vector3(-2.6 + i*0.168f, 1.52 + 3 * 0.154, 0.01f));

	for (i = 0; i <= 24; i++) //top bottom
		_cheerio[i + 178] = new Cheerio(Vector3(-2.0 + i*0.168f, 1.0 + 3 * 0.154, 0.01f));
		
		

	_butter[0] = new Butter(new Vector3(2.0,1.8, 0.01));
	_butter[1] = new Butter(new Vector3(2.0, -1.8, 0.01));
	_butter[2] = new Butter(new Vector3(-2.0, -1.8, 0.01));
	_butter[3] = new Butter(new Vector3(-2.0, 1.8, 0.01));
	_butter[4] = new Butter(new Vector3(0.0, -1.65, 0.01));

	float x = gen(rng);
	float y = gen(rng);
	_orange[0] = new Orange(Vector3(x, y, 0.15f), gen2(rng));

	x = gen(rng);
	y = gen(rng);
	_orange[1] = new Orange(Vector3(x, y, 0.15f), gen2(rng));

	x = gen(rng);
	y = gen(rng);
	_orange[2] = new Orange(Vector3(x, y, 0.15f), gen2(rng));


	
	std::cout << _orange[0]->getDirection() << std::endl;
	std::cout << _orange[1]->getDirection() << std::endl;
	std::cout << _orange[2]->getDirection() << std::endl;




    _lastTime = 0;
}

void GameManager::drawFloor()
{

}
