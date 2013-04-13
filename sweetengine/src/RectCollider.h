#ifndef SWEET_RECTCOLLIDER_H
#define SWEET_RECTCOLLIDER_

#include "Collider.h"
#include "sePoint.h"

namespace Sweet
{
	class RectCollider : public Collider
	{
	private:
		float width;
		float height;
	public:
		RectCollider();
		RectCollider(sePoint *_position, float _width, float _height);
		~RectCollider();
	};
}

#endif