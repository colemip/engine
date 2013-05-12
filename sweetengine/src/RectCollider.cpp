#include "RectCollider.h"

using namespace Sweet;

RectCollider::RectCollider()
{
}
RectCollider::RectCollider(sePoint _topLeft, sePoint _bottomRight)
{
	// TODO: review behavor of assigning sePoint
	// OPTIONAL:  override operator= for sePoint
	this->topLeft = _topLeft;
	this->bottomRight = _bottomRight;	
}

RectCollider::~RectCollider()
{
}

bool RectCollider::Collides(RectCollider *collider)
{
	return Util::AABBRectIntersect(this, collider);
}
