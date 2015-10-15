#include "orange.h"

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

void Orange::draw() const
{
	glColor3f(1.0f, 0.6471f, 0.0f);
	glPushMatrix();
	glTranslatef(_position->getX(), _position->getY(), _position->getZ());
	glutSolidSphere(0.15, 32, 32);	
	glPopMatrix();
}

void Orange::update(double delta_t) {

}

