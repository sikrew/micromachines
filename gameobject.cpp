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
