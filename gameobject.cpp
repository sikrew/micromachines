#include "gameobject.h"

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
