#ifndef SWEET_GAMEPAD_H
#define SWEET_GAMEPAD_H

#include <SDL.h>

typedef enum _GamepadModel
{
	XBOX360_WIRED = (1 << 0)
} GamepadModel;

namespace Sweet
{
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
	};
}

#endif
