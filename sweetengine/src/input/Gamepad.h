#ifndef SWEET_GAMEPAD_H
#define SWEET_GAMEPAD_H

#include <SDL/SDL.h>
#include <map>

namespace Sweet
{
	typedef enum _GamepadModel
	{
		XBOX360_WIRED = (1 << 0)
	} GamepadModel;

	typedef enum _GamepadAxis
	{
		LEFT_STICK_X = 0,
		LEFT_STICK_Y = 1,
		TRIGGERS = 2,
		RIGHT_STICK_X = 3,
		RIGHT_STICK_Y = 4
	} GamepadAxis;
	
	class Gamepad
	{
	private:
		SDL_Joystick *joystick;
		std::map<Uint8, Uint32> buttonsDown;		
	public:
		Gamepad();
		~Gamepad();
		void OnButtonDown(SDL_JoyButtonEvent *jbe);
		void OnButtonUp(SDL_JoyButtonEvent *jbe);
		void OnJoyAxisMotion(SDL_JoyAxisEvent *jae);
		bool IsButtonDown(Uint8 button);			
		int GetAxisValue(Sweet::GamepadAxis axis);
	};
}

#endif
