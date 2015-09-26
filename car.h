#ifndef CAR_H
#define CAR_H

#include "dynamicobject.h"

namespace Micromachines
{
class Car : public DynamicObject
{
public:
    Car();
    ~Car();
    void draw() const;
};
} // namespace Micromachines

#endif // CAR_H
