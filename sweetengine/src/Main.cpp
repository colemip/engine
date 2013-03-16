#include <iostream>
#include <tchar.h>
#include "Engine.h"
#include "event\Event.h"

using namespace std;

int _tmain(int argc, _TCHAR** argv) 
{
	Sweet::Engine *engine = new Sweet::Engine();
	engine->Init();
	//engine->Update();
	engine->StartUp();

	/*string input;
	cout << "Exit? (y/n)";
	cin >> input;*/

	return 0;
}