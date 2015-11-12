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

std::ostream& operator<<(std::ostream& out, const AccelerationState value){
    const char* s = 0;
#define PROCESS_VAL(p) case(p): s = #p; break;
    switch(value){
        PROCESS_VAL(NONE);
        PROCESS_VAL(SPEEDING);
        PROCESS_VAL(BRAKING);
        PROCESS_VAL(MAXSPEED);
        PROCESS_VAL(NONEREVERSE);
        PROCESS_VAL(SPEEDREVERSE);
        PROCESS_VAL(REVERSE);
        PROCESS_VAL(MAXREVERSE);
        PROCESS_VAL(FRONTCOLLIDED);
        PROCESS_VAL(BACKCOLLIDED);
    }
#undef PROCESS_VAL

    return out << s;
}


Car::Car() : _maxAbsSpeed(0.002), _maxReverseSpeed(0.0007)
{
    this->setSpeedingAcc(_maxAbsSpeed/2000);
    this->setBrakingAcc(-_maxAbsSpeed/1000);
	this->setDrawSolidState(true);
	this->setPosition(Vector3(0, 1.7, 0.2));
    this->setDirection(_direction);
    this->_friction = 0.5;
    setWSize(0.2);
    setHSize(0.2);

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
    _vDirection = Vector3(cos(_direction*DEGTORADS),sin(_direction*DEGTORADS), 0);
    _vDirection.normalize(); //Para ter a certeza, acho que dá para tirar
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

    if(accState == SPEEDING && _accState == MAXSPEED) {
        std::cout << "i: " << accState << "  r: " << this->getAccState() << std::endl;
        return;
    }
    else if(accState == BRAKING && _accState == MAXREVERSE) {
        std::cout << "i: " << accState << "  r: " << this->getAccState() << std::endl;
        return;
    }
    else if(accState == BRAKING && (_accState == NONEREVERSE ||  _accState == SPEEDREVERSE || _accState == REVERSE)) {
        _accState = REVERSE;
        std::cout << "i: " << accState << "  r: " << this->getAccState() << std::endl;
        return;
    }
    else if(accState == SPEEDING && (_accState == NONEREVERSE || _accState == SPEEDREVERSE || _accState == REVERSE || _accState == MAXREVERSE)) {
        _accState = SPEEDREVERSE;
        std::cout << "i: " << accState << "  r: " << this->getAccState() << std::endl;
        return;
    }
    else if(accState == NONE && (_accState == NONEREVERSE ||  _accState == SPEEDREVERSE || _accState == REVERSE || _accState == MAXREVERSE)) {
        _accState = NONEREVERSE;
        std::cout << "i: " << accState << "  r: " << this->getAccState() << std::endl;
        return;
    }
    else if( _accState == FRONTCOLLIDED && accState != BRAKING) {
        std::cout << "i: " << accState << "  r: " << this->getAccState() << std::endl;
        return;
    }
    else if( _accState == BACKCOLLIDED && accState != SPEEDING) {
        std::cout << "i: " << accState << "  r: " << this->getAccState() << std::endl;
        return;
    }

    _accState = accState;
    std::cout << "i: " << accState << "  r: " << this->getAccState() << std::endl;
}

void Car::draw() const {

	GLfloat green[] = { 0.0, 1.0, 0.0, 1.0 };
	GLfloat blue[] = { 0.0, 0.0, 1.0, 1.0 };
	GLfloat white[] = { 1.0, 1.0, 1.0, 1.0 };

	GLfloat Chrome_amb[] = { 0.25, 0.25, 0.25 };	
	GLfloat Chrome_dif[] = { 0.4, 0.4, 0.4 };
	GLfloat Chrome_spc[] = { 0.774597, 0.774597, 0.774597 };

	glMaterialfv(GL_FRONT, GL_AMBIENT, Chrome_amb);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, Chrome_dif);
	glMaterialfv(GL_FRONT, GL_SPECULAR, Chrome_spc);
	glMaterialf(GL_FRONT, GL_SHININESS, 76.8);

