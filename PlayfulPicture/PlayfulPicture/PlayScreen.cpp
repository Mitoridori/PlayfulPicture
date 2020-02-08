#include "PlayScreen.h"

int SDLFramework::PlayScreen::totalMoves = 0;

SDLFramework::PlayScreen::PlayScreen()
{
	timer = Timer::Instance();
	input = InputManager::Instance();

	playerUI = new InGameUI();

	board = new Board();
	//board->Parent(this);
	//board->Position(Graphics::SCREEN_WIDTH * 0.87f, Graphics::SCREEN_HEIGHT * 0.05f);

}

SDLFramework::PlayScreen::~PlayScreen()
{

	timer = nullptr;
	input = nullptr;

	delete playerUI;
	playerUI = nullptr;

	delete board;
	board = nullptr;
}

InGameUI* SDLFramework::PlayScreen::GetPlayerUI()
{
	return playerUI;
}

void SDLFramework::PlayScreen::Update()
{
	playerUI->Update();
}

void SDLFramework::PlayScreen::Render()
{
	playerUI->Render();
	board->Render();
}

int SDLFramework::PlayScreen::GetTotalMoves()
{
	return totalMoves;
}

void SDLFramework::PlayScreen::IncrementTotalMoves(int amount)
{
	totalMoves += amount;
}
