#ifndef VECTOR3_H
#define VECTOR3_H

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
    ~Vector3();

    double getX() const;
    double getY() const;
    double getZ() const;
    void set(double x,double y, double z);
    Vector3 operator=(const Vector3 &);
    Vector3 operator*(double num);
    Vector3 operator+(const Vector3 &);
    Vector3 operator-(const Vector3 &);
    Vector3 operator-();
};
} //namespace Micromachines

#endif // VECTOR3_H
