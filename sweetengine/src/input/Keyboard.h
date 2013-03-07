#ifndef SWEET_KEYBOARD_H
#define SWEET_KEYBOARD_H

#include <SDL.h>

namespace Sweet
{
	class Keyboard
	{
	public:
		Keyboard();
		~Keyboard();
		void OnKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode);
		void OnKeyUp(SDLKey sym, SDLMod mod, Uint16 unicode);
	};
}

#endif

