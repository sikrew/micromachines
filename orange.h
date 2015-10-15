#ifndef ORANGE_H
#define ORANGE_H

#include "obstacle.h"

namespace Micromachines
{
class Orange : public Obstacle
{
public:
    Orange(Vector3 *position);
    ~Orange();
    void draw() const;
	void update(double delta_t);

private:
	Vector3 *_position;
};
} // namespace Micromachines

#endif // ORANGE_H
