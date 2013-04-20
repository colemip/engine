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
	AddKey(kbe->keysym.sym);	
	std::cout << "Spaced pressed? " << IsKeyDown(SDLK_SPACE) << std::endl;
	std::cout << "list size: " << keysDown.size() << std::endl;
}

void Keyboard::OnKeyUp(SDL_KeyboardEvent *kbe)
{
	std::cout << "Key up: " << SDL_GetKeyName( kbe->keysym.sym ) << std::endl;	
	RemoveKey(kbe->keysym.sym);
	std::cout << "list size: " << keysDown.size() << std::endl;
}

void Keyboard::AddKey(SDLKey key)
{
	this->keysDown.push_back(key);
}

void Keyboard::RemoveKey(SDLKey key)
{
	std::list<SDLKey>::iterator iterator;	
	bool keyFound = false;

	// find key in list of pressed keys		
	for(iterator = keysDown.begin(); iterator != keysDown.end(); iterator++)
	{
		if((keyFound = (key == *iterator)))
			break;		
	}
	if(keyFound)
		keysDown.remove(*iterator);
}

bool Keyboard::IsKeyDown(SDLKey key)
{
	std::list<SDLKey>::iterator iterator;	

	// check if key is in list of pressed keys
	for(iterator = keysDown.begin(); iterator != keysDown.end(); iterator++)
	{
		if(key == *iterator)
			return true;
	}

	return false;
}