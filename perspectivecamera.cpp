#include "perspectivecamera.h"

using namespace Micromachines;

PerspectiveCamera::PerspectiveCamera(double fovy, double aspect, double zNear, double zFar) : Camera(zNear, zFar), _fovy(fovy), _aspect(aspect)
{

}

PerspectiveCamera::~PerspectiveCamera()
{

}

void PerspectiveCamera::update()
{

}

void PerspectiveCamera::computeProjectionMatrix()
{

}

void PerspectiveCamera::computeVisualizationMatrix()
{

}

