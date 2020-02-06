#include "PlayScreen.h"

SDLFramework::PlayScreen::PlayScreen()
{
	timer = Timer::Instance();
	input = InputManager::Instance();

	//uiBar = new PlaySideBar();
	//uiBar->Parent(this);
	//uiBar->Position(Graphics::SCREEN_WIDTH * 0.87f, Graphics::SCREEN_HEIGHT * 0.05f);

	board = new Board();
	//board->Parent(this);
	//board->Position(Graphics::SCREEN_WIDTH * 0.87f, Graphics::SCREEN_HEIGHT * 0.05f);

}

SDLFramework::PlayScreen::~PlayScreen()
{

	timer = nullptr;
	input = nullptr;

	//delete uiBar;
	//uiBar = nullptr;

	delete board;
	board = nullptr;
}
