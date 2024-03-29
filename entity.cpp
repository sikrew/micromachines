#include "entity.h"

using namespace Micromachines;

Entity::Entity()
{ }

Entity::~Entity()
{ }

const Vector3 &Entity::getPosition() const
{
    return _position;
}

void Entity::setPosition(double x, double y, double z)
{
    _position.set(x,y,z);
}

void Entity::setPosition(const Vector3 & p)
{
    _position = p;
}
