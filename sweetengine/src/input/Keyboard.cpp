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
	seKeyEvent kEvent;
	kEvent.keyEvent = kbe;
	kEvent.duration - 0;
	AddKey(kEvent);		
}

void Keyboard::OnKeyUp(SDL_KeyboardEvent *kbe)
{
	std::cout << "Key up: " << SDL_GetKeyName( kbe->keysym.sym ) << std::endl;	
	RemoveKey(kbe->keysym.sym);
	std::cout << "list size: " << keysDown.size() << std::endl;
}

void Keyboard::AddKey(seKeyEvent kEvent)
{
	this->keysDown.push_back(&kEvent);
}

void Keyboard::RemoveKey(SDLKey key)
{	
	seKeyEvent *kEvent;

	if((kEvent = IsKeyDown(key)) != NULL)
		keysDown.remove(kEvent);
}

seKeyEvent* Keyboard::IsKeyDown(SDLKey key)
{
	std::list<seKeyEvent *>::iterator iterator;	

	// check if key is in list of pressed keys
	for(iterator = keysDown.begin(); iterator != keysDown.end(); iterator++)
	{
		if(key == (*iterator)->keyEvent->keysym.sym)
			return *iterator;
	}

	return NULL;
}

void Keyboard::UpdateKeyDownTime()
{
	std::list<seKeyEvent *>::iterator iterator;	

	// check if key is in list of pressed keys
	for(iterator = keysDown.begin(); iterator != keysDown.end(); iterator++)
	{
		(*iterator)->duration += (SDL_GetTicks() - ((seKeyEvent *)*iterator)->duration);
	}
}