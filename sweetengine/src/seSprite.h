#ifndef SWEET_SESPRITE_H
#define SWEET_SESPRITE_H

#include "sePoint.h"
#include "Collider.h"
#include "Types.h"

namespace Sweet
{
	class seSprite
	{
	private:
		sePoint *position;
		Collider *collider;

	public:
		seSprite();
		~seSprite();
		void DrawBoundingBox(); 
		virtual void Move();
		void SetColliderPosition(sePoint *_position);
	};
}

#endif