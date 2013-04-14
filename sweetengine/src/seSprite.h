#ifndef SWEET_SESPRITE_H
#define SWEET_SESPRITE_H

#include <string>
#include "sePoint.h"
#include "Collider.h"
#include "Types.h"

namespace Sweet
{
	class seSprite
	{
	private:
		std::string	fileName;
		sePoint		*position;
		Collider	*collider;

	public:
		seSprite();
		~seSprite();
		std::string FileName();
		seFloat X();
		seFloat Y();
		void DrawBoundingBox(); 
		virtual void Move();
		void SetColliderPosition(sePoint *_position);
	};
}

#endif