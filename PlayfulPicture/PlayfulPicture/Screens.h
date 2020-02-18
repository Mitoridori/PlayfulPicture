#pragma once
#include "GameEntity.h"
#include "InputManager.h"
#include "Timer.h"
#include "Buttons.h"
#include <vector>

using namespace SDLFramework;
using namespace std;

class Screens : public GameEntity {

protected:
	Timer* timer;
	InputManager* input;
	Buttons* button;

	vector<GameEntity*> gameEntityList;

public:
	Screens();
	~Screens();


};