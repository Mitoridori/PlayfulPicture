//FILE: DifficultyScreen.cpp
//PROJECT: PlayfulPictures
//PROGRAMMER: John Gotts
//FIRST VERSION: 02/05/2020
#include "DifficultyScreen.h"

DifficultyScreen::DifficultyScreen()
{
	timer = Timer::Instance();
	input = InputManager::Instance();

	iconHolder = new GameEntity(Graphics::SCREEN_WIDTH, Graphics::SCREEN_HEIGHT * 0.8f);

	easyButton = new Texture("3x3.png", 0, 0, 400, 400);
	easyButton->SetParent(iconHolder);

	mediumButton = new Texture("4x4.png", 0, 0, 400, 400);
	mediumButton->SetParent(iconHolder);

	hardButton = new Texture("5x5.png", 0, 0, 400, 400);
	hardButton->SetParent(iconHolder);
}

DifficultyScreen::~DifficultyScreen()
{
	delete iconHolder;
	iconHolder = nullptr;

	delete easyButton;
	easyButton = nullptr;
	delete mediumButton;
	mediumButton = nullptr;
	delete hardButton;
	hardButton = nullptr;
}

void DifficultyScreen::Render()
{
	easyButton->Render();
	mediumButton->Render();
	hardButton->Render();
}

void DifficultyScreen::Update()
{
}

void DifficultyScreen::SetGameMode()
{
}
