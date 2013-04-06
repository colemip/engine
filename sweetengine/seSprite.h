#ifndef SWEET_SESPRITE_H
#define SWEET_SESPRITE_H

#include "sePoint.h"

namespace Sweet
{
	class seSprite
	{
	private:
		sePoint *position;

	public:
		seSprite();
		~seSprite();
		void DrawBoundingBox(); 
	};
}

#endif