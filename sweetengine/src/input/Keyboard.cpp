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
	AddKey(kbe->keysym.sym, SDL_GetTicks());		
}

void Keyboard::OnKeyUp(SDL_KeyboardEvent *kbe)
{
	std::cout << "Key up: " << SDL_GetKeyName( kbe->keysym.sym ) << std::endl;		
	RemoveKey(kbe->keysym.sym);	
}

void Keyboard::AddKey(SDLKey key, Uint32 time)
{
	keysDown.insert(std::pair<SDLKey, Uint32>(key, time));
}

void Keyboard::RemoveKey(SDLKey key)
{	
	keysDown.erase(key);
}

bool Keyboard::IsKeyDown(SDLKey key)
{
	std::map<SDLKey, Uint32>::iterator mapIterator;		

	// check if key is in list of pressed keys
	return (this->keysDown.find(key) != this->keysDown.end());
}

std::map<SDLKey, Uint32>* Keyboard::getKeysDown()
{
	return &this->keysDown;
}