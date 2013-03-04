#ifndef SWEET_EVENT_H
#define SWEET_EVENT_H

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
		void OnKeyPress();
		void OnMouseDown();
		void OnMouseUp();
		void OnButtonPress();
	};
}

#endif

