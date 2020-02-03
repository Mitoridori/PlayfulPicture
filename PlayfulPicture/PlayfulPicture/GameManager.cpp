#include "GameManager.h"


namespace SDLFramework {

	GameManager* GameManager::instance = nullptr;

	GameManager::GameManager() : quit(false)
	{

	}

	GameManager::~GameManager()
	{
		SDL_Quit();
	}

	GameManager* GameManager::Instance()
	{
		if (instance == nullptr) {
			instance = new GameManager();
		}
		return instance;
	}

	void GameManager::Release()
	{
		delete instance;
		instance = nullptr;
	}

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
		}
	}

	void GameManager::Update()
	{
	}

	void GameManager::LateUpdate()
	{
	}

	//used to render objects ie. graphics, screen manager.
	void GameManager::RenderObjects()
	{
	}

}