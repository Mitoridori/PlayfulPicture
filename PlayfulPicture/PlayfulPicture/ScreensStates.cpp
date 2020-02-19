#include "ScreensStates.h"
#include "Screens.h"


TitleScreenState* TitleScreenState::Instance()
{
	static TitleScreenState instance;
	return &instance;
}

void TitleScreenState::Enter(Screens* screen)
{
	screen->Render();
}

void TitleScreenState::Render(Screens* screen)
{
	screen->Render();
}

void TitleScreenState::Update(Screens* screen)
{
	screen->Update();
}

void TitleScreenState::Exit(Screens* screen)
{
	//screen->ChangeScreenState(MainMenuState::Instance());
}


MainMenuState* MainMenuState::Instance()
{
	static MainMenuState instance;
	return &instance;
}

void MainMenuState::Enter(Screens* screen)
{
	screen->Render();
}

void MainMenuState::Render(Screens* screen)
{
	screen->Render();
}

void MainMenuState::Update(Screens* screen)
{
	screen->Update();
}

void MainMenuState::Exit(Screens* screen)
{
}
