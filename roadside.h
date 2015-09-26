#ifndef ROADSIDE_H
#define ROADSIDE_H

#include "staticobject.h"

namespace Micromachines
{
class Roadside : public StaticObject
{
public:
    Roadside();
    ~Roadside();
    void draw() const;
};
} // namespace Micromachines

#endif // ROADSIDE_H
