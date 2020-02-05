#pragma once
#include "Timer.h"
#include "Texture.h"
#include "InputManager.h"

using namespace SDLFramework;

class WinScreen {

private:
	Timer* timer;
	InputManager* input;

public:
	WinScreen();
	~WinScreen();
};