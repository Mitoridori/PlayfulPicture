#include "Screens.h"
#include "ScreensStates.h"
#include <cassert>

Screens::Screens()
{
	timer = Timer::Instance();
	input = InputManager::Instance();
	button = new Buttons();
}

Screens::~Screens()
{

}

//void Screens::ChangeScreenState(State* newState)
//{
//	//make sure both states are both valid before attempting to 
//  //call their methods
//	assert(currentScreenState && newState);
//
//	//call the exit method of the existing state
//	currentScreenState->Exit(this);
//
//	//change state to the new state;
//	currentScreenState = newState;
//
//	//call the entry method of the new state
//	currentScreenState->Enter(this);
//}
