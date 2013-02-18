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
	Surf_Test = NULL;
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
 
    if((Surf_Test = CSurface::OnLoad("hello.bmp")) == NULL) {
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
	CSurface::OnDraw(Surf_Display, Surf_Test, 0, 0);
 
    SDL_Flip(Surf_Display);
}

void CApp::OnCleanup() {
    SDL_FreeSurface(Surf_Test);
    SDL_FreeSurface(Surf_Display);
    SDL_Quit();
}