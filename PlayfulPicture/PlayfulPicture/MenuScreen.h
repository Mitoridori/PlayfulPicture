#pragma once
#include "Timer.h"
#include "Texture.h"
#include "InputManager.h"

using namespace SDLFramework;

class MenuScreen{

private:
	Timer* timer;
	InputManager* input;

public:
	MenuScreen();
	~MenuScreen();
};