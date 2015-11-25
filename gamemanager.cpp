#include <iostream>
#include <random>
#include <ctime>
#include "gamemanager.h"
#include "orthogonalcamera.h"
#include "perspectivecamera.h"
#include "gameobject.h"
#include "dynamicobject.h"
#include "car.h"
#include "roadside.h"
#include "cheerio.h"
#include "butter.h"
#include "orange.h"
#include "lightsource.h"
#include "lightpoint.h"

using namespace Micromachines;


float aspect;
//there's probably a better place to put this...
std::mt19937 rng(time(NULL));
std::uniform_real_distribution<float> gen(-2.f, 2.f);
std::uniform_real_distribution<float> gen2(0.f, 360.f);
bool shade_smooth;

GameManager::GameManager()
{
}

GameManager::~GameManager()
{

}

void GameManager::display()
{

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    for(auto l : _lightpointList) {
        l->display();
    }

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
	case 'n':
		toggleLightswitch();
		break;
	case 'l':
		toggleLightingCalculation();
		break;
    case 'c':
        for(LightPoint *l : _lightpointList) {
            if(l->isEmitting())
                l->setState(false);
            else
                l->setState(true);
        }
        break;
    case 'g':
        if(shade_smooth) {
            glDisable(GL_SMOOTH);
            glEnable(GL_FLAT);
            glShadeModel(GL_FLAT);
            shade_smooth = false;
        }
        else {
            glDisable(GL_FLAT);
            glEnable(GL_SMOOTH);
            glShadeModel(GL_SMOOTH);
            shade_smooth = true;
        }
        break;
    case 's':
        if(_paused) {
            _paused = false;
        }
        else {
            _paused = true;
        }
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

int GameManager::getLightswitch() const {
	return _lightswitch;
}

void GameManager::setLightswitch(int state) {
	_lightswitch = state;
}

void GameManager::toggleLightswitch(){
	if (getLightswitch())
	{	setLightswitch(0);
		glDisable(GL_LIGHT0);
	}
	else
	{
		setLightswitch(1);
		glEnable(GL_LIGHT0);
	}
}

int GameManager::getLightingCalculation() const {
	return _lightingCalculation;
}

void GameManager::setLightingCalculation(int state) {
	_lightingCalculation = state;
}

void GameManager::toggleLightingCalculation(){
	std::cout << "smooth: "<< getLightingCalculation() << std::endl;
	if (getLightingCalculation())
	{
		setLightingCalculation(0);
        glDisable(GL_LIGHTING);
		std::cout << "lights are out" << std::endl;
	}
	else
	{
		setLightingCalculation(1);
        glEnable(GL_LIGHTING);
		std::cout << "lights are on" << std::endl;
	}
}

void GameManager::update()
{
    int timeNow = glutGet(GLUT_ELAPSED_TIME);
    int deltaTime = timeNow - _lastTime;
    _lastTime = timeNow;

    if(_paused)
        deltaTime = 0;

    //collided(_car);
    _car->update(deltaTime);



    _cameras[2]->setPosition(_car->getPosition() + Vector3(0.0, 0.0, 5.0));

    for (int i = 0; i < 3; i++) //3 is NUM_ORANGES
		_orange[i]->update(deltaTime);


    _cameras[2]->setCameraCenter(_car->getPosition() + _car->getVDirection());

    _activeCamera->computeProjectionMatrix();
    _activeCamera->computeVisualizationMatrix(aspect);



    glutPostRedisplay();
}

void GameManager::init()
{
	int i;
	_car = new Car();
    _objectList.push_back(_car);

    glEnable(GL_SMOOTH);
    glShadeModel(GL_SMOOTH);
    shade_smooth = true;
	//light intensity and color
    GLfloat black[] = { 0.0, 0.0, 0.0, 1.0 };
    GLfloat ambientLight[] = { 0.4, 0.4, 0.4, 1.0 };
    GLfloat diffuseLight[] = { 0.1, 0.1, 0.1, 1.0 };
    GLfloat specularLight[] = { 0.2, 0.2, 0.2, 1.0 };
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambientLight);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseLight);
	glLightfv(GL_LIGHT0, GL_SPECULAR, specularLight);

    glLightModelfv(GL_LIGHT_MODEL_AMBIENT,black);

	//light position
	GLfloat lightPosition[] = { 5.0, 5.0, 5.0, 1.0 };
	glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);

    LightPoint *lp = new LightPoint(GL_LIGHT1);
    lp->setPosition(2.0, 0.0 ,0.5); //right
    _lightpointList.push_back(lp);

    lp = new LightPoint(GL_LIGHT3);
    lp->setPosition(-2.0, 0.0 ,0.5); //left
    _lightpointList.push_back(lp);

    lp = new LightPoint(GL_LIGHT4);
    lp->setPosition(-1.0, -1.2 ,0.5); //bottom
    _lightpointList.push_back(lp);

    lp = new LightPoint(GL_LIGHT5);
    lp->setPosition(1.0, -1.2 ,0.5); //bottom
    _lightpointList.push_back(lp);

    lp = new LightPoint(GL_LIGHT6);
    lp->setPosition(-1.0, 1.2 ,0.5); //top
    _lightpointList.push_back(lp);

    lp = new LightPoint(GL_LIGHT7);
    lp->setPosition(1.0, 1.2 ,0.5); //top
    _lightpointList.push_back(lp);


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
	persp2->setCameraCenter(_car->getPosition() + _car->getVDirection());
	persp2->setPosition(_car->getPosition() + Vector3(0.0, 0.0, 5.0));
	_cameras.push_back(persp2);
  

    _activeCamera = _cameras[0];
    
	_roadside = new Roadside();

	if (!_roadside->loadGLtextures())	
	{
		std::cerr << "SOIL loading error: '" << SOIL_last_result() << "' (textures/plank.jpg)" << std::endl;
	}
			
    for (i = 0; i <= 24; i++) //right right
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
		
    for(i = 0; i < 203; ++i)
        _objectList.push_back(_cheerio[i]);

	_butter[0] = new Butter(new Vector3(2.0,1.8, 0.01));
	_butter[1] = new Butter(new Vector3(2.0, -1.8, 0.01));
	_butter[2] = new Butter(new Vector3(-2.0, -1.8, 0.01));
	_butter[3] = new Butter(new Vector3(-2.0, 1.8, 0.01));
	_butter[4] = new Butter(new Vector3(0.0, -1.65, 0.01));

    for(i = 0; i < 5; ++i)
        _objectList.push_back(_butter[i]);

	float x = gen(rng);
	float y = gen(rng);
	_orange[0] = new Orange(Vector3(x, y, 0.15f), gen2(rng));

	x = gen(rng);
	y = gen(rng);
	_orange[1] = new Orange(Vector3(x, y, 0.15f), gen2(rng));

	x = gen(rng);
	y = gen(rng);
	_orange[2] = new Orange(Vector3(x, y, 0.15f), gen2(rng));

    for(i = 0; i < 3; ++i)
        _objectList.push_back(_orange[i]);

	
	std::cout << _orange[0]->getDirection() << std::endl;
	std::cout << _orange[1]->getDirection() << std::endl;
	std::cout << _orange[2]->getDirection() << std::endl;




    _lastTime = 0;
}

