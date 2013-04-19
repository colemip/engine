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

seFloat sePoint::X()
{
	return this->x;
}

void sePoint::X(seFloat value)
{
	this->x = value;
}

seFloat sePoint::Y()
{
	return this->y;
}

void sePoint::Y(seFloat value)
{
	this->y = value;
}

seFloat sePoint::Z()
{
	return this->z;
}

seFloat sePoint::DistanceToPoint(sePoint *otherPoint)
{
	return 0.0;
}
