#ifndef SWEET_SEPOINT_H
#define SWEET_SEPOINT_H

namespace Sweet
{
	class sePoint
	{
	private: 
		float x;
		float y;
		float z;
	public:
		sePoint();
		sePoint(float _x, float _y, float _z);
		~sePoint();
	};
}

#endif