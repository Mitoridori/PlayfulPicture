//FILE: ScreenManager.h
//PROJECT: PlayfulPictures
//PROGRAMMER: John Gotts
//FIRST VERSION: 02/03/2020
#pragma once

#include "TitleScreen.h"
#include "MusicScreen.h"
#include "MenuScreen.h"
#include "DifficultyScreen.h"
#include "PictureSelectScreen.h"
#include "Board.h"

using namespace SDLFramework;

class ScreenManager {

private:
	static ScreenManager* instance;

	static enum Screens { start, mainScreen, musicScreen, difficulty, picture, play, congratulations };
	static Screens currentScreen;
	InputManager* input;
	MenuScreen* mMainScreen;
	MusicScreen* mMusicScreen;
	TitleScreen* mTitleScreen;
	DifficultyScreen* selectScreen;
	PictureSelectScreen* pictureSelectScreen;
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