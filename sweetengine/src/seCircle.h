#ifndef SWEET_SECIRCLE_H
#define SWEET_SECIRCLE_H

#include "Types.h"
#include "sePoint.h"

namespace Sweet 
{
	class seCircle
	{
	private:
		sePoint center;
		seFloat radius;
	public:
		seCircle();
		~seCircle();
		sePoint getCenter();
		seFloat getRadius();
	};
}

#endif