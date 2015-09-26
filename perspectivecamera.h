#ifndef PERSPECTIVECAMERA_H
#define PERSPECTIVECAMERA_H

#include "camera.h"

namespace Micromachines
{
class PerspectiveCamera : public Camera
{
public:
    PerspectiveCamera(double fovy, double aspect, double zNear, double zFar);
    ~PerspectiveCamera();
    void update();
    void computeProjectionMatrix();
    void computeVisualizationMatrix();
private:
    double _fovy;
    double _aspect;
};
} // namespace Micromachines

#endif // PERSPECTIVECAMERA_H
