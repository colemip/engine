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
	seFloat spriteX = 0.0f;
	seFloat spriteY = 0.0f;

	while(SDL_PollEvent(&sdl_e))
	{
		OnSDLEvent(&sdl_e);				
	}

	/* keyboard events for moving sprite */
	if(this->keyboard->IsKeyDown(SDLK_RIGHT))
	{
		//std::cout << "Moving sprite" << std::endl;
		spriteX = this->sprite->X();
		this->sprite->X(spriteX+1);
	}
	if(this->keyboard->IsKeyDown(SDLK_LEFT))
	{
		spriteX = this->sprite->X();
		this->sprite->X(spriteX-1);
	}
	if(this->keyboard->IsKeyDown(SDLK_UP))
	{
		spriteY = this->sprite->Y();
		this->sprite->Y(spriteY-1);
	}
	if(this->keyboard->IsKeyDown(SDLK_DOWN))
	{
		spriteY = this->sprite->Y();
		this->sprite->Y(spriteY+1);
	}

	/* gamepad button events for moving sprite */
	if(this->gamepad_1->IsButtonDown(0))
	{		
		spriteY = this->sprite->Y();
		this->sprite->Y(spriteY+1);
	}
	if(this->gamepad_1->IsButtonDown(1))
	{	
		spriteX = this->sprite->X();
		this->sprite->X(spriteX+1);
	}
	if(this->gamepad_1->IsButtonDown(2))
	{
		spriteX = this->sprite->X();
		this->sprite->X(spriteX-1);
	}
	if(this->gamepad_1->IsButtonDown(3))
	{
		spriteY = this->sprite->Y();
		this->sprite->Y(spriteY-1);
	}

	/* gamepad axis events for moving sprite */
	int gamepadThreshold = 5000;
	if(this->gamepad_1->GetAxisValue(LEFT_STICK_X) > gamepadThreshold)
	{
		spriteX = this->sprite->X();
		this->sprite->X(spriteX+1);
	}
	if(this->gamepad_1->GetAxisValue(LEFT_STICK_X) < -gamepadThreshold)
	{
		spriteX = this->sprite->X();
		this->sprite->X(spriteX-1);
	}
	if(this->gamepad_1->GetAxisValue(LEFT_STICK_Y) > gamepadThreshold)
	{
		spriteY = this->sprite->Y();
		this->sprite->Y(spriteY+1);
	}
	if(this->gamepad_1->GetAxisValue(LEFT_STICK_Y) < -gamepadThreshold)
	{
		spriteY = this->sprite->Y();
		this->sprite->Y(spriteY-1);
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