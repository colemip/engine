//Sample license text.
#include <iostream>
#include "Gamepad.h"

using namespace Sweet;

Gamepad::Gamepad()
{
	/* set joystick as first one detected */
	if(SDL_NumJoysticks() > 0)
	{
		this->joystick = SDL_JoystickOpen(0);
		std::cout << "Gamepad Name: " << SDL_JoystickName(0) << std::endl;
	}	
}


Gamepad::~Gamepad()
{
}


void Gamepad::OnButtonDown(SDL_JoyButtonEvent *jbe)
{	
	/* check that state is pressed */
	if(jbe->state == SDL_PRESSED)
	{
		std::cout << "Gamepad Button Down: " << std::endl;
		this->buttonsDown.insert(std::pair<Uint8, Uint32>(jbe->button, SDL_GetTicks()));
	}	
}


void Gamepad::OnButtonUp(SDL_JoyButtonEvent *jbe)
{
	/* check that state is released */
	if(jbe->state == SDL_RELEASED)
	{
		std::cout << "Gamepad Button Up" << std::endl;
		this->buttonsDown.erase(jbe->button);
	}	
}

void Gamepad::OnJoyAxisMotion(SDL_JoyAxisEvent *jae)
{	
	int numAxes = SDL_JoystickNumAxes(this->joystick);

	for(int i=0; i<numAxes; i++)
	{
		switch(i)
		{
		case LEFT_STICK_X:
			std::cout << "Axis " << i << " value: " << GetAxisValue(LEFT_STICK_X) << std::endl;			
			break;
		case LEFT_STICK_Y:
			std::cout << "Axis " << i << " value: " << GetAxisValue(LEFT_STICK_Y) << std::endl;			
			break;
		case RIGHT_STICK_X:
			std::cout << "Axis " << i << " value: " << GetAxisValue(RIGHT_STICK_X) << std::endl;			
			break;
		case RIGHT_STICK_Y:
			std::cout << "Axis " << i << " value: " << GetAxisValue(RIGHT_STICK_Y) << std::endl;			
			break;
		}
	}	
}

int Gamepad::GetAxisValue(Sweet::GamepadAxis axis)
{
	return SDL_JoystickGetAxis(this->joystick, axis);
}

bool Gamepad::IsButtonDown(Uint8 button)
{
	std::map<SDLKey, Uint32>::iterator mapIterator;		

	// check if key is in list of pressed keys
	return (this->buttonsDown.find(button) != this->buttonsDown.end());
}

