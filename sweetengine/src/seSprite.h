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
		seString	fileName;
		sePoint		*position;
		Collider	*collider;

	public:
		seSprite();
		~seSprite();
		seString FileName();
		seFloat X();
		seFloat Y();
		void DrawBoundingBox(); 
		virtual void Move();
		void SetColliderPosition(sePoint *_position);
	};
}

#endif