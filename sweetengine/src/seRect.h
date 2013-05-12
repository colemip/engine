#ifndef SWEET_SERECT_H
#define SWEET_SERECT_H

#include "sePoint.h"

namespace Sweet
{
	class seRect
	{
	protected:
		sePoint topLeft;
		sePoint bottomRight;
	public:
		seRect();
		~seRect();
		sePoint getTopLeft();
		sePoint getBottomRight();
	};
}

#endif
