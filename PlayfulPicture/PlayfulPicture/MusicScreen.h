#pragma once
#include "Timer.h"
#include "Texture.h"
#include "InputManager.h"

using namespace SDLFramework;

class MusicScreen {

private:
	Timer* timer;
	InputManager* input;

public:
	MusicScreen();
	~MusicScreen();
};