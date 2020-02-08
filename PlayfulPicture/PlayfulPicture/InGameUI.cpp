//FILE: InGameUI.cpp
//PROJECT: PlayfulPictures
//PROGRAMMER: John Gotts
//FIRST VERSION: 02/07/2020
#include "InGameUI.h"

InGameUI::InGameUI()
{
	minutes = 0;
	seconds = 00;
	timer = Timer::Instance();
	input = InputManager::Instance();
	button = new Buttons();

	//UpdateTimeCounterText();

	topBar = new GameEntity(Graphics::SCREEN_WIDTH, 50.0f);

	timeCounter = new Texture(minutes + ":" + seconds, "emulogic.ttf", 32, {255, 0, 111});
	movesCounter = new Texture("Total Moves: " + totalMoves, "emulogic.ttf", 28, {255, 0, 111});
	backButtonTexture = new Texture("Buttons.png", 344, 85, 172, 85);

	topBar->SetParent(this);
	timeCounter->SetParent(topBar);
	movesCounter->SetParent(topBar);
	backButtonTexture->SetParent(topBar);

	timeCounter->SetPosition(-Graphics::SCREEN_WIDTH * 0.9f, 0.0f);
	movesCounter->SetPosition(-Graphics::SCREEN_WIDTH * 0.6f, 0.0f);
	backButtonTexture->SetPosition(-Graphics::SCREEN_WIDTH * 0.2f, 0.0f);
}

InGameUI::~InGameUI()
{
	delete topBar;
	topBar = nullptr;

	delete timeCounter;
	timeCounter = nullptr;

	delete movesCounter;
	movesCounter = nullptr;

	delete backButtonTexture;
	backButtonTexture = nullptr;

	delete button;
	button = nullptr;
}

void InGameUI::Update()
{
	//UpdateTimeCounterText();
	movesCounter->Update();

	if (input->MouseButtonPressed(input->Left)) {
		if (button->ContainsPoint(backButtonTexture, input->MousePosition().x, input->MousePosition().y)) {
			quit = true;
		}
	}
}

void InGameUI::Render()
{
	timeCounter->Render();
	movesCounter->Render();
	backButtonTexture->Render();
}

bool InGameUI::GetQuit()
{
	return quit;
}

void InGameUI::UpdateTimeCounterText()
{
	if (timer->GetDeltaTime() >= 1.0f / 600) {
		seconds++;
		if (seconds == 60) {
			minutes++;
			seconds = 0;
		}
		timer->ResetTimer();
	}
}