void GameManager::drawFloor()
{

}

void GameManager::collided(Car *car) {
    for(auto o : _objectList) {
        if(o != car) {
            if(o->collided(*car)) {
                if(Cheerio* v1 = dynamic_cast<Cheerio*>(o)) {
                    std::cout <<"Cheerio postion: x: " << o->getPosition().getX()
                              << " y: "<<o->getPosition().getY() << std::endl;
                }
                else if(Butter* v2 = dynamic_cast<Butter*>(o)) {
                    std::cout <<"Butter postion: x: " << o->getPosition().getX()
                              << " y: "<<o->getPosition().getY() << std::endl;
                }
                else if(Orange* v3 = dynamic_cast<Orange*>(o)) {
                    std::cout <<"Orange postion: x: " << o->getPosition().getX()
                              << " y: "<<o->getPosition().getY() << std::endl;
                }
                else if(Car* v4 = dynamic_cast<Car*>(o)) {
                    std::cout <<"Car postion: x: " << o->getPosition().getX()
                              << " y: "<<o->getPosition().getY() << std::endl;
                }



                std::cout << "Car postion: x: " << car->getPosition().getX()
                          << " y: "<<car->getPosition().getY() << std::endl;

                if(car->getAccState() == NONE ||
                        car->getAccState() == SPEEDING ||
                        car->getAccState() == BRAKING ||
                        car->getAccState() == MAXSPEED)
                    car->setAccState(FRONTCOLLIDED);
                else
                    car->setAccState(BACKCOLLIDED);
            }
        }
    }
}
