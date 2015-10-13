#ifndef CAR_H
#define CAR_H

#include "dynamicobject.h"

namespace Micromachines
{
enum Lean { NOLEAN, LEFT, RIGHT };

class Car : public DynamicObject
{
public:
    Car();
    Car(double max);
    ~Car();

    double getMaxAbsSpeed() const;
    void setMaxAbsSpeed(const double maxAbsSpeed);

    double getAcceleration() const;
    void setAcceleration(const double acceleration);

    double getDirection() const;
    void setDirection(const double direction);

    Lean getLean() const;
    void setLean(const Lean &lean);

    virtual void draw() const;
    virtual void update(double delta_t);


protected:
    double _maxAbsSpeed;
    double _acceleration;
    double _direction;
    Lean _lean;
};
} // namespace Micromachines

#endif // CAR_H
