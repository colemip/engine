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
	//std::cout << "Mouse at (" <<  mme->x << ", " << mme->y << ")" << std::endl;
}

void Mouse::OnMouseDown(SDL_MouseButtonEvent *mbe)
{
	if(mbe->state == SDL_PRESSED && mbe->type == SDL_MOUSEBUTTONDOWN)
	{
		switch(mbe->button)
		{
			case SDL_BUTTON_LEFT:
				std::cout << "Left Mouse down at (" << mbe->x << ", "  << mbe->y << ")" << std::endl;
				break;
			case SDL_BUTTON_MIDDLE:
				std::cout << "Middle Mouse down at (" << mbe->x << ", "  << mbe->y << ")" << std::endl;
				break;
			case SDL_BUTTON_RIGHT:
				std::cout << "Right Mouse down at (" << mbe->x << ", "  << mbe->y << ")" << std::endl;
				break;
			case SDL_BUTTON_WHEELUP:
				std::cout << "Mouse Wheel Up down at (" << mbe->x << ", "  << mbe->y << ")" << std::endl;
				break;
			case SDL_BUTTON_WHEELDOWN:
				std::cout << "Mouse Wheel Down down at (" << mbe->x << ", "  << mbe->y << ")" << std::endl;
				break;
		}
	}
}

void Mouse::OnMouseUp(SDL_MouseButtonEvent *mbe)
{
	if(mbe->state == SDL_RELEASED && mbe->type == SDL_MOUSEBUTTONUP)
	{
		switch(mbe->button)
		{
			case SDL_BUTTON_LEFT:
				std::cout << "Left Mouse up at (" << mbe->x << ", "  << mbe->y << ")" << std::endl;
				break;
			case SDL_BUTTON_MIDDLE:
				std::cout << "Middle Mouse up at (" << mbe->x << ", "  << mbe->y << ")" << std::endl;
				break;
			case SDL_BUTTON_RIGHT:
				std::cout << "Right Mouse up at (" << mbe->x << ", "  << mbe->y << ")" << std::endl;
				break;
		}
	}
}