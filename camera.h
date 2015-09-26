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
    void computeProjectionMatrix();  //const?
    void computeVisualizationMatrix();  //const?
private:
    double _near;
    double _far;
};
} // namespace Micromachines

#endif // CAMERA_H
