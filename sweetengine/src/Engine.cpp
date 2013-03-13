#include <iostream>
#include "Engine.h"

using namespace Sweet;

Engine::Engine()
{
	std::cout << "Constructing Engine" << std::endl;
	/*if(instance == NULL)
		instance = new Sweet::Engine();*/
	this->keyboard = new Sweet::Keyboard();
}


Engine::~Engine()
{
}

int Engine::Update()
{
	while(this->running)
	{
		// do engine things

		// listen for input
		Sweet::Event event;
		while(PollEvent(&event))
		{
			//instance->OnEvent(&event);
			OnEvent(&event);
		}
	}

	return 0;
}

int Engine::PollEvent(Sweet::Event *e)
{
	/* SDL Events */
	SDL_Event sdl_e; 
	while(SDL_PollEvent(&sdl_e))
	{
		OnSDLEvent(&sdl_e);
	}

	return 0;
}

void Engine::OnEvent(Sweet::Event *e)
{

}

void Engine::OnSDLEvent(SDL_Event *e)
{
	//Dummy *d = new Dummy();

	switch(e->type)
	{
		case SDL_KEYUP:
			this->keyboard->OnKeyDown(&e->key);
			break;
		case SDL_KEYDOWN:
			keyboard->OnKeyUp(&e->key);
			break;
	}
}
