#ifndef SWEET_KEYBOARD_H
#define SWEET_KEYBOARD_H

#include <SDL.h>
#include <list>

namespace Sweet
{
	typedef struct seKeyEvent
	{
		SDL_KeyboardEvent *keyEvent;
		Uint32 duration;
	} KeyEvent;

	class Keyboard
	{
	private:
		std::list<seKeyEvent *> keysDown;
	public:
		Keyboard();
		~Keyboard();
		void OnKeyDown(SDL_KeyboardEvent *kbe);
		void OnKeyUp(SDL_KeyboardEvent *kbe);
		void UpdateKeyDownTime();
	private:
		void AddKey(seKeyEvent *key);
		void RemoveKey(SDLKey key);
		void PrintKeys();
		seKeyEvent* IsKeyDown(SDLKey key);		
	};	
}

#endif

