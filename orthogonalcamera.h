#ifndef ORTHOGONALCAMERA_H
#define ORTHOGONALCAMERA_H

#include "camera.h"

namespace Micromachines
{
class OrthogonalCamera : public Camera
{
public:
    OrthogonalCamera(double left, double right, double bottom, double top, double near, double far);
    ~OrthogonalCamera();
    void update();
    void computeProjectionMatrix();
    void computeVisualizationMatrix(float ratio);
private:
    double _left;
    double _right;
    double _bottom;
    double _top;
};
} // namespace Micromachines

#endif // ORTHOGONALCAMERA_H