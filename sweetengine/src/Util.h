#ifndef SWEET_UTIL_H
#define SWEET_UTIL_H

#include "seRect.h"

namespace Sweet
{
	class Util 
	{
	public:
		static bool AABBRectIntersect(seRect *rect1, seRect *rect2);
	};
}

#endif