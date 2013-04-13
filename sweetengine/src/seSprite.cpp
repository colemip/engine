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

void seSprite::Move()
{
	// update collider here
}

void seSprite::SetColliderPosition(sePoint *_position)
{
	this->collider->SetPosition(_position);
}
