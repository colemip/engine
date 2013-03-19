#ifndef SWEET_GAMEPAD_H
#define SWEET_GAMEPAD_H

#include <SDL.h>

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
	};
}

#endif
