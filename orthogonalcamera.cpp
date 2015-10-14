#include <iostream>
#include <stdlib.h>
#if defined(__APPLE__) || defined(MACOSX)
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include "orthogonalcamera.h"

using namespace Micromachines;

OrthogonalCamera::OrthogonalCamera(double left, double right, double bottom, double top, double near, double far) : Camera(near, far), _left(left), _right(right), _bottom(bottom), _top(top)
{
	_ratio = (right - left) / (top - bottom);
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

void OrthogonalCamera::computeVisualizationMatrix(float aspect)
{
	std::cout << "ratio: " << aspect << "_ratio: " << _ratio << std::endl;

	if (_ratio < aspect)
		glScalef(_ratio / aspect, 1., 1.);
	else
		glScalef(1., aspect / _ratio, 1.);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
