#include "vector3.h"
#include <stdlib.h>
#include <iostream>
#include <cmath>

using namespace Micromachines;

Vector3::Vector3() : _x(0), _y(0), _z(0)
{ }

Vector3::Vector3(double x, double y, double z) : _x(x), _y(y), _z(z)
{ }

Vector3::Vector3(const Vector3 &v) : _x(v.getX()), _y(v.getY()), _z(v.getZ())
{ }

Vector3::Vector3(Vector3 &&v) : Vector3()
{
    swap(*this, v);
}

Vector3::~Vector3()
{ }

double Vector3::getX() const
{
    return _x;
}

double Vector3::getY() const
{
    return _y;
}

double Vector3::getZ() const
{
    return _z;
}

void Vector3::set(double x, double y, double z)
{
    _x = x;
    _y = y;
    _z = z;
}

double Vector3::length() const
{
    return sqrt(squaredLength());
}

double Vector3::squaredLength() const {
    return _x*_x + _y*_y + _z*_z;
}

void Vector3::normalize() {
    double len = length();

    _x = _x / len;
    _y = _y / len;
    _z = _z / len;
}

Vector3 Vector3::getNormalized() const
{
    double len = length();
    if(len == 0) {
        std::cout << "00000" << std::endl;
        return Vector3(_x, _y, _z);
    }

    return Vector3(_x / len, _y / len, _z / len);
}

Vector3 &Vector3::operator=(Vector3 rv)
{
    swap(*this, rv);

    return *this;
}

Vector3 &Vector3::operator+=(const Vector3 &rv)
{
    this->_x += rv.getX();
    this->_y += rv.getY();
    this->_z += rv.getZ();

    return *this;
}

Vector3 &Vector3::operator*=(const double r)
{
    this->_x *= r;
    this->_y *= r;
    this->_z *= r;

    return *this;
}

Vector3 &Vector3::operator-=(const Vector3 &rv)
{
    this->_x -= rv.getX();
    this->_y -= rv.getY();
    this->_z -= rv.getZ();

    return *this;
}
