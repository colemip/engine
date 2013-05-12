#ifndef SWEET_UTIL_H
#define SWEET_UTIL_H

#include <math.h>
#include "seRect.h"
#include "seCircle.h"

namespace Sweet
{
	class Util 
	{
	public:
		static bool AABBRectIntersect(seRect *rect1, seRect *rect2);
		static bool CircleIntersect(seCircle *circle1, seCircle *circle2);
		static seFloat PointDistance(sePoint p1, sePoint p2);
	};
}

#endif