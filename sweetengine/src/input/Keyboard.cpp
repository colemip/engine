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
	seKeyEvent *kEvent = new seKeyEvent();
	//kEvent->keyEvent = kbe;
	//kEvent->keyEvent->keysym.sym = kbe->keysym.sym;	
	memcpy_s(&kEvent->keyEvent, sizeof(kEvent->keyEvent), &kbe, sizeof(kbe));
	kEvent->beginTicks = SDL_GetTicks();
	AddKey(kEvent);		
}

void Keyboard::OnKeyUp(SDL_KeyboardEvent *kbe)
{
	std::cout << "Key up: " << SDL_GetKeyName( kbe->keysym.sym ) << std::endl;	
	seKeyEvent *kEvent = IsKeyDown(kbe->keysym.sym);
	//std::cout << "Key '" << SDL_GetKeyName(kbe->keysym.sym) << "' pressed for " << (SDL_GetTicks() - kEvent->beginTicks) << " ms" << std::endl;
	RemoveKey(kbe->keysym.sym);	
}

void Keyboard::AddKey(seKeyEvent *kEvent)
{
	this->keysDown.push_back(kEvent);
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
		//std::cout << "setting iterator" << std::endl;
		std::cout << "Param key: " << SDL_GetKeyName(key) << std::endl;
		std::cout << "Iterator key: " << SDL_GetKeyName((*iterator)->keyEvent->keysym.sym) << std::endl;
		//std::cout << "Iterator ptr: " << (*iterator) << std::endl;
		//std::cout << "Iterator keyEvent: " << (*iterator)->keyEvent << std::endl;
		//std::cout << "Iterator keyEvent ksym: " << &((*iterator)->keyEvent->keysym) << std::endl;
		//std::cout << "Iterator keyEvent ksym.sym: " << (*iterator)->keyEvent->keysym.sym << std::endl;
		//std::cout << "Iterator keyEvent bTicks: " << (*iterator)->beginTicks << std::endl;
		//std::cout << "****************" << std::endl;
		if(key == (*iterator)->keyEvent->keysym.sym)
		{
			std::cout << "returning iterator" << std::endl;
			return *iterator;		
		}
	}

	//std::cout << "returning NULL iterator" << std::endl;
	return NULL;
}

std::list<seKeyEvent *>* Keyboard::getKeysDown()
{
	return &this->keysDown;
}