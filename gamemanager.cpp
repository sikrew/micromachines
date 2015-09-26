#include "gamemanager.h"

using namespace Micromachines;

GameManager::GameManager()
{
}

GameManager::~GameManager()
{

}

void GameManager::display()
{
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
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
    glEnd();


    glFlush();
}

void GameManager::reshape(GLsizei w, GLsizei h)
{
    float adjustedProjectionWidth = 2;
    float adjustedProjectionHeight = 2;
    float ratio =  w / ((float) h);

    if(ratio > 1)
    {
        adjustedProjectionWidth = adjustedProjectionWidth*ratio;
    }
    else
    {
        adjustedProjectionHeight = adjustedProjectionHeight/ratio;
    }

    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-adjustedProjectionWidth, adjustedProjectionWidth, -adjustedProjectionHeight, adjustedProjectionHeight, -1.0f, 1.0f);
    glMatrixMode(GL_MODELVIEW);

    glLoadIdentity();
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

}
