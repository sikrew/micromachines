#ifndef CHEERIO_H
#define CHEERIO_H



#include "obstacle.h"

namespace Micromachines
{
	class Cheerio : public Obstacle
	{
	public:
		Cheerio(Vector3 &position);
		~Cheerio();
		void draw() const;
		void update(double delta_t);
	};
} // namespace Micromachines

#endif // CHEERIO_H
