#include <iostream>
#include "Event.h"

using namespace std;
using namespace Sweet;


Event::Event()
{
	cout << "Event Constructor" << endl;
}

Event::~Event()
{
	cout << "Event Destructor" << endl;
}

bool Event::OnInit()
{
	cout << "OnOnit Event" <<  endl;
	return false;
}

bool Event::OnLoad()
{
	cout << "OnLoad Event" << endl;
	return false;
}

bool Event::OnExit()
{
	cout << "OnExit Event" << endl;
	return false;
}

void Event::OnKeyPress()
{
	cout << "OnKeyPress Event" << endl;
}

void Event::OnMouseDown()
{
	cout << "OnMouseDown Event" << endl;
}

void Event::OnMouseUp()
{
	cout << "OnMouseUp Event" << endl;
}

void Event::OnButtonPress()
{
	cout << "OnButtonPress Event" << endl;
}
