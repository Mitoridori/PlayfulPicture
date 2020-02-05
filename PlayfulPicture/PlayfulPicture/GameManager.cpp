//FILE: GameManager.cpp
//PROJECT: PlayfulPictures
//PROGRAMMER: John Gotts
//FIRST VERSION: 02/03/2020
#include "GameManager.h"


namespace SDLFramework {

	GameManager* GameManager::instance = nullptr;

	//Function: GameManager
	//DESCRIPTION: the Game managers constructor, used to initialize all game objects
	//PARAMETERS: None
	//RETURNS: None
	GameManager::GameManager() : quit(false)
	{
		timer = Timer::Instance();
		screenManager = ScreenManager::Instance();
		graphics = Graphics::Instance();
	}

	//Function: ~GameManager
	//DESCRIPTION: Game managers deconstructor
	//PARAMETERS: None
	//RETURNS: None
	GameManager::~GameManager()
	{
		Timer::Release();
		timer = nullptr;

		ScreenManager::Release();
		screenManager = nullptr;

		Graphics::Release();
		graphics = nullptr;

		SDL_Quit();
	}

	//Function: Instance
	//DESCRIPTION: this function will be used to create the instance of the game manager for singleton use
	//PARAMETERS: None
	//RETURNS: instance
	GameManager* GameManager::Instance()
	{
		if (instance == nullptr) {
			instance = new GameManager();
		}
		return instance;
	}

	//Function: Release
	//DESCRIPTION: function used to clear the instance upon deconstuctor call
	//PARAMETERS: None
	//RETURNS: None
	void GameManager::Release()
	{
		delete instance;
		instance = nullptr;
	}

	//Function: Run
	//DESCRIPTION: function used for when the game is running
	//PARAMETERS: None
	//RETURNS: None
	void GameManager::Run()
	{
		while (!quit) {
			while (SDL_PollEvent(&events)) {
				switch (events.type) {
				case SDL_QUIT:
					quit = true;
					break;
				}
			}

			if (timer->GetDeltaTime() >= 1.0f / FRAME_RATE) {
				Update();
				LateUpdate();
				RenderObjects();
				timer->ResetTimer();
			}
		}
	}

	//Function: Update
	//DESCRIPTION: function used to update the game manager
	//PARAMETERS: None
	//RETURNS: None
	void GameManager::Update()
	{
		screenManager->Update();
	}

	//Function: LateUpdate
	//DESCRIPTION: function used to update certain aspects after the rest has been updated
	//PARAMETERS: None
	//RETURNS: None
	void GameManager::LateUpdate()
	{
	}

	//Function: RenderObjects
	//DESCRIPTION: function used to render the game objects ie. screen manager and graphics
	//PARAMETERS: None
	//RETURNS: None
	void GameManager::RenderObjects()
	{
		graphics->ClearRenderer();
		screenManager->Render();
		
		graphics->Render();

	}

}