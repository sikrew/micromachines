#include "roadside.h"

#if defined(__APPLE__) || defined(MACOSX)
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include "staticobject.h"

using namespace Micromachines;

Roadside::Roadside()
{

}

Roadside::~Roadside()
{

}

void Roadside::draw() const
{
	glColor3f(0.0, 1.0, 1.0);
	glPushMatrix();
	glTranslatef(0.0f, 0.0f, -1.0f);
	glScalef(8.0f, 8.0f, 1.0f);
	glutSolidCube(1);
	glPopMatrix();

}

void Roadside::update(double delta_t) {

}

