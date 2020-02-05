//FILE: ScreenManager.h
//PROJECT: PlayfulPictures
//PROGRAMMER: John Gotts
//FIRST VERSION: 02/03/2020
#pragma once

#include "TitleScreen.h"
#include "InputManager.h"

using namespace SDLFramework;

class ScreenManager {

private:
	static ScreenManager* instance;

	enum Screens { start, difficulty, play, congratulations };
	Screens currentScreen;
	InputManager* input;
	TitleScreen* mTitleScreen;


public:
	static ScreenManager* Instance();
	static void Release();

	void Update();
	void Render();

private:
	ScreenManager();
	~ScreenManager();
};