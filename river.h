#ifndef RIVER_H
#define RIVER_H

#include "staticobject.h"

namespace Micromachines
{
class River : public StaticObject
{
public:
    River();
    ~River();
    void draw() const;
};
} // namespace Micromachines

#endif // RIVER_H
