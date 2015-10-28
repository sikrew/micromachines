#include <cmath>
#include <iostream>
#include "orange.h"
#include "mathconstants.h"

#if defined(__APPLE__) || defined(MACOSX)
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

using namespace Micromachines;

Orange::Orange(Vector3 *position){

	_position = position;
}

Orange::~Orange()
{

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
	glTranslatef(_position->getX(), _position->getY(), _position->getZ());

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

	this->setSpeed(this->getSpeed() + vDir*delta_t);
	this->setXRotation(this->getXRotation() + 1);
	//this->setYRotation(this->getYRotation() + 1);
	//this->setZRotation(this->getZRotation() + 1);

	//std::cout << "x angle:  " << this->getXRotation() << std::endl;
	//std::cout << "y angle: " << this->getYRotation() << std::endl;
	//std::cout << "z angle: " << this->getZRotation() << std::endl;
	//std::cout << "delta_t: " << delta_t << std::endl;
}

