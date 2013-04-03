#ifndef SWEET_GAMEPAD_H
#define SWEET_GAMEPAD_H

#include <SDL.h>

namespace Sweet
{
	typedef enum _GamepadModel
	{
		XBOX360_WIRED = (1 << 0)
	} GamepadModel;

	typedef enum _GamepadAxis
	{
		LEFT_STICK_LR = 0,
		LEFT_STICK_UD = 1,
		RIGHT_STICK_LR = 2,
		RIGHT_STICK_UD = 3,
		/*LEFT_TRIGGER = 2,
		RIGHT_TRIGGER = 3*/
	} GamepadAxis;

	class Gamepad
	{
	private:
		SDL_Joystick *joystick;

	public:
		Gamepad();
		~Gamepad();
		void OnButtonDown(SDL_JoyButtonEvent *jbe);
		void OnButtonUp(SDL_JoyButtonEvent *jbe);
		void OnJoyAxisMotion(SDL_JoyAxisEvent *jae);
	private:
		int GetAxisValue(Sweet::GamepadAxis axis);
	};
}

#endif
