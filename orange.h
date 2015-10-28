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

	double getDirection() const;
	void setDirection(const double direction);

	double getXRotation() const;
	void setXRotation(const double xRotation);

	double getYRotation() const;
	void setYRotation(const double yRotation);

	double getZRotation() const;
	void setZRotation(const double zRotation);

private:
	Vector3 *_position;

protected:
	double _direction = 0;
	double _xRotation = 0;
	double _yRotation = 0;
	double _zRotation = 0;

};
} // namespace Micromachines

#endif // ORANGE_H
