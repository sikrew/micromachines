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
	void update(double delta_t);

	int loadGLtextures() const;
};
} // namespace Micromachines

#endif // ROADSIDE_H
