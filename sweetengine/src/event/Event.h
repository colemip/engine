#ifndef SWEET_EVENT_H
#define SWEET_EVENT_H

//#include <SDL.h>

typedef enum _EventType 
{
	
} EventType;

namespace Sweet
{
	class Event
	{
	public:
		Event();
		~Event();
		bool OnInit();
		bool OnLoad();
		bool OnExit();
		void OnKeyDown();
		void OnKeyUp();
		void OnMouseDown();
		void OnMouseUp();
		void OnButtonDown();
		void OnButtonUp();
	};
}

#endif

