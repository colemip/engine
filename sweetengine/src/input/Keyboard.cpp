#include <iostream>
#include "Keyboard.h"

using namespace Sweet;

Keyboard::Keyboard()
{
}

Keyboard::~Keyboard()
{
}

void Keyboard::OnKeyDown(SDL_KeyboardEvent *kbe)
{
	std::cout << "Key down: " << SDL_GetKeyName( kbe->keysym.sym ) << std::endl;
}

void Keyboard::OnKeyUp(SDL_KeyboardEvent *kbe)
{
	std::cout << "Key up: " << SDL_GetKeyName( kbe->keysym.sym ) << std::endl;
}