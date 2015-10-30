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
    bool getDrawSolidState() const;
    void setDrawSolidState(bool drawSolidState);
    double getWSize() const;
    void setWSize(const double &wSize);
    double getHSize() const;
    void setHSize(const double &hSize);
    void toggleDrawSolidState();
    virtual void draw() const = 0;
    virtual void update(double delta_t) = 0;

private:
    bool _drawSolidState;
    double _wSize;
    double _hSize;
};
} // Namespace Micromachines

#endif // GAMEOBJECT_H