//Carroçaria inferior
	//Face-Up
	glBegin(GL_QUADS);
		glVertex3f(-0.16f, -0.06f, 0.1f);
		glNormal3f(0.0f, 0.0f, 1.0f);
		glVertex3f(-0.16f, 0.06f, 0.1f);
		glNormal3f(0.0f, 0.0f, 1.0f);
		glVertex3f(0.16f, 0.06f, 0.1f);
		glNormal3f(0.0f, 0.0f, 1.0f);
		glVertex3f(0.16f, -0.06f, 0.1f);
		glNormal3f(0.0f, 0.0f, 1.0f);
	glEnd();

	//Face-Down
	glBegin(GL_QUADS);
		glVertex3f(-0.16f, -0.06f, -0.1f);
		glNormal3f(0.0f, 0.0f, -1.0f);
		glVertex3f(-0.16f, 0.06f, -0.1f);
		glNormal3f(0.0f, 0.0f, -1.0f);
		glVertex3f(0.16f, 0.06f, -0.1f);
		glNormal3f(0.0f, 0.0f, -1.0f);
		glVertex3f(0.16f, -0.06f, -0.1f);
		glNormal3f(0.0f, 0.0f, -1.0f);
	glEnd();

	//Face-Back
	glBegin(GL_QUADS);
		glVertex3f(0.16f, -0.06f, 0.1f);
		glNormal3f(-1.0f, 0.0f, 0.0f);
		glVertex3f(0.16f, -0.06f, -0.1f);
		glNormal3f(-1.0f, 0.0f, 0.0f);
		glVertex3f(0.16f, 0.06f, -0.1f);
		glNormal3f(-1.0f, 0.0f, 0.0f);
		glVertex3f(0.16f, 0.06f, 0.1f);
		glNormal3f(-1.0f, 0.0f, 0.0f);
	glEnd();
	
	//Face-Front
	glBegin(GL_QUADS);
		glVertex3f(-0.16f, -0.06f, 0.1f);
		glNormal3f(1.0f, 0.0f, 0.0f);
		glVertex3f(-0.16f, -0.06f, -0.1f);
		glNormal3f(1.0f, 0.0f, 0.0f);
		glVertex3f(-0.16f, 0.06f, -0.1f);
		glNormal3f(1.0f, 0.0f, 0.0f);
		glVertex3f(-0.16f, 0.06f, 0.1f);
		glNormal3f(1.0f, 0.0f, 0.0f);
	glEnd();

	//Face-Right
	glBegin(GL_QUADS);
		glVertex3f(-0.16f, 0.06f, 0.1f);
		glNormal3f(0.0f, 1.0f, 0.0f);
		glVertex3f(0.16f, 0.06f, 0.1f);
		glNormal3f(0.0f, 1.0f, 0.0f);
		glVertex3f(0.16f, 0.06f, -0.1f);
		glNormal3f(0.0f, 1.0f, 0.0f);
		glVertex3f(-0.16f, 0.06f, -0.1f);
		glNormal3f(0.0f, 1.0f, 0.0f);
	glEnd();

	//Face-Left
	glBegin(GL_QUADS);
		glVertex3f(-0.16f, -0.06f, 0.1f);
		glNormal3f(0.0f, -1.0f, 0.0f);
		glVertex3f(0.16f, -0.06f, 0.1f);
		glNormal3f(0.0f, -1.0f, 0.0f);
		glVertex3f(0.16f, -0.06f, -0.1f);
		glNormal3f(0.0f, -1.0f, 0.0f);
		glVertex3f(-0.16f, -0.06f, -0.1f);
		glNormal3f(0.0f, -1.0f, 0.0f);
	glEnd();


