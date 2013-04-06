#include "seSprite.h"

using namespace Sweet;

seSprite::seSprite()
{
}


seSprite::~seSprite()
{
}

void seSprite::DrawBoundingBox()
{
}

void seSprite::move()
{

}

void seSprite::setColliderPosition(sePoint *_position)
{
	this->collider->setPosition(_position);
}
