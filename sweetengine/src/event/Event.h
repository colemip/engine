#ifndef SWEET_EVENT_H
#define SWEET_EVENT_H

#include <SDL/SDL.h>

#define EVENT_SDL (EVENT_KEYDOWN | EVENT_KEYUP)

typedef enum _EventType 
{
	EVENT_KEYDOWN,
	EVENT_KEYUP
} EventType;



namespace Sweet
{
	class Event
	{
	private: 
		EventType type;
	public:
		Event();
		~Event();
		EventType getType();
		bool OnInit();
		bool OnLoad();
		bool OnExit();
		void OnKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode);
		void OnKeyUp();
		void OnMouseDown();
		void OnMouseUp();
		void OnButtonDown();
		void OnButtonUp();
	};
}

#endif

