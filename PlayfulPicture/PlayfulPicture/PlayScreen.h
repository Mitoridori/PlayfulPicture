#pragma once
#include "Timer.h"
#include "Texture.h"
#include "InputManager.h"
#include "Board.h"

namespace SDLFramework {
	class PlayScreen {

	private:
		Timer* timer;
		InputManager* input;

		//UIBar* uiBar;

		Board* board;

	public:
		PlayScreen();
		~PlayScreen();

	};
}