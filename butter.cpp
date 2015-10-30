#include "butter.h"

#if defined(__APPLE__) || defined(MACOSX)
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

using namespace Micromachines;

Butter::Butter(Vector3 *position)
{
	_position = position;
	setWSize(0.4);
	setHSize(0.2);
}

Butter::~Butter()
{

}

void Butter::draw() const
{
	glColor3f(0.9529f, 0.9372f, 0.4902f);
	glPushMatrix();
	glTranslatef(_position->getX(), _position->getY(), _position->getZ());
	glScalef(2.0f, 1.0f, 1.0f);
	glutSolidCube(0.2f);
	glPopMatrix();
}

void Butter::update(double delta_t) {

}
