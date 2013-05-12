#ifndef SWEET_CIRCLECOLLIDER_H
#define SWEET_CIRCLECOLLIDER_H

#include "seCircle.h"
#include "Collider.h"
#include "Util.h"

namespace Sweet
{
	class CircleCollider : public seCircle, public Collider
	{
	public:
		CircleCollider();
		~CircleCollider();
		bool Collides(CircleCollider *collider);
	};
}

#endif