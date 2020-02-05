//FILE: GameManager.h
//PROJECT: PlayfulPictures
//PROGRAMMER: John Gotts
//FIRST VERSION: 02/03/2020
#pragma once

#include <SDL.h>
#include "Timer.h"
#include "ScreenManager.h"
#include "TitleScreen.h"

namespace SDLFramework {

	class GameManager {

	private:
		static GameManager* instance;

		Timer* timer;
		ScreenManager* screenManager;

		bool quit;
		const int FRAME_RATE = 60;

		SDL_Event events;

		TitleScreen* mTitleScreen;

	public:
		GameManager();
		~GameManager();

		static GameManager* Instance();
		static void Release();

		void Run();
		void Update();
		void LateUpdate();
		void RenderObjects();


	};

}