#ifndef SWEET_RECTCOLLIDER_H
#define SWEET_RECTCOLLIDER_

#include "Types.h"
#include "Collider.h"
#include "sePoint.h"

namespace Sweet
{
	class RectCollider : public Collider
	{
	private:
		seFloat width;
		seFloat height;
	public:
		RectCollider();
		RectCollider(sePoint *_position, seFloat _width, seFloat _height);
		~RectCollider();
	};
}

#endif