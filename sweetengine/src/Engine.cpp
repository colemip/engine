#include <iostream>
#include "Engine.h"

using namespace Sweet;

Engine::Engine()
{
	std::cout << "Constructing Engine" << std::endl;
	this->keyboard = new Sweet::Keyboard();
	this->mouse_1 = new Sweet::Mouse();
}


Engine::~Engine()
{
}

void Engine::Init()
{
	this->running = true;
	SDL_Init( SDL_INIT_VIDEO );
	SDL_SetVideoMode( 320, 200, 0, 0 );
	SDL_EnableUNICODE( 1 );
}

int Engine::Update()
{
	return 0;
}

void Engine::StartUp()
{
	Sweet::Event event;

	while(this->running)
	{
		// do engine things

		// listen for input
		while(PollEvent(&event))
		{
			//OnEvent(&event);
		}

		//this->running = false;
	}

	CleanUp();
	SDL_Quit();
}

void Engine::CleanUp()
{
	this->keyboard = NULL;
	delete this->keyboard;
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
	switch(e->type)
	{
		case SDL_KEYUP:
			this->keyboard->OnKeyDown(&e->key);
			break;
		case SDL_KEYDOWN:
			this->keyboard->OnKeyUp(&e->key);
			break;
		case SDL_QUIT:
			this->running = false;
			break;
		case SDL_MOUSEMOTION:
			this->mouse_1->OnMouseMove(&e->motion);
			break;
		case SDL_MOUSEBUTTONDOWN:
			this->mouse_1->OnMouseDown(&e->button);
			break;
		default: 
			break;
	}
}
