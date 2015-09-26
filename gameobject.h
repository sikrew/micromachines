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
    void draw();
    void update(double delta_t);
};
} //Namespace Micromachines

#endif // GAMEOBJECT_H
