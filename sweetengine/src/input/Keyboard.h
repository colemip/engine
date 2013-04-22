#ifndef SWEET_KEYBOARD_H
#define SWEET_KEYBOARD_H

#include <SDL.h>
#include <list>

namespace Sweet
{
	typedef struct seKeyEvent
	{
		SDL_KeyboardEvent *keyEvent;
		Uint32 beginTicks;
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
		seKeyEvent* IsKeyDown(SDLKey key);
		std::list<seKeyEvent *>* getKeysDown();
	private:
		void AddKey(seKeyEvent *key);
		void RemoveKey(SDLKey key);
		void PrintKeys();				
	};	
}

#endif

