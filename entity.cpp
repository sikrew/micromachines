#include "entity.h"

using namespace Micromachines;

Entity::Entity()
{
}

Entity::~Entity()
{

}

Vector3 *Entity::getPosition() const
{
    Vector3 *p = new Vector3();
    *p = _position;
    return p;
}

void Entity::setPosition(double x, double y, double z)
{
    _position.set(x,y,z);
}

void Entity::setPosition(const Vector3 & p)
{
    _position = p;
}
