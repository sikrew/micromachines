#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "entity.h"

namespace Micromachines
{
class GameObject : public Entity
{
public:
    GameObject();
    ~GameObject();
    virtual void draw() const = 0;
    virtual void update(double delta_t) = 0;
};
} // Namespace Micromachines

#endif // GAMEOBJECT_H
