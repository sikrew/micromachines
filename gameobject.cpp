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

double GameObject::getWSize() const
{
    return _wSize;
}

void GameObject::setWSize(const double &wSize)
{
    _wSize = wSize;
}

double GameObject::getHSize() const
{
    return _hSize;
}

void Micromachines::GameObject::setHSize(const double & hSize)
{
}

