#ifndef SWEET_COLLISIONENTITY_H
#define SWEET_COLLISIONENTITY_H

#include "sePoint.h"

namespace Sweet
{
	class CollisionEntity
	{
	private:
		sePoint *position;
		float width;
		float height;

	public:
		CollisionEntity();
		CollisionEntity(sePoint *_position, float _width, float _height);
		~CollisionEntity();
		void setPosition(sePoint *_position);
	};
}

#endif