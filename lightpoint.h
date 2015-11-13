#ifndef LIGHTPOINT_H
#define LIGHTPOINT_H

#include "lightsource.h"

namespace Micromachines
{
class LightPoint : public LightSource
{
public:
    LightPoint(int id);
    ~LightPoint();
    LightPoint(int id, Vector3 &ambient, Vector3 &diffuse, Vector3 &specular);
};
} // Namespace Micromachines
#endif // LIGHTPOINT_H
