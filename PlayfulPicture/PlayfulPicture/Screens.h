#pragma once
#include "GameEntity.h"
#include "InputManager.h"
#include "Timer.h"
#include "Buttons.h"
#include <vector>

class State;
using namespace SDLFramework;
using namespace std;

class Screens : public GameEntity {

protected:
	Timer* timer;
	InputManager* input;
	Buttons* button;

	vector<GameEntity*> gameEntityList;

	//State* currentScreenState;

public:
	State* currentScreenState;

public:
	Screens();
	~Screens();

	//void ChangeScreenState(State* newState);

};