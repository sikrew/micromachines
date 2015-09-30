#ifndef CAMERA_H
#define CAMERA_H

#include "entity.h"

namespace Micromachines
{
class Camera : public Entity
{
public:
    Camera(double near, double far);
    ~Camera();
    virtual void update() = 0;
    virtual void computeProjectionMatrix() = 0;
    virtual void computeVisualizationMatrix() = 0;
	void setCameraCenter(Vector3& center);
	void setCameraUp(Vector3& up);
	void setCameraRatio(double ratio);
	Vector3& getCameraUp();
	Vector3& getCameraCenter();

protected:
    double _near;
    double _far;
	double _ratio;
    Vector3 _up;
    Vector3 _center;
    Vector3 _at;
};
} // namespace Micromachines

#endif // CAMERA_H
