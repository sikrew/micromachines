#ifndef BUTTER_H
#define BUTTER_H

#include "obstacle.h"

namespace Micromachines
{
class Butter : public Obstacle
{
public:
    Butter();
    ~Butter();
    void draw() const;
};
} // namespace Micromachines

#endif // BUTTER_H
