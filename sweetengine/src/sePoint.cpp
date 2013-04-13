#include "sePoint.h"

using namespace Sweet;

sePoint::sePoint()
{
}

sePoint::sePoint(seFloat _x, seFloat _y, seFloat _z = 0)
{
	this->x = _x;
	this->y = _y;
	this->z = _z;
}

sePoint::~sePoint()
{
}

seFloat sePoint::DistanceToPoint(sePoint *otherPoint)
{
	return 0.0;
}
