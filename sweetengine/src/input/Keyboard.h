#ifndef SWEET_KEYBOARD_H
#define SWEET_KEYBOARD_H

#include <SDL/SDL.h>
#include <list>
#include <map>

namespace Sweet
{
	/*typedef struct seKeyEvent
	{
		SDL_KeyboardEvent keyEvent;
		Uint32 beginTicks;
	} KeyEvent;*/

	class Keyboard
	{
	private:
		//std::list<seKeyEvent *> keysDown;
		std::map<SDLKey, Uint32> keysDown;
	public:
		Keyboard();
		~Keyboard();
		void OnKeyDown(SDL_KeyboardEvent *kbe);
		void OnKeyUp(SDL_KeyboardEvent *kbe);		
		bool IsKeyDown(SDLKey key);
		std::map<SDLKey, Uint32>* getKeysDown();
	private:
		void AddKey(SDLKey key, Uint32 time);
		void RemoveKey(SDLKey key);
		void PrintKeys();				
	};	
}

#endif

