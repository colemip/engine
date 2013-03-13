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

EventType Event::getType()
{
	return this->type;
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

void Event::OnKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode)
{
	cout << "OnKeyDown Event" << endl;
	
}

void Event::OnKeyUp()
{
	cout << "OnKeyUp Event" << endl;
}

void Event::OnMouseDown()
{
	cout << "OnMouseDown Event" << endl;
}

void Event::OnMouseUp()
{
	cout << "OnMouseUp Event" << endl;
}

void Event::OnButtonDown()
{
	cout << "OnButtonDown Event" << endl;
}

void Event::OnButtonUp()
{
	cout << "OnButtonUp Event" << endl;
}