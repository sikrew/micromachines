#include "camera.h"

using namespace Micromachines;

Camera::Camera(double near, double far) : _near(near), _far(far)
{ }

Camera::~Camera()
{ }

void Camera::setCameraCenter(Vector3& center) {
	_center.set(center.getX(), center.getY(), center.getZ());
}

void Camera::setCameraUp(Vector3& up) {
	_up.set(up.getX(), up.getY(), up.getZ());
}

void Camera::setCameraRatio(double ratio) {
	_ratio = ratio;
}

Vector3& Camera::getCameraUp() {
	return _up;
}

Vector3& Camera::getCameraCenter() {
	return _center;
}