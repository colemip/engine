#ifndef SWEET_SESPRITE_H
#define SWEET_SESPRITE_H

#include "sePoint.h"
#include "CollisionEntity.h"

namespace Sweet
{
	class seSprite
	{
	private:
		sePoint *position;
		CollisionEntity *collider;

	public:
		seSprite();
		~seSprite();
		void DrawBoundingBox(); 
		virtual void move();
		void setColliderPosition(sePoint *_position);
	};
}

#endif