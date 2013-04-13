#include "sePoint.h"

using namespace Sweet;

sePoint::sePoint()
{
}

sePoint::sePoint(float _x, float _y, float _z = 0)
{
	this->x = _x;
	this->y = _y;
	this->z = _z;
}

sePoint::~sePoint()
{
}

float sePoint::DistanceToPoint(sePoint *otherPoint)
{
	return 0.0;
}
