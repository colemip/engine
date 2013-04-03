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
	//std::cout << "Gamepad Button Down: " << jbe->button << std::endl;

	/*for(int i=0; i<SDL_JoystickNumButtons(this->joystick); i++)
		if(SDL_JoystickGetButton(this->joystick, i))*/
	if(jbe->state == SDL_PRESSED)
		std::cout << "Gamepad Button Down" << std::endl;
}


void Gamepad::OnButtonUp(SDL_JoyButtonEvent *jbe)
{
	/*for(int i=0; i<SDL_JoystickNumButtons(this->joystick); i++)
		if(SDL_JoystickGetButton(this->joystick, i))*/
	if(jbe->state == SDL_RELEASED)
		std::cout << "Gamepad Button Up" << std::endl;

}

void Gamepad::OnJoyAxisMotion(SDL_JoyAxisEvent *jae)
{	
	int numAxes = SDL_JoystickNumAxes(this->joystick);

	for(int i=0; i<numAxes; i++)
	{
		switch(i)
		{
		case GamepadAxis::LEFT_STICK_LR:
			std::cout << "Axis " << i << " value: " << GetAxisValue(LEFT_STICK_LR) << std::endl;
			break;
		case GamepadAxis::LEFT_STICK_UD:
			std::cout << "Axis " << i << " value: " << GetAxisValue(LEFT_STICK_UD) << std::endl;
			break;
		case GamepadAxis::RIGHT_STICK_LR:
			std::cout << "Axis " << i << " value: " << GetAxisValue(RIGHT_STICK_LR) << std::endl;
			break;
		case GamepadAxis::RIGHT_STICK_UD:
			std::cout << "Axis " << i << " value: " << GetAxisValue(RIGHT_STICK_UD) << std::endl;
			break;
		}
	}	
	/* Left, right axis movement */
	//if(jae->axis == 0)
	//{
	//	std::cout << "Joystick value: " << jae->value << std::endl;
	//}

	///* Up, down axis movement */
	//if(jae->axis == 1)
	//{
	//	std::cout << "Joystick value: " << jae->value << std::endl;
	//}
}

int Gamepad::GetAxisValue(Sweet::GamepadAxis axis)
{
	return SDL_JoystickGetAxis(this->joystick, axis);
}
