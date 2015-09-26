#ifndef ENTITY_H
#define ENTITY_H

#include "vector3.h"

namespace Micromachines
{
class Entity
{
private:
    Vector3 _position;
public:
    Entity();
    ~Entity();
    const Vector3 &getPosition() const;
    void setPosition(double x, double y, double z);
    void setPosition(const Vector3 &p);
};
} //namespace Micromachines

#endif // ENTITY_H
