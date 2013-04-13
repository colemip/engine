#ifndef SWEET_ENGINE_H
#define SWEET_ENGINE_H

#include <string>
#include <SDL.h>
#include <glut.h>
#include "input\Keyboard.h"
#include "input\Mouse.h"
#include "input\Gamepad.h"
#include "event\Event.h"
#include "GLWorkbench.h"


namespace Sweet
{
	class Engine
	{
	private:
		std::string version;
		static Sweet::Engine *instance;
		bool running;
		Sweet::Keyboard *keyboard;
		Sweet::Mouse *mouse_1;
		Sweet::Gamepad *gamepad_1;

	public:
		Engine();
		~Engine();
		void Init();
		void StartUp();
		int Update();
		void Render();
		void Run();
		void CleanUp();
		void Exit();
		void Message();
		void OnEvent(Sweet::Event *e);
		void OnSDLEvent(SDL_Event *e);
		int PollEvent(Sweet::Event *e);
		/* OpenGL */
		void InitOpenGL();		
		//void RunGLWorkbench(int argc, char **argv);
	};
}

#endif