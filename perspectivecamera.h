#ifndef PERSPECTIVECAMERA_H
#define PERSPECTIVECAMERA_H

#include "camera.h"

namespace Micromachines
{
class PerspectiveCamera : public Camera
{
public:
    PerspectiveCamera(double fovy, double zNear, double zFar);
    ~PerspectiveCamera();
    void update();
	void computeProjectionMatrixReshape(GLsizei w, GLsizei h);
    void computeProjectionMatrix();
    void computeVisualizationMatrix(float ratio);
private:
    double _fovy;
    double _aspect;
};
} // namespace Micromachines

#endif // PERSPECTIVECAMERA_H
