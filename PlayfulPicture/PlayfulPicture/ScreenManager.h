//FILE: ScreenManager.h
//PROJECT: PlayfulPictures
//PROGRAMMER: John Gotts
//FIRST VERSION: 02/03/2020
#pragma once

#include "TitleScreen.h"
#include "DifficultyScreen.h"
#include "Board.h"

using namespace SDLFramework;

class ScreenManager {

private:
	static ScreenManager* instance;

	enum Screens { start, mainScreen, musicScreen, difficulty, picture, play, congratulations };
	Screens currentScreen;
	InputManager* input;
	TitleScreen* mTitleScreen;
	DifficultyScreen* selectScreen;
	Board* test;


public:
	static ScreenManager* Instance();
	static void Release();

	void Update();
	void Render();

private:
	ScreenManager();
	~ScreenManager();
};