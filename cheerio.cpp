#include "cheerio.h"
#if defined(__APPLE__) || defined(MACOSX)
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

using namespace Micromachines;

Cheerio::Cheerio(const Vector3 &position)
{
	_position = position;
    setWSize(0.001);
    setHSize(0.001);
}

Cheerio::~Cheerio()
{
}

void Cheerio::draw() const
{
	GLfloat red[] = { 1.0, 0.0, 0.0, 1.0 };
	GLfloat white[] = { 1.0, 1.0, 1.0, 1.0 };

	glMaterialfv(GL_FRONT, GL_AMBIENT, red);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, red);
	glMaterialfv(GL_FRONT, GL_SPECULAR, white);
	glMaterialf(GL_FRONT, GL_SHININESS, 60.0);

	glColor3f(1.0f, 0.0f, 0.6f);
	glPushMatrix();
	glTranslatef(_position.getX(), _position.getY(), _position.getZ());
	glutSolidTorus(0.01, 0.02, 16, 16);
	glPopMatrix();
}

void Cheerio::update(double delta_t) {

}

