#include "seSprite.h"

using namespace Sweet;

seSprite::seSprite()
{
}


seSprite::~seSprite()
{
}

std::string seSprite::FileName()
{
	return this->fileName;
}

seFloat seSprite::X()
{
	return this->position->X();
}

seFloat seSprite::Y()
{
	return this->position->Y();
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
