#include <iostream>
#include "Mouse.h"

using namespace Sweet;

Mouse::Mouse()
{
	std::cout << "Mouse created" << std::endl;
}


Mouse::~Mouse()
{
}

void Mouse::Init()
{
}

void Mouse::OnMouseMove(SDL_MouseMotionEvent *mme)
{
	std::cout << "Mouse at (" <<  mme->x << ", " << mme->y << ")" << std::endl;
}