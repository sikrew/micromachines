#ifndef BUTTER_H
#define BUTTER_H

#include "obstacle.h"

namespace Micromachines
{
class Butter : public Obstacle
{
public:
    Butter(Vector3 *position);
    ~Butter();
    void draw() const;
	void update(double delta_t);

private:
	Vector3 *_position;
	
};
} // namespace Micromachines

#endif // BUTTER_H