//Carroçaria Superior
	//Face-Up
	glBegin(GL_QUADS);
		glVertex3f(-0.06f, 0.06f, 0.26f);
		glNormal3f(0.0f, 0.0f, 1.0f);
		glVertex3f(0.04f, 0.06f, 0.26f);
		glNormal3f(0.0f, 0.0f, 1.0f);
		glVertex3f(0.04f, -0.06f, 0.26f);
		glNormal3f(0.0f, 0.0f, 1.0f);
		glVertex3f(-0.06f, -0.06f, 0.26f);
		glNormal3f(0.0f, 0.0f, 1.0f);
	glEnd();

	//Face-Back
	glBegin(GL_QUADS);
		glVertex3f(0.04f, -0.06f, 0.26f);
		glNormal3f(-1.0f, 0.0f, 0.0f);
		glVertex3f(0.04f, 0.06f, 0.26f);
		glNormal3f(-1.0f, 0.0f, 0.0f);
		glVertex3f(0.04f, 0.06f, 0.1f);
		glNormal3f(-1.0f, 0.0f, 0.0f);
		glVertex3f(0.04f, -0.06f, 0.1f);
		glNormal3f(-1.0f, 0.0f, 0.0f);
	glEnd();

	//Face-Front
	glBegin(GL_QUADS);
		glVertex3f(-0.06f, 0.06f, 0.26f);
		glNormal3f(0.0192f, 0.0f, 0.0024f);
		glVertex3f(-0.08f, 0.06f, 0.1f);
		glNormal3f(-0.0192f, 0.0f, 0.0024f);
		glVertex3f(-0.08f, -0.06f, 0.1f);
		glNormal3f(-0.0192f, 0.0f, 0.0024f);
		glVertex3f(-0.06f, -0.06f, 0.26f);
		glNormal3f(0.0192f, 0.0f, 0.0024f);
	glEnd();

	//Face-Right
	glBegin(GL_QUADS);
		glVertex3f(-0.06f, 0.06f, 0.26f);
		glNormal3f(0.0f, 1.0f, 0.0f);
		glVertex3f(0.04f, 0.06f, 0.26f);
		glNormal3f(0.0f, 1.0f, 0.0f);
		glVertex3f(0.04f, 0.06f, 0.1f);
		glNormal3f(0.0f, 1.0f, 0.0f);
		glVertex3f(-0.08f, 0.06f, 0.1f);
		glNormal3f(0.0f, 1.0f, 0.0f);
	glEnd();

	//Face-Left
	glBegin(GL_QUADS);
		glVertex3f(-0.06f, -0.06f, 0.26f);
		glNormal3f(0.0f, -1.0f, 0.0f);
		glVertex3f(0.04f, -0.06f, 0.26f);
		glNormal3f(0.0f, -1.0f, 0.0f);
		glVertex3f(0.04f, -0.06f, 0.1f);
		glNormal3f(0.0f, -1.0f, 0.0f);
		glVertex3f(-0.08f, -0.06f, 0.1f);
		glNormal3f(0.0f, -1.0f, 0.0f);
	glEnd();

	/*glPushMatrix();
        //Subtrair para ir para o centro do carro
        glTranslatef(this->getPosition().getX(), this->getPosition().getY(), this->getPosition().getZ());
        glScalef(0.2,0.2,0.2);
        glRotatef(_direction, 0.0f, 0.0f, 1.0f);

        if (getDrawSolidState() == true) {

			glMaterialfv(GL_FRONT, GL_AMBIENT, green);
			glMaterialfv(GL_FRONT, GL_DIFFUSE, green);
			glMaterialfv(GL_FRONT, GL_SPECULAR, white);
			glMaterialf(GL_FRONT, GL_SHININESS, 100.0);

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

			glMaterialfv(GL_FRONT, GL_AMBIENT, blue);
			glMaterialfv(GL_FRONT, GL_DIFFUSE, blue);
			glMaterialfv(GL_FRONT, GL_SPECULAR, white);
			glMaterialf(GL_FRONT, GL_SHININESS, 20.0);

            glPushMatrix();
                glTranslatef(0.0f, 0.2f, 0.0f);
                glScalef(8.0f, 3.f, 1.0f);
                glutSolidCube(0.2f);
            glPopMatrix();

            glColor3f(0.0f, 1.0f, 0.0f);

			glMaterialfv(GL_FRONT, GL_AMBIENT, green);
			glMaterialfv(GL_FRONT, GL_DIFFUSE, green);
			glMaterialfv(GL_FRONT, GL_SPECULAR, white);
			glMaterialf(GL_FRONT, GL_SHININESS, 20.0);

            glPushMatrix();
                glTranslatef(0.25f, 0.2f, 0.2f);
                glScalef(4.0f, 3.f, 1.0f);
                glutSolidCube(0.2f);
            glPopMatrix();

	


        }
        else {

            glPushMatrix();
                glTranslatef(-0.6f, -0.25f, 0.0f);
                glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
                glutWireTorus(0.05f, 0.1f, 60, 60);
            glPopMatrix();

            glPushMatrix();
                glTranslatef(-0.6f, 0.6f, 0.0f);
                glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
                glutWireTorus(0.05f, 0.1f, 60, 60);
            glPopMatrix();

            glPushMatrix();
                glTranslatef(0.6f, -0.25f, 0.0f);
                glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
                glutWireTorus(0.05f, 0.1f, 60, 60);
            glPopMatrix();

            glPushMatrix();
                glTranslatef(0.6f, 0.6f, 0.0f);
                glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
                glutWireTorus(0.05f, 0.1f, 60, 60);
            glPopMatrix();

            glColor3f(0.0f, 0.0f, 1.0f);
            glPushMatrix();
                glTranslatef(0.0f, 0.2f, 0.0f);
                glScalef(8.0f, 3.0f, 1.0f);
                glutWireCube(0.2f);
            glPopMatrix();

            glColor3f(0.0f, 1.0f, 0.0f);
            glPushMatrix();
                glTranslatef(0.25f, 0.2f, 0.2f);
                glScalef(4.0f, 3.0f, 1.0f);
                glutWireCube(0.2f);
            glPopMatrix();

        }

    glPopMatrix();*/
}

