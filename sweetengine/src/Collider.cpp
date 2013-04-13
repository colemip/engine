#include "Collider.h"

using namespace Sweet;

Collider::Collider()
{
}

Collider::Collider(sePoint *_position)
{
	this->position = _position;	
}

Collider::~Collider()
{
}

void Collider::SetPosition(sePoint *_position)
{
	this->position = _position;
}
