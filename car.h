#ifndef CAR_H
#define CAR_H

#include "dynamicobject.h"

namespace Micromachines
{
enum LeanState { NOLEAN, LEFT, RIGHT };

enum AccelerationState { NONE, SPEEDING, BRAKING, MAXSPEED, NONEREVERSE, SPEEDREVERSE, REVERSE, MAXREVERSE, FRONTCOLLIDED, BACKCOLLIDED };

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

    Vector3 getVDirection() const;
    void setVDirection(const Vector3 &vDirection);

    LeanState getLeanState() const;
    void setLeanState(const LeanState &leanState);

    AccelerationState getAccState() const;
    void setAccState(const AccelerationState &accState);

	void toggleState();

    virtual void draw() const;
    virtual void update(double delta_t);


protected:
    double _maxAbsSpeed;
    double _maxReverseSpeed;
    double _acceleration = 0;
    double _direction = 0;
    double _turnAngle = 0.1;
    double _speedingAcc;
    double _brakingAcc;
    double _friction;
    Vector3 _vDirection;
    LeanState _leanState = NOLEAN;
    AccelerationState _accState = NONE;
};
} // namespace Micromachines

#endif // CAR_H
