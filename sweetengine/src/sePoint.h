#ifndef SWEET_SEPOINT_H
#define SWEET_SEPOINT_H

#include "Types.h"

namespace Sweet
{
	class sePoint
	{
	private: 
		seFloat x;
		seFloat y;
		seFloat z;
	public:
		sePoint();
		sePoint(seFloat _x, seFloat _y, seFloat _z);
		~sePoint();
		seFloat X();
		seFloat Y();
		seFloat Z();
		seFloat DistanceToPoint(sePoint *otherPoint);
	};
}

#endif