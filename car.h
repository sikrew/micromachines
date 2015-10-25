#ifndef CAR_H
#define CAR_H

#include "dynamicobject.h"

namespace Micromachines
{
enum LeanState { NOLEAN, LEFT, RIGHT };

enum AccelerationState { NONE, SPEEDING, BRAKING, MAXSPEED, STOPPED };

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

    double getTurnAngle() const;
    void setTurnAngle(const double turnAngle);

    double getSpeedingAcc() const;
    void setSpeedingAcc(const double speedingAcc);

    double getBrakingAcc() const;
    void setBrakingAcc(const double brakingAcc);

    LeanState getLeanState() const;
    void setLeanState(const LeanState &leanState);

    AccelerationState getAccState() const;
    void setAccState(const AccelerationState &accState);

	void toggleState();

    virtual void draw() const;
    virtual void update(double delta_t);

protected:
    double _maxAbsSpeed;
    double _acceleration = 0;
    double _direction = 0;
    double _turnAngle = 3;
    double _speedingAcc;
    double _brakingAcc;
    LeanState _leanState = NOLEAN;
    AccelerationState _accState = STOPPED;
};
} // namespace Micromachines

#endif // CAR_H
