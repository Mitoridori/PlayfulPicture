#pragma once
#include "Timer.h"
#include "Texture.h"
#include "InputManager.h"

namespace SDLFramework {
	class PlayScreen {

	private:
		Timer* timer;
		InputManager* input;

	public:
		PlayScreen();
		~PlayScreen();

	};
}