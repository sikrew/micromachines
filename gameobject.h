#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "entity.h"


namespace Micromachines
{

class DynamicObject;

class GameObject : public Entity
{
public:
    GameObject();
    ~GameObject();
    bool getDrawSolidState() const;
    void setDrawSolidState(bool drawSolidState);
    Vector3 getWSize() const;
    void setWSize(const Vector3 &wSize);
    Vector3 getHSize() const;
    void setHSize(const Vector3 &hSize);
    void toggleDrawSolidState();
    bool collided(DynamicObject &dObj) const;
    virtual void draw() const = 0;
    virtual void update(double delta_t) = 0;

private:
    bool _drawSolidState;
    Vector3 _wSize;
    Vector3 _hSize;
};
} // Namespace Micromachines

#endif // GAMEOBJECT_H
