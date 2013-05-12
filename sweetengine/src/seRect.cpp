#include "seRect.h"

using namespace Sweet;

seRect::seRect()
{
}


seRect::~seRect()
{
}

sePoint seRect::getTopLeft()
{
	return this->topLeft;
}

sePoint seRect::getBottomRight()
{
	return this->bottomRight;
}
