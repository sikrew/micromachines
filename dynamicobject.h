#ifndef DYNAMICOBJECT_H
#define DYNAMICOBJECT_H

#include "gameobject.h"

namespace Micromachines
{
class DynamicObject : public GameObject
{
public:
    DynamicObject();
    ~DynamicObject();
    void setSpeed(const Vector3 &speed);
    void setSpeed(const double x, const double y, const double z);
    const Vector3 &getSpeed() const;
protected:
    Vector3 _speed;
};
} // namespace Micromachines

#endif // DYNAMICOBJECT_H
