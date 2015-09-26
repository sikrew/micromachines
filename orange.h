#ifndef ORANGE_H
#define ORANGE_H

#include "obstacle.h"

namespace Micromachines
{
class Orange : public Obstacle
{
public:
    Orange();
    ~Orange();
    void draw() const;
};
} // namespace Micromachines

#endif // ORANGE_H
