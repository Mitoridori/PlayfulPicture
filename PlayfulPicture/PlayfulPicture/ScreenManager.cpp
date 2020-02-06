//FILE: ScreenManager.cpp
//PROJECT: PlayfulPictures
//PROGRAMMER: John Gotts
//FIRST VERSION: 02/03/2020
#include "ScreenManager.h"


ScreenManager* ScreenManager::instance = nullptr;

//Function: ScreenManager
//DESCRIPTION: constructor for the screen manager
//PARAMETERS: None
//RETURNS: None
ScreenManager::ScreenManager()
{
	input = InputManager::Instance();
	mTitleScreen = new TitleScreen();
	selectScreen = new DifficultyScreen();

	currentScreen = difficulty;
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

	switch (currentScreen) {

	case start:
		mTitleScreen->Update();
		break;
	case mainScreen:
		break;
	case musicScreen:
		break;
	case difficulty:
		selectScreen->Update();
		break;
	case play:
		/*playScreen->Update();
		if (input->GetKeyPressed(SDL_SCANCODE_ESCAPE)) {
			currentScreen = start;
		}*/
		break;
	case congratulations:
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
	case mainScreen:
		break;
	case musicScreen:
		break;
	case difficulty:
		selectScreen->Render();
		break;
	case play:
		//playScreen->Render();
		break;
	case congratulations:
		break;
	}
}