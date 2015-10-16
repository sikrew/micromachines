#include "cheerio.h"
#if defined(__APPLE__) || defined(MACOSX)
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

using namespace Micromachines;

Cheerio::Cheerio(Vector3 &position) : _postion(position)
{
}

Cheerio::~Cheerio()
{
}

void Cheerio::draw() const
{
	glColor3f(1.0f, 0.0f, 0.6f);
	glPushMatrix();
	glTranslatef(_position->getX(), _position->getY(), _position->getZ());
	glutSolidTorus(0.01, 0.02, 64, 64);
	glPopMatrix();
}

void Cheerio::update(double delta_t) {

}

