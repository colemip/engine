#ifndef SWEET_COLLIDER_H
#define SWEET_COLLIDER_H

#include "sePoint.h"

namespace Sweet
{
	class Collider
	{
	protected:
		sePoint *position;		

	public:
		Collider();
		Collider(sePoint *_position);
		~Collider();
		void SetPosition(sePoint *_position);
	};
}

#endif