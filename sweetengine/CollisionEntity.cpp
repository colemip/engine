#include "CollisionEntity.h"

using namespace Sweet;

CollisionEntity::CollisionEntity()
{
}

CollisionEntity::CollisionEntity(sePoint *_position, float _width, float _height)
{
	this->position = _position;
	this->width = _width;
	this->height = _height;
}

CollisionEntity::~CollisionEntity()
{
}
