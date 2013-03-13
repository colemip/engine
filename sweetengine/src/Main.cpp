#include <iostream>
#include <tchar.h>
#include "Engine.h"
#include "event\Event.h"

using namespace std;

int _tmain(int argc, _TCHAR** argv) 
{
	Sweet::Engine *engine = new Sweet::Engine();
	Sweet::Event *e = new Sweet::Event();
	e->OnInit();

	string input;
	cout << "Exit? (y/n)";
	cin >> input;

	return 0;
}