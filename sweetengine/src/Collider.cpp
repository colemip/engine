#include "Collider.h"

using namespace Sweet;

Collider::Collider()
{
}

Collider::Collider(sePoint *_position, float _width, float _height)
{
	this->position = _position;
	this->width = _width;
	this->height = _height;
}

Collider::~Collider()
{
}

void Collider::SetPosition(sePoint *_position)
{
	this->position = _position;
}
