#include "WinScreen.h"

WinScreen::WinScreen()
{
	timer = Timer::Instance();
	input = InputManager::Instance();

	button = new Buttons();

	topBar = new GameEntity(Graphics::SCREEN_WIDTH, 50.0f);
	screenLabel = new Texture("You Win!!", "emulogic.ttf", 32, { 255, 0, 111 });
	topBar->SetParent(this);
	screenLabel->SetParent(topBar);
	screenLabel->SetPosition(-Graphics::SCREEN_WIDTH * 0.5f, 0.0f);

	buttonHolder = new GameEntity(Graphics::SCREEN_WIDTH, Graphics::SCREEN_HEIGHT);
	menuButtonTexture = new Texture("Buttons.png", 0, 0, 172, 85);
	quitButtonTexture = new Texture("Buttons.png", 1204, 0, 172, 85);

	movesCounter = new Texture("Total Moves: " + PlayScreen::GetTotalMoves(), "emulogic.ttf", 32, { 255, 0, 111 });
	movesCounter->SetParent(buttonHolder);
	movesCounter->SetPosition(-Graphics::SCREEN_WIDTH * 0.7f, -Graphics::SCREEN_HEIGHT * 0.5f);

	backgroundImage = new Texture("Background.jpg", 0, 0, 1760, 1200);

	buttonHolder->SetParent(this);
	menuButtonTexture->SetParent(buttonHolder);
	quitButtonTexture->SetParent(buttonHolder);
	backgroundImage->SetParent(buttonHolder);

	menuButtonTexture->SetPosition(-Graphics::SCREEN_WIDTH * 0.2f, -Graphics::SCREEN_HEIGHT * 0.3f);
	quitButtonTexture->SetPosition(-Graphics::SCREEN_WIDTH * 0.8f, -Graphics::SCREEN_HEIGHT * 0.3f);
	backgroundImage->SetPosition(-Graphics::SCREEN_WIDTH * 0.5f, -Graphics::SCREEN_HEIGHT * 0.5f);

}

WinScreen::~WinScreen()
{
	delete topBar;
	topBar = nullptr;

	delete screenLabel;
	screenLabel = nullptr;

	delete movesCounter;
	movesCounter = nullptr;

	delete buttonHolder;
	buttonHolder = nullptr;

	delete menuButtonTexture;
	menuButtonTexture = nullptr;

	delete quitButtonTexture;
	quitButtonTexture = nullptr;

	delete backgroundImage;
	backgroundImage = nullptr;

	delete button;
	button = nullptr;
}

void WinScreen::Render()
{
	backgroundImage->Render();
	screenLabel->Render();
	movesCounter->Render();
	menuButtonTexture->Render();
	quitButtonTexture->Render();
}

void WinScreen::Update()
{
	if (input->MouseButtonPressed(input->Left)) {
		if (button->ContainsPoint(menuButtonTexture, input->MousePosition().x, input->MousePosition().y)) {
			menu = true;
		}
		else if (button->ContainsPoint(quitButtonTexture, input->MousePosition().x, input->MousePosition().y)) {
			quit = true;
		}

	}
}
