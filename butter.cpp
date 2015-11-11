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
    setHSize(0.8);
}

Butter::~Butter()
{

}

void Butter::draw() const
{
	GLfloat butteryellow[] = { 0.9, 0.9, 0.5, 1.0 };
	GLfloat white[] = { 1.0, 1.0, 1.0, 1.0 };

	glMaterialfv(GL_FRONT, GL_AMBIENT, butteryellow);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, butteryellow);
	glMaterialfv(GL_FRONT, GL_SPECULAR, white);
	glMaterialf(GL_FRONT, GL_SHININESS, 60.0);

	glColor3f(0.9f, 0.9f, 0.5f);
	glPushMatrix();
	glTranslatef(_position->getX(), _position->getY(), _position->getZ());
	glScalef(2.0f, 1.0f, 1.0f);
	glutSolidCube(0.2f);
	glPopMatrix();
}

void Butter::update(double delta_t) {

}
