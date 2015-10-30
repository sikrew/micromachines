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
    double left = this->getPosition().getX()-_wSize;
    double right = this->getPosition().getX()+_wSize;

    double bottom = this->getPosition().getY()-_hSize;
    double top = this->getPosition().getY()+_hSize;

    double leftB = dObj.getPosition().getX()-dObj.getWSize();
    double rightB = dObj.getPosition().getX()+dObj.getWSize();

    double bottomB = dObj.getPosition().getY()-dObj.getHSize();
    double topB = dObj.getPosition().getY()+dObj.getHSize();


    if (left<rightB && right>leftB && bottom<topB && top>bottomB)
        return true;
    else
        return false;
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

void GameObject::setHSize(const double &hSize)
{
    _hSize = hSize;
}
