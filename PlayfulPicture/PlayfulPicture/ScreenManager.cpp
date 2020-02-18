//FILE: ScreenManager.cpp
//PROJECT: PlayfulPictures
//PROGRAMMER: John Gotts
//FIRST VERSION: 02/03/2020
#include "ScreenManager.h"


ScreenManager* ScreenManager::instance = nullptr;
ScreenManager::Screens ScreenManager::currentScreen = start;

//Function: ScreenManager
//DESCRIPTION: constructor for the screen manager
//PARAMETERS: None
//RETURNS: None
ScreenManager::ScreenManager()
{

	input = InputManager::Instance();
	mMenuScreen = new MenuScreen();
	mTitleScreen = new TitleScreen();
	mMusicScreen = new MusicScreen();
	selectScreen = new DifficultyScreen();
	pictureSelectScreen = new PictureSelectScreen();
	winScreen = new WinScreen();
	playScreen = new PlayScreen();

	currentScreen = start;
}

//Function:~ScreenManager
//DESCRIPTION: deconstructor for the screen manager
//PARAMETERS: None
//RETURNS: None
ScreenManager::~ScreenManager()
{
	InputManager::Release();
	input = nullptr;

	delete mTitleScreen;
	mTitleScreen = NULL;

	delete selectScreen;
	selectScreen = nullptr;

	delete pictureSelectScreen;
	pictureSelectScreen = nullptr;

	delete mMusicScreen;
	mMusicScreen = nullptr;

	delete mMenuScreen;
	mMenuScreen = nullptr;

	delete winScreen;
	winScreen = nullptr;

	delete playScreen;
	playScreen = nullptr;
}

//Function: Instance
//DESCRIPTION: singleton function for the screen manager
//PARAMETERS: None
//RETURNS: instance
ScreenManager* ScreenManager::Instance()
{
	if (instance == nullptr) {
		instance = new ScreenManager();
	}
	return instance;
}

//Function: Release
//DESCRIPTION: funtion used to remove the instance
//PARAMETERS: None
//RETURNS: None
void ScreenManager::Release()
{
	delete instance;
	instance = nullptr;
}

//Function: Update
//DESCRIPTION: function used to update the screen manager
//PARAMETERS: None
//RETURNS: None
void ScreenManager::Update()
{

	switch (currentScreen) 
	{

	case start:
		mTitleScreen->Update();
		if (input->MouseButtonPressed(input->Left)) 
		{
			currentScreen = menuScreen;
		}
		break;
	case menuScreen:
		mMenuScreen->Update();
		if (mMenuScreen->game)
		{
			mMenuScreen->game = false;
			currentScreen = difficulty;
		}
		else if (mMenuScreen->music)
		{
			mMenuScreen->music = false;
			currentScreen = musicScreen;
		}
		else if(mMenuScreen->quit)
		{
			gameQuit = true;
		}
		break;
	case musicScreen:
		mMusicScreen->Update();
		if (mMusicScreen->back) 
		{
			mMusicScreen->back = false;
			currentScreen = menuScreen;
		}
		break;
	case difficulty:
		selectScreen->Update();
		if (selectScreen->GetDifficulty() != 0) 
		{
			currentScreen = picture;
		}
		break;
	case picture:
		pictureSelectScreen->Update();
		if (pictureSelectScreen->GetSelectedPicture() != 0) 
		{
			currentScreen = play;
		}
		break;
	case play:
		playScreen->Update();
		if (playScreen->GetPlayerUI()->GetQuit()) {
			gameQuit = true;
		}
		break;
	case congratulations:
		winScreen->Update();
		if (winScreen->GetMenu()) {
			currentScreen = start;
		}
		else if (winScreen->GetQuit()) {
			gameQuit = true;
		}
		break;
	}
}

//Function: Render
//DESCRIPTION: function used to call the relevant screen to render
//PARAMETERS: None
//RETURNS: None
void ScreenManager::Render()
{

	switch (currentScreen) {
	case start:
		mTitleScreen->Render();
		break;
	case menuScreen:
		mMenuScreen->Render();
		break;
	case musicScreen:
		mMusicScreen->Render();
		break;
	case difficulty:
		selectScreen->Render();
		break;
	case picture:
		pictureSelectScreen->Render();
		break;
	case play:
		playScreen->Render();
		break;
	case congratulations:
		winScreen->Render();
		break;
	}
}

bool ScreenManager::GetGameQuit()
{
	return gameQuit;
}
