//FILE: Main.cpp
//PROJECT: PlayfulPictures
//PROGRAMMER: John Gotts
//FIRST VERSION: 02/03/2020
#include "GameManager.h"

using SDLFramework::GameManager;

int main(int argc, char* args[]) {

	GameManager* game = new GameManager();

	game->Run();

	GameManager::Release();
	game = nullptr;

	return 0;
}