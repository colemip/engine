#ifndef SWEET_COLLISIONENTITY_H
#define SWEET_COLLISIONENTITY_H

#include "sePoint.h"

namespace Sweet
{
	class Collider
	{
	private:
		sePoint *position;
		float width;
		float height;

	public:
		Collider();
		Collider(sePoint *_position, float _width, float _height);
		~Collider();
		void SetPosition(sePoint *_position);
	};
}

#endif