#include "gamemanager.h"
#include "orthogonalcamera.h"

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

    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0f, 0.0f, 0.0f);
	glutSolidCube(2.);
    /*glBegin(GL_POLYGON);
        glVertex3f(0.0f, -1.0f, 0.0f);
        glVertex3f(0.0f, 1.0f, 0.0f);
        glVertex3f(1.0f, 1.0f, 0.0f);
        glVertex3f(1.0f, -1.0f, 0.0f);
    glEnd();

    glColor3f(0.0f, 1.0f, 0.0f);
    glBegin(GL_POLYGON);
        glVertex3f(-1.0f, -1.0f, 0.0f);
        glVertex3f(-1.0f, 1.0f, 0.0f);
        glVertex3f(0.0f, 1.0f, 0.0f);
        glVertex3f(0.0f, -1.0f, 0.0f);
    glEnd();*/


    glFlush();
}

void GameManager::reshape(GLsizei w, GLsizei h)
{
    /*float adjustedProjectionWidth = 2;
    float adjustedProjectionHeight = 2;*/
    float ratio =  w / ((float) h);

	_activeCamera->setCameraRatio(ratio);
	_cameras[0]->setCameraRatio(ratio);

    //if(ratio > 1)
    //{
    //    adjustedProjectionWidth = adjustedProjectionWidth*ratio;
    //}
    //else
    //{
    //    adjustedProjectionHeight = adjustedProjectionHeight/ratio;
    //}

    glViewport(0, 0, w, h);

	_activeCamera->computeProjectionMatrix();
	//_activeCamera->computeVisualizationMatrix(); //TODO: fix ratio glScale

    /*glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
	glOrtho(-adjustedProjectionWidth, adjustedProjectionWidth, -adjustedProjectionHeight, adjustedProjectionHeight, -1.0f, 1.0f);*/
    
    glMatrixMode(GL_MODELVIEW); //needs to be removed afterwards
    glLoadIdentity(); //needs to be removed afterwards
}

void GameManager::keyPressed()
{

}

void GameManager::onTimer()
{

}

void GameManager::idle()
{

}

void GameManager::update()
{

}

void GameManager::init()
{
	Camera* orthogonalCamera = new OrthogonalCamera(-2., 2., -2., 2., -1., 1.);
	orthogonalCamera->setCameraUp(Vector3(0.0, 1.0, 0.0));
	orthogonalCamera->setCameraCenter(Vector3(0.0, 0.0, 1.0));
	_cameras.push_back(orthogonalCamera);

	_activeCamera = _cameras[0];

}

void GameManager::drawFloor()
{

}