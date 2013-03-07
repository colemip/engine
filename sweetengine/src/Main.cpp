#include <iostream>
#include "Engine.h"
#include "event\Event.h"

using namespace std;

int main()
{
	Sweet::Engine();
	Sweet::Event *e = new Sweet::Event();
	e->OnInit();

	string input;
	cout << "Exit? (y/n)";
	cin >> input;

	return 0;
}