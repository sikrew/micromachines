#include "car.h"

#if defined(__APPLE__) || defined(MACOSX)
    #include <GLUT/glut.h>
#else
    #include <GL/glut.h>
#endif

#include <iostream>
#include <cmath>
#include "mathconstants.h"

using namespace Micromachines;

Car::Car() : _maxAbsSpeed(0.001), _acceleration(0), _direction(0)
{
    this->setPosition(0,1.7,0);
    this->setSpeed(0,0,0);
}

Car::Car(double max) : _maxAbsSpeed(max), _acceleration(0), _direction(0)
{
    this->setPosition(0,0,0);
    this->setSpeed(0,0,0);
}

Car::~Car()
{

}

double Car::getMaxAbsSpeed() const
{
    return _maxAbsSpeed;
}

void Car::setMaxAbsSpeed(double maxAbsSpeed)
{
    _maxAbsSpeed = maxAbsSpeed;
}

double Car::getAcceleration() const
{
    return _acceleration;
}

void Car::setAcceleration(const double acceleration)
{
    if(this->getSpeed().length() >= _maxAbsSpeed)
    {
        _acceleration = 0;
    }
    else if(this->getSpeed().length() <= 0 && acceleration <= 0)
    {
        this->setSpeed(0,0,0);
    }
    else
    {
        _acceleration = acceleration;
    }
}

double Car::getDirection() const
{
    return _direction;
}

void Car::setDirection(const double direction)
{
    _direction = fmod(direction, 360);
}

Lean Car::getLean() const
{
    return _lean;
}

void Car::setLean(const Lean &lean)
{
    _lean = lean;
}

void Car::toggleState() {

	_state = !_state;
}

void Car::draw() const {
    glPushMatrix();
        //Subtrair para ir para o centro do carro
        glTranslatef(this->getPosition().getX(), this->getPosition().getY(), this->getPosition().getZ());
        glScalef(0.2,0.2,0.2);
        glRotatef(_direction, 0.0f, 0.0f, 1.0f);

        if (_state) {

            glColor3f(1.0f, 1.0f, 1.0f);
            glPushMatrix();
                glTranslatef(-0.6f, -0.25f, 0.0f);
                glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
                glutSolidTorus(0.05f, 0.1f, 60, 60);
            glPopMatrix();

            glPushMatrix();
                glTranslatef(-0.6f, 0.6f, 0.0f);
                glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
                glutSolidTorus(0.05f, 0.1f, 60, 60);
            glPopMatrix();

            glPushMatrix();
                glTranslatef(0.6f, -0.25f, 0.0f);
                glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
                glutSolidTorus(0.05f, 0.1f, 60, 60);
            glPopMatrix();

            glPushMatrix();
                glTranslatef(0.6f, 0.6f, 0.0f);
                glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
                glutSolidTorus(0.05f, 0.1f, 60, 60);
            glPopMatrix();

            glColor3f(0.0f, 0.0f, 1.0f);

            glPushMatrix();
                glTranslatef(0.0f, 0.2f, 0.0f);
                glScalef(8.0f, 3.f, 1.0f);
                glutSolidCube(0.2f);
            glPopMatrix();

            glColor3f(0.0f, 1.0f, 0.0f);

            glPushMatrix();
                glTranslatef(0.25f, 0.2f, 0.2f);
                glScalef(4.0f, 3.f, 1.0f);
                glutSolidCube(0.2f);
            glPopMatrix();

	


        }
        else {

            glPushMatrix();
                glTranslatef(-0.6f, 0.0f, 0.0f);
                glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
                glutWireTorus(0.05f, 0.1f, 60, 60);
            glPopMatrix();

            glPushMatrix();
                glTranslatef(-0.6f, 0.4f, 0.0f);
                glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
                glutWireTorus(0.05f, 0.1f, 60, 60);
            glPopMatrix();

            glPushMatrix();
                glTranslatef(0.6f, 0.0f, 0.0f);
                glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
                glutWireTorus(0.05f, 0.1f, 60, 60);
            glPopMatrix();

            glPushMatrix();
                glTranslatef(0.6f, 0.4f, 0.0f);
                glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
                glutWireTorus(0.05f, 0.1f, 60, 60);
            glPopMatrix();

            glColor3f(0.0f, 0.0f, 1.0f);
            glPushMatrix();
                glTranslatef(0.0f, 0.2f, 0.0f);
                glScalef(8.0f, 1.5f, 1.0f);
                glutWireCube(0.2f);
            glPopMatrix();

            glColor3f(0.0f, 1.0f, 0.0f);
            glPushMatrix();
                glTranslatef(0.25f, 0.2f, 0.2f);
                glScalef(4.0f, 1.5f, 1.0f);
                glutWireCube(0.2f);
            glPopMatrix();

        }

    glPopMatrix();
}

void Car::update(double delta_t)
{
    if(_lean == LEFT)
        setDirection(_direction+10);
    else if(_lean == RIGHT)
        setDirection(_direction-10);

    Vector3 vDir = Vector3(cos(_direction*DEGTORADS),sin(_direction*DEGTORADS), 0);
    vDir.normalize();


    this->setSpeed(vDir * this->getSpeed().length());
    this->setSpeed(this->getSpeed() + vDir*_acceleration);

    //std::cout << "Speed after: " <<  _acceleration << std::endl;

    this->setPosition(this->getPosition() + this->getSpeed()*delta_t);
}