void Car::update(double delta_t)
{
    if(_accState == FRONTCOLLIDED || _accState == BACKCOLLIDED) {
            setAcceleration(0);
            setSpeed(Vector3(0,0,0));
    }
    else if(_leanState == LEFT)
        setDirection(_direction+_turnAngle);
    else if(_leanState == RIGHT)
        setDirection(_direction-_turnAngle);

    if(_accState == SPEEDING || _accState == SPEEDREVERSE) {
        setAcceleration(_speedingAcc);
    }
    else if(_accState == BRAKING) {
        setAcceleration(_brakingAcc);
    }
    else if(_accState == REVERSE) {
        setAcceleration(_brakingAcc);
    }
    else if(_accState == MAXSPEED || _accState == NONE) {
        setAcceleration(_friction);
    }
    else if(_accState == MAXREVERSE || _accState == NONEREVERSE) {
        setAcceleration(-_friction);
    }


    if(_accState == REVERSE || _accState == SPEEDREVERSE || _accState == MAXREVERSE || _accState == NONEREVERSE) {
        this->setSpeed(Vector3(0,0,0) - (_vDirection * this->getSpeed().length()));
    }
    else {
        this->setSpeed(_vDirection * this->getSpeed().length());
    }

    if(_accState == SPEEDING || _accState == BRAKING)
    {
        this->setSpeed(this->getSpeed() + _vDirection*_acceleration*delta_t);

        Vector3 vSpeedNormalized = this->getSpeed();
        vSpeedNormalized.normalize();

        if(this->getSpeed().length() > _maxAbsSpeed && _accState == SPEEDING) {
            this->setSpeed(_vDirection*_maxAbsSpeed);
//			std::cout << "Acc: " << this->getSpeed().getX() << std::endl;
            this->setAccState(MAXSPEED);
        }
        else if((_vDirection - vSpeedNormalized).length() > _vDirection.length()*1.999) {
            std::cout << "u: " << this->getAccState() << std::endl;
            _accState = REVERSE;
        }
    }
    else if(_accState == SPEEDREVERSE || _accState == REVERSE) {
        this->setSpeed(this->getSpeed() + _vDirection*_acceleration*delta_t);

        Vector3 vSpeedNormalized = this->getSpeed();
        vSpeedNormalized.normalize();

        if(this->getSpeed().length() > _maxReverseSpeed && _accState == REVERSE) {
            this->setSpeed(_vDirection*-_maxReverseSpeed);
            this->setAccState(MAXREVERSE);
        }
        else if((_vDirection - vSpeedNormalized).length() < _vDirection.length()*1.999) {
            std::cout << "u: " << this->getAccState();
            _accState = SPEEDING;
            std::cout << " to: " << this->getAccState() << std::endl;
        }
    }
    else if(_accState == NONE) {
        this->setSpeed(this->getSpeed() - _vDirection*this->getSpeed().length()*this->getSpeed().length()*_friction*delta_t);

    }
    else if(_accState == NONEREVERSE) {
        this->setSpeed(this->getSpeed() + _vDirection*this->getSpeed().length()*this->getSpeed().length()*_friction*delta_t);
    }
    //std::cout << "Speed after: " <<  _acceleration << std::endl;

    this->setPosition(this->getPosition() + this->getSpeed()*delta_t);
}

Vector3 Car::getVDirection() const
{
    return _vDirection;
}
