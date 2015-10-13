#ifndef VECTOR3_H
#define VECTOR3_H

#include <utility>

namespace Micromachines
{
class Vector3
{
private:
    double _x;
    double _y;
    double _z;
public:
    Vector3();
    Vector3(double x, double y, double z);
    Vector3(const Vector3 &v); //copy
    Vector3(Vector3 &&v); //move

    ~Vector3();

    double getX() const;
    double getY() const;
    double getZ() const;
    void set(double x,double y, double z);

    double length() const;
    double squaredLength() const;

    void normalize();
    Vector3 getNormalized() const;

    Vector3 & operator=(Vector3 rv);
    Vector3 & operator+=(const Vector3& rv);
    Vector3 & operator*=(const double r);
    Vector3 & operator-=(const Vector3& rv);

    friend void swap(Vector3& first, Vector3& second)
    {
        std::swap(first._x, second._x);
        std::swap(first._y, second._y);
        std::swap(first._z, second._z);
    }
};

inline Vector3 operator+(Vector3 lv, const Vector3& rv)
{
  lv += rv;
  return lv;
}

inline Vector3 operator*(Vector3 lv, const double r)
{
  lv *= r;
  return lv;
}

inline Vector3 operator-(Vector3 lv, const Vector3& rv)
{
  lv -= rv;
  return lv;
}

} // namespace Micromachines

#endif // VECTOR3_H
