#ifndef SWEET_MOUSE_H
#define SWEET_MOUSE_H

#include <SDL.h>

namespace Sweet 
{
	class Mouse
	{
	public:
		Mouse();
		~Mouse();
		void Init();
		void OnMouseMove(SDL_MouseMotionEvent *mme);
	};
}

#endif
