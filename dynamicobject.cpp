#include "dynamicobject.h"

using namespace Micromachines;

DynamicObject::DynamicObject()
{

}

DynamicObject::~DynamicObject()
{

}

void DynamicObject::setSpeed(const Vector3 &speed)
{
    _speed = speed;
}

void DynamicObject::setSpeed(const double x, const double y, const double z)
{
    _speed.set(x, y, z);
}

const Vector3 &DynamicObject::getSpeed() const
{
    return _speed;
}
