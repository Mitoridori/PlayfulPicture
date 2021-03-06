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
#include "WinScreen.h"
#include "PlayScreen.h"

class State;

using namespace SDLFramework;

class ScreenManager {

private:
	static ScreenManager* instance;

	static enum Screens { start, menuScreen, musicScreen, difficulty, picture, play, congratulations };
	static Screens currentScreen;

	InputManager* input;
	MenuScreen* mMenuScreen;
	MusicScreen* mMusicScreen;
	TitleScreen* mTitleScreen;
	DifficultyScreen* selectScreen;
	PictureSelectScreen* pictureSelectScreen;
	WinScreen* winScreen;
	PlayScreen* playScreen;

	bool gameQuit = false;


public:
	static ScreenManager* Instance();
	static void Release();

	void Update();
	void Render();

	bool GetGameQuit();

private:
	ScreenManager();
	~ScreenManager();
};