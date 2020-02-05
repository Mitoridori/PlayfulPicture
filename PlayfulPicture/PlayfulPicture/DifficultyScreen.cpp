#include "DifficultyScreen.h"

DifficultyScreen::DifficultyScreen()
{
	timer = Timer::Instance();
	input = InputManager::Instance();

	iconHolder = new GameEntity(Graphics::SCREEN_WIDTH, Graphics::SCREEN_HEIGHT * 0.8f);

}

DifficultyScreen::~DifficultyScreen()
{
}

void DifficultyScreen::Render()
{
}

void DifficultyScreen::Update()
{
}

void DifficultyScreen::SetGameMode()
{
}
