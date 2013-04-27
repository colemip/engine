#include <iostream>
#include <list>
#include <iterator>
#include "Engine.h"

using namespace Sweet;

Engine::Engine()
{
	std::cout << "Constructing Engine" << std::endl;
	this->keyboard = new Sweet::Keyboard();
	this->mouse_1 = new Sweet::Mouse();	
	this->glWorkbench = new Sweet::GLWorkbench();
	this->sprite = new Sweet::seSprite();
}


Engine::~Engine()
{
}

void Engine::Init()
{
	this->running = true;
	SDL_Init( SDL_INIT_VIDEO | SDL_INIT_JOYSTICK );
	SDL_SetVideoMode( 640, 480, 32, SDL_OPENGL);
	SDL_EnableUNICODE( 1 );	

	/* Enable joysticks */
	SDL_JoystickEventState(SDL_ENABLE);
	this->gamepad_1 = new Sweet::Gamepad();
}

int Engine::Update()
{
	return 0;
}

void Engine::StartUp()
{		
	/* Startup messages */
	for(int i=0; i<SDL_NumJoysticks(); i++)
		std::cout << "Joystick '" << SDL_JoystickName(i) << "' Detected" << std::endl;


	Sweet::Event event;
	
	while(this->running)
	{		
		//std::cout << "Running for " << SDL_GetTicks() << std::endl;
		// do engine things
		this->sprite->Draw();			
		
		// listen for input
		while(PollEvent(&event));				
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
	seKeyEvent *kEvent;
	seFloat spriteX = 0.0f;

	while(SDL_PollEvent(&sdl_e))
	{
		//std::cout << "polling for SDL event" << std::endl;
		OnSDLEvent(&sdl_e);				
	}

	//std::cout << "PollEvent: " << sdl_e.key.keysym.sym << std::endl;

	/* check for arrow key press to move sprite */		
	size_t keysDownSize = this->keyboard->getKeysDown()->size();
	//std::cout << "Keys Down Count (Engine): " << keysDownSize << std::endl;
	kEvent = this->keyboard->IsKeyDown(SDLK_RIGHT);
	//std::cout << "checking for right arrow down" << std::endl;
	if(kEvent != NULL)
	{
		std::cout << "Moving sprite" << std::endl;
		spriteX = this->sprite->X();
		this->sprite->X(spriteX+1);
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
		case SDL_KEYDOWN:
			this->keyboard->OnKeyDown(&e->key);			
			break;
		case SDL_KEYUP:
			this->keyboard->OnKeyUp(&e->key);
			break;
		case SDL_MOUSEMOTION:
			this->mouse_1->OnMouseMove(&e->motion);
			break;
		case SDL_MOUSEBUTTONDOWN:
			this->mouse_1->OnMouseDown(&e->button);
			break;
		case SDL_MOUSEBUTTONUP:
			this->mouse_1->OnMouseUp(&e->button);
			break;
		case SDL_JOYBUTTONDOWN:
			this->gamepad_1->OnButtonDown(&e->jbutton);
			break;
		case SDL_JOYBUTTONUP:
			this->gamepad_1->OnButtonUp(&e->jbutton);
			break;
		case SDL_JOYAXISMOTION:
			this->gamepad_1->OnJoyAxisMotion(&e->jaxis);
			break;
		case SDL_QUIT:
			this->running = false;
			break;
		default: 
			break;
	}

	//std::cout << "OnSDLEvent: " << e->key.keysym.sym << std::endl;
}

void Engine::InitOpenGL()
{
	glClearColor(0,0,0,0);
	glClearDepth(1.0f);
	glViewport(0, 0, 640, 480);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, 640, 480, 0, 1, -1);
	glMatrixMode(GL_MODELVIEW);
	glEnable(GL_TEXTURE_2D);
	glLoadIdentity();	 
}