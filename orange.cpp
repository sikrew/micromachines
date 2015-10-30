#include <cmath>
#include <ctime>
#include <random>
#include <iostream>
#include "orange.h"
#include "mathconstants.h"

#if defined(__APPLE__) || defined(MACOSX)
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

using namespace Micromachines;

std::mt19937 orangeRng(time(NULL));
std::uniform_real_distribution<double> orangeGen(0.f, 360.f);

Orange::Orange(Vector3 position, double direction){
    _direction = direction;
    this->setPosition(position);
//	this->setPosition(Vector3(0, 1.7, 0.2)
}

Orange::~Orange()
{

}

double Orange::getDirection() const {
    return _direction;
}


double Orange::getXRotation() const{
    return _xRotation;
}

double Orange::getYRotation() const{
    return _yRotation;
}

double Orange::getZRotation() const{
    return _zRotation;
}

void Orange::setDirection(double direction) {
    _direction = direction;
}

void Orange::setXRotation(double xRotation) {
    _xRotation = xRotation;
}

void Orange::setYRotation(double yRotation) {
    _yRotation = yRotation;
}

void Orange::setZRotation(double zRotation) {
    _zRotation = zRotation;
}



void Orange::draw() const
{
    glColor3f(1.0f, 0.6471f, 0.0f);
    glPushMatrix();
    glTranslatef(this->getPosition().getX(), this->getPosition().getY(), this->getPosition().getZ());
    glRotatef(this->getDirection(), 0.0, 0.0, 1.0);

    //rotate the orange
    // rotate around X axis
    glRotatef(this->getXRotation(), 1.0, 0.0, 0.0);
    // rotation around Y axis
    glRotatef(this->getYRotation(), 0.0, 1.0, 0.0);
    // rotation around Z axis
    glRotatef(this->getZRotation(), 0.0, 0.0, 1.0);


    glutSolidSphere(.15, 32, 32);
    //glutWireSphere(.15, 10, 10);
    glColor3f(0.f, 1.f, 0.f);
    glTranslatef(0.f, 0.f, -0.1f);
    glScalef(0.05f, 0.02f, 0.3f);
    glutSolidCube(1);
    glPopMatrix();
}

void Orange::update(double delta_t) {

    Vector3 vDir = Vector3(cos(_direction*DEGTORADS), sin(_direction*DEGTORADS), 0);
    vDir.normalize(); //Para ter a certeza, acho que dá para tirar

    //this->setSpeed(vDir * this->getSpeed().length());
    //this->setSpeed(this->getSpeed() + vDir*_acceleration*delta_t);


    // Verificar se a bola saiu da mesa
    if (this->getPosition().getX() > 4.0f || this->getPosition().getX() < -4.0f)
        this->setPosition(this->getPosition() + Vector3(0.0f, 0.0, -0.01f));

    if (this->getPosition().getY() > 4.0f || this->getPosition().getY() < -4.0f)
        this->setPosition(this->getPosition() + Vector3(0.0f, 0.0, -0.01f));


    else //this->setPosition(this->getPosition() + this->getSpeed()*delta_t);
        this->setPosition(this->getPosition() + Vector3(0.01*cos(_direction*DEGTORADS), 0.01*sin(_direction*DEGTORADS), 0.0f));

    int direction = this->getDirection();
    if (direction == 0 || direction == 360){
        this->setXRotation(this->getXRotation() + 1);
        this->setYRotation(0);
    }
    else if (1 <= direction && direction <= 89){
        this->setXRotation(this->getXRotation() + 1);
        this->setYRotation(this->getYRotation() + 1);
    }
    if (direction == 90){
        this->setXRotation(0);
        this->setYRotation(this->getYRotation() + 1);
    }
    else if (91 <= direction && direction <= 179){
        this->setXRotation(this->getXRotation() -1);
        this->setYRotation(this->getYRotation() + 1);
    }
    else if (direction == 180){
        this->setXRotation(this->getXRotation() - 1);
        this->setYRotation(0);
    }
    else if (181 <= direction && direction <= 269){
        this->setXRotation(this->getXRotation() - 1);
        this->setYRotation(this->getYRotation() - 1);
    }
    else if (direction == 270){
        this->setXRotation(0);
        this->setYRotation(this->getYRotation() - 1);
    }
    else if (271 <= direction && direction <=359){
        this->setXRotation(this->getXRotation() + 1);
        this->setYRotation(this->getYRotation() - 1);
    }


    //this->setXRotation(this->getXRotation() + 0.1*delta_t);
    //this->setYRotation(this->getYRotation() + 1);
    //this->setZRotation(this->getZRotation() + 1);

    if (this->getPosition().getZ() < -1.f){
        this->setPosition(Vector3(0.0, 0.0, 0.0));
        this->setDirection(orangeGen(orangeRng));
    }

    //std::cout << "x angle:  " << this->getXRotation() << std::endl;
    //std::cout << "y angle: " << this->getYRotation() << std::endl;
    //std::cout << "z angle: " << this->getZRotation() << std::endl;
    //std::cout << "delta_t: " << delta_t << std::endl;

}
