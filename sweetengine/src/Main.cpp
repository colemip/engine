#include <iostream>
#include <tchar.h>
#include "Engine.h"
#include "event\Event.h"

using namespace std;

//int _tmain(int argc, _TCHAR** argv) 
int main(int argc, char **argv)
{
	Sweet::Engine *engine = new Sweet::Engine();
	engine->Init();
	//engine->Update();
	engine->StartUp();
	engine->runGLWorkbench(argc, argv);

	/*string input;
	cout << "Exit? (y/n)";
	cin >> input;*/

	return 0;
}