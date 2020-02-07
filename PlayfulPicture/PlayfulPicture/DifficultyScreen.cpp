//FILE: DifficultyScreen.cpp
//PROJECT: PlayfulPictures
//PROGRAMMER: John Gotts
//FIRST VERSION: 02/05/2020
#include "DifficultyScreen.h"


DifficultyScreen::Difficulties DifficultyScreen::selectedDifficulty = none;
DifficultyScreen::DifficultyScreen()
{
	timer = Timer::Instance();
	input = InputManager::Instance();

	button = new Buttons();

	topBar = new GameEntity(Graphics::SCREEN_WIDTH, 50.0f);
	screenLabel = new Texture("Difficulty Selection", "emulogic.ttf", 32, {255, 0, 111});
	topBar->SetParent(this);
	screenLabel->SetParent(topBar);
	screenLabel->SetPosition(-Graphics::SCREEN_WIDTH * 0.5f, 0.0f);

	iconHolder = new GameEntity(Graphics::SCREEN_WIDTH, Graphics::SCREEN_HEIGHT);
	easyButtonTexture = new Texture("3x3.png", 0, 0, 238, 200);
	mediumButtonTexture = new Texture("4x4.png", 0, 0, 238, 200);
	hardButtonTexture = new Texture("5x5.png", 0, 0, 238, 200);
	backgroundImage = new Texture("Background.jpg", 0, 0, 1760, 1200);

	iconHolder->SetParent(this);
	easyButtonTexture->SetParent(iconHolder);
	mediumButtonTexture->SetParent(iconHolder);
	hardButtonTexture->SetParent(iconHolder);
	backgroundImage->SetParent(iconHolder);

	easyButtonTexture->SetPosition(-Graphics::SCREEN_WIDTH * 0.8f, -Graphics::SCREEN_HEIGHT * 0.75f);
	mediumButtonTexture->SetPosition(-Graphics::SCREEN_WIDTH * 0.8f, -Graphics::SCREEN_HEIGHT * 0.50f);
	hardButtonTexture->SetPosition(-Graphics::SCREEN_WIDTH * 0.8f, -Graphics::SCREEN_HEIGHT * 0.25f);
	backgroundImage->SetPosition(-Graphics::SCREEN_WIDTH * 0.5f, -Graphics::SCREEN_HEIGHT * 0.5f);
}

DifficultyScreen::~DifficultyScreen()
{

	delete topBar;
	topBar = nullptr;

	delete screenLabel;
	screenLabel = nullptr;

	delete iconHolder;
	iconHolder = nullptr;

	delete easyButtonTexture;
	easyButtonTexture = nullptr;
	delete mediumButtonTexture;
	mediumButtonTexture = nullptr;
	delete hardButtonTexture;
	hardButtonTexture = nullptr;
	delete backgroundImage;
	backgroundImage = nullptr;

	delete button;
	button = nullptr;
}

void DifficultyScreen::Render()
{
	backgroundImage->Render();
	screenLabel->Render();
	easyButtonTexture->Render();
	mediumButtonTexture->Render();
	hardButtonTexture->Render();
}

void DifficultyScreen::Update()
{
	if (input->MouseButtonPressed(input->Left)) {

		if (button->ContainsPoint(easyButtonTexture, input->MousePosition().x, input->MousePosition().y)) {
			selectedDifficulty = easy;
			std::cout << "clicked easy button\n";
		}
		else if (button->ContainsPoint(mediumButtonTexture, input->MousePosition().x, input->MousePosition().y)) {
			selectedDifficulty = medium;
			std::cout << "clicked medium button\n";
		}
		else if (button->ContainsPoint(hardButtonTexture, input->MousePosition().x, input->MousePosition().y)) {
			selectedDifficulty = hard;
			std::cout << "clicked hard button\n";
		}
		else {
			selectedDifficulty = none;
		}
	}
}

DifficultyScreen::Difficulties DifficultyScreen::GetDifficulty()
{
	return selectedDifficulty;
}