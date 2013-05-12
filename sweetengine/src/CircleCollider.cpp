#include "CircleCollider.h"

using namespace Sweet;

CircleCollider::CircleCollider()
{
}


CircleCollider::~CircleCollider()
{
}

bool CircleCollider::Collides(CircleCollider *collider)
{
	return Util::CircleIntersect(this, collider);
}
