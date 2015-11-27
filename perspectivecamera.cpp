#include "perspectivecamera.h"

#if defined(__APPLE__) || defined(MACOSX)
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

using namespace Micromachines;

PerspectiveCamera::PerspectiveCamera(double fovy, double zNear, double zFar) : Camera(zNear, zFar), _fovy(fovy)
{
	_ratio = 1.0f;
}

PerspectiveCamera::~PerspectiveCamera()
{

}

void PerspectiveCamera::update()
{

}

void Micromachines::PerspectiveCamera::computeProjectionMatrixReshape(GLsizei w, GLsizei h)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(_fovy, _ratio, _near, _far);
}

void PerspectiveCamera::computeProjectionMatrix()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(_fovy, _ratio, _near, _far);
}

void PerspectiveCamera::computeVisualizationMatrix(float aspect)
{


	if (_ratio < aspect)
		glScalef(_ratio / aspect, 1., 1.);
	else
		glScalef(1., aspect / _ratio, 1.);


	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(getPosition().getX(), getPosition().getY(), getPosition().getZ(),
		getCameraCenter().getX(), getCameraCenter().getY(), getCameraCenter().getZ(),
		getCameraUp().getX(), getCameraUp().getY(), getCameraUp().getZ());
}

