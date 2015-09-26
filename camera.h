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
    void update();
    void computeProjectionMatrix();
    void computeVisualizationMatrix();
private:
    double _near;
    double _far;
};
} //namespace Micromachines
#endif // CAMERA_H
