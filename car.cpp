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

Car::Car() : _maxAbsSpeed(0.001)
{
    this->setSpeedingAcc(_maxAbsSpeed/3);
    this->setBrakingAcc(_maxAbsSpeed);
}

Car::Car(double max) : _maxAbsSpeed(max)
{
    this->setSpeedingAcc(_maxAbsSpeed/3);
    this->setBrakingAcc(_maxAbsSpeed);
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
        _acceleration = acceleration;
}

double Car::getDirection() const
{
    return _direction;
}

void Car::setDirection(const double direction)
{
    _direction = fmod(direction, 360);
}

double Car::getTurnAngle() const
{
    return _turnAngle;
}

void Car::setTurnAngle(const double turnAngle)
{
    _turnAngle = turnAngle;
}

double Car::getSpeedingAcc() const
{
    return _speedingAcc;
}

void Car::setSpeedingAcc(const double speedingAcc)
{
    _speedingAcc = speedingAcc;
}

double Car::getBrakingAcc() const
{
    return _brakingAcc;
}

void Car::setBrakingAcc(const double brakingAcc)
{
    _brakingAcc = brakingAcc;
}

LeanState Car::getLeanState() const
{
    return _leanState;
}

void Car::setLeanState(const LeanState &leanState)
{
    _leanState = leanState;
}

AccelerationState Car::getAccState() const
{
    return _accState;
}

void Car::setAccState(const AccelerationState &accState)
{
    if(accState == SPEEDING && _accState == MAXSPEED)
        return;
    else if(accState == BRAKING && _accState == STOPPED)
        return;
    else if(accState == NONE && (_accState == MAXSPEED || _accState == STOPPED))
        return;

    _accState = accState;
}

void Car::draw() const {
    glPushMatrix();
        //Subtrair para ir para o centro do carro
        glTranslatef(this->getPosition().getX(), this->getPosition().getY(), this->getPosition().getZ());
        glScalef(0.2,0.2,0.2);
        glRotatef(_direction, 0.0f, 0.0f, 1.0f);

        if (getDrawSolidState() == true) {

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
    if(_leanState == LEFT)
        setDirection(_direction+_turnAngle);
    else if(_leanState == RIGHT)
        setDirection(_direction-_turnAngle);

    if(_accState == SPEEDING) {
        setAcceleration(_speedingAcc);
    }
    else if(_accState == BRAKING) {
        setAcceleration(_brakingAcc);
    }
    else {
        setAcceleration(0);
    }

    Vector3 vDir = Vector3(cos(_direction*DEGTORADS),sin(_direction*DEGTORADS), 0);
    vDir.normalize(); //Para ter a certeza, acho que dá para tirar


    this->setSpeed(vDir * this->getSpeed().length());

    if(_accState == SPEEDING || _accState == BRAKING)
    {
        this->setSpeed(this->getSpeed() + vDir*_acceleration*delta_t);

        Vector3 vSpeedNormalized = this->getSpeed();
        vSpeedNormalized.normalize();

        if(this->getSpeed().length() > _maxAbsSpeed) {
            this->setSpeed(vDir*_maxAbsSpeed);
            this->setAccState(MAXSPEED);
        }
        else if((vDir - vSpeedNormalized).length() > vDir.length()*1.9) {
            this->setSpeed(0,0,0);
            this->setAccState(STOPPED);
        }
    }

    //std::cout << "Speed after: " <<  _acceleration << std::endl;

    this->setPosition(this->getPosition() + this->getSpeed()*delta_t);
}
