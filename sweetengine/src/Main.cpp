#include <iostream>
//#include <tchar.h>
#include "Engine.h"
#include "event/Event.h"

using namespace std;

int main(int argc, char **argv)
{
	Sweet::Engine *engine = new Sweet::Engine();
	engine->Init();
	engine->StartUp();
	//engine->RunGLWorkbench(argc, argv);

	return 0;
}
