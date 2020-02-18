#include "Screens.h"

Screens::Screens()
{
	timer = Timer::Instance();
	input = InputManager::Instance();
	button = new Buttons();
}

Screens::~Screens()
{

}
