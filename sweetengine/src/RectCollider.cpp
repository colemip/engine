#include "RectCollider.h"

using namespace Sweet;

RectCollider::RectCollider()
{
}
RectCollider::RectCollider(sePoint *_position, seFloat _width, seFloat _height)
{
	this->position = _position;
	this->width = _width;
	this->height = _height;
}

RectCollider::~RectCollider()
{
}
