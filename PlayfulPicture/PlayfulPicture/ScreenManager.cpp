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
	/*input = InputManager::Instance();
	startScreen = new StartScreen();
	playScreen = new PlayScreen();*/

	currentScreen = start;
}

//Function:~ScreenManager
	//DESCRIPTION: deconstructor for the screen manager
	//PARAMETERS: None
	//RETURNS: None
ScreenManager::~ScreenManager()
{
	//input = nullptr;

	/*delete startScreen;
	startScreen = nullptr;*/
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
		/*startScreen->Update();
		if (input->GetKeyPressed(SDL_SCANCODE_RETURN)) {
			currentScreen = play;
			startScreen->ResetAnimations();
		}*/
		break;
	case difficulty:
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
		//startScreen->Render();
		break;
	case difficulty:
		break;
	case play:
		//playScreen->Render();
		break;
	case congratulations:
		break;
	}
}