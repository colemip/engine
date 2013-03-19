#include <iostream>
#include "Gamepad.h"

using namespace Sweet;

Gamepad::Gamepad()
{
	if(SDL_NumJoysticks() > 0)
		this->joystick = SDL_JoystickOpen(0);
}


Gamepad::~Gamepad()
{
}


void Gamepad::OnButtonDown(SDL_JoyButtonEvent *jbe)
{
	//std::cout << "Gamepad Button Down: " << jbe->button << std::endl;

	for(int i=0; i<SDL_JoystickNumButtons(this->joystick); i++)
		if(SDL_JoystickGetButton(this->joystick, i))
			std::cout << "Gamepad Button " << i << " Down" << std::endl;
}


void Gamepad::OnButtonUp(SDL_JoyButtonEvent *jbe)
{
	//std::cout << "Gamepad Button Up: " << jbe->button << std::endl;
}
