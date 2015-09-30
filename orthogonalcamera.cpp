#if defined(__APPLE__) || defined(MACOSX)
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include "orthogonalcamera.h"
#include <cstdio>

using namespace Micromachines;

OrthogonalCamera::OrthogonalCamera(double left, double right, double bottom, double top, double near, double far) : Camera(near, far), _left(left), _right(right), _bottom(bottom), _top(top)
{

}

OrthogonalCamera::~OrthogonalCamera()
{

}

void OrthogonalCamera::update()
{

}

void OrthogonalCamera::computeProjectionMatrix()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(_left, _right, _bottom, _top, _near, _far);
}

void OrthogonalCamera::computeVisualizationMatrix()
{
	
	float ratio = (_right - _left) / (_top - _bottom);
	printf("ratio: %f   _ratio: %f\n", ratio, _ratio);
	if (ratio < _ratio)
		glScalef(ratio / _ratio, 1., 1.);
	else
		glScalef(1., _ratio / ratio, 1.);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
