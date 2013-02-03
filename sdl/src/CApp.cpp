#include "CApp.h"
#include <tchar.h>
 
/* Entry point */
int _tmain(int argc, _TCHAR** argv) 
{
	CApp theApp;
 
	return theApp.OnExecute();
}

/* Class definition */
CApp::CApp() 
{
	Surf_Display = NULL;
 
    Running = true;
}
 
int CApp::OnExecute() 
{
    if(OnInit() == false) {
        return -1;
    }
 
    SDL_Event Event;
 
    while(Running) {
        while(SDL_PollEvent(&Event)) {
            OnEvent(&Event);
        }
 
        OnLoop();
        OnRender();
    }
 
    OnCleanup();
 
    return 0;
}
  
bool CApp::OnInit() 
{
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        return false;
    }
 
    if((Surf_Display = SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE | SDL_DOUBLEBUF)) == NULL) {
        return false;
    }
 
    return true;
}

void CApp::OnEvent(SDL_Event* Event) 
{
	if(Event->type == SDL_QUIT) {
        Running = false;
    }
}

void CApp::OnLoop() 
{
}

void CApp::OnRender() 
{
}

void CApp::OnCleanup()
{
	SDL_Quit();
}