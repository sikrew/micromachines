#include "gameobject.h"
#include "dynamicobject.h"

using namespace Micromachines;

GameObject::GameObject()
{
}

GameObject::~GameObject()
{

}

bool GameObject::getDrawSolidState() const
{
    return _drawSolidState;
}

void GameObject::setDrawSolidState(bool drawSolidState)
{
    _drawSolidState = drawSolidState;
}

void GameObject::toggleDrawSolidState()
{
    _drawSolidState = !_drawSolidState;
}

bool GameObject::collided(DynamicObject &dObj) const
{
    double x1 = this->getPosition().getX()-_wSize;
    double x2 = this->getPosition().getX()+_wSize;

    double y1 = this->getPosition().getY()-_hSize;
    double y2 = this->getPosition().getY()+_hSize;

    double dx1 = dObj.getPosition().getX()-dObj.getWSize();
    double dx2 = dObj.getPosition().getX()+dObj.getWSize();

    double dy1 = dObj.getPosition().getY()-dObj.getHSize();
    double dy2 = dObj.getPosition().getY()+dObj.getHSize();


    if (x2<dx1 || dx2<x1 || y1<dy2 || dy1<y2)
        return false;
    else
        return true;
}

Vector3 GameObject::getWSize() const
{
    return _wSize;
}

void GameObject::setWSize(const Vector3 &wSize)
{
    _wSize = wSize;
}

Vector3 GameObject::getHSize() const
{
    return _hSize;
}

void GameObject::setHSize(const Vector3 &hSize)
{
    _hSize = hSize;
}
