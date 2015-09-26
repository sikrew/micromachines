#include "vector3.h"

using namespace Micromachines;

Vector3::Vector3() : _x(0), _y(0), _z(0)
{ }

Vector3::Vector3(double x, double y, double z) : _x(x), _y(y), _z(z)
{ }

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

Vector3 Vector3::operator=(const Vector3 &v)
{
    return Vector3(v.getX(), v.getY(), v.getZ());
}

Vector3 Vector3::operator*(double num)
{
    return Vector3(_x * num, _y * num, _z * num);
}

Vector3 Vector3::operator+(const Vector3 &v)
{
    return Vector3(_x + v.getX(), _y + v.getY(), _z + v.getZ());
}

Vector3 Vector3::operator-(const Vector3 &v)
{
    return Vector3(_x - v.getX(), _y - v.getY(), _z - v.getZ());
}

Vector3 Vector3::operator-()
{
    return Vector3(-_x, -_y, -_z);
}
