#ifndef SWEET_KEYBOARD_H
#define SWEET_KEYBOARD_H

#include <SDL.h>
#include <list>

namespace Sweet
{
	class Keyboard
	{
	private:
		std::list<SDLKey> keysDown;
	public:
		Keyboard();
		~Keyboard();
		void OnKeyDown(SDL_KeyboardEvent *kbe);
		void OnKeyUp(SDL_KeyboardEvent *kbe);
	private:
		void AddKey(SDLKey key);
		void RemoveKey(SDLKey key);
		void PrintKeys();
		bool IsKeyDown(SDLKey key);
	};

	typedef struct KeyEvent
	{
		SDLKey key;
		Uint32 duration;
	} KeyEvent;
}

#endif

