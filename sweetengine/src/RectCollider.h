#ifndef SWEET_RECTCOLLIDER_H
#define SWEET_RECTCOLLIDER_

#include "Collider.h"
#include "sePoint.h"
#include "Util.h"

namespace Sweet
{
	class RectCollider : public seRect, public Collider
	{
	public:
		RectCollider();
		RectCollider(sePoint _topLeft, sePoint _bottomRight);
		~RectCollider();		
		bool Collides(RectCollider *collider);
	};
}

#endif