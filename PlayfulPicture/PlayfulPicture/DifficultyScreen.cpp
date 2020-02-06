//FILE: DifficultyScreen.cpp
//PROJECT: PlayfulPictures
//PROGRAMMER: John Gotts
//FIRST VERSION: 02/05/2020
#include "DifficultyScreen.h"

DifficultyScreen::DifficultyScreen()
{
	timer = Timer::Instance();
	input = InputManager::Instance();

	topBar = new GameEntity(Graphics::SCREEN_WIDTH, 50.0f);
	screenLabel = new Texture("Difficulty Selection", "emulogic.ttf", 32, {255, 0, 111});
	topBar->SetParent(this);
	screenLabel->SetParent(topBar);
	screenLabel->SetPosition(-Graphics::SCREEN_WIDTH * 0.5f, 0.0f);

	iconHolder = new GameEntity(Graphics::SCREEN_WIDTH, Graphics::SCREEN_HEIGHT);
	easyButton = new Texture("3x3.png", 0, 0, 238, 200);
	mediumButton = new Texture("4x4.png", 0, 0, 238, 200);
	hardButton = new Texture("5x5.png", 0, 0, 238, 200);

	iconHolder->SetParent(this);
	easyButton->SetParent(iconHolder);
	mediumButton->SetParent(iconHolder);
	hardButton->SetParent(iconHolder);

	easyButton->SetPosition(-Graphics::SCREEN_WIDTH * 0.8f, -Graphics::SCREEN_HEIGHT * 0.75f);
	mediumButton->SetPosition(-Graphics::SCREEN_WIDTH * 0.8f, -Graphics::SCREEN_HEIGHT * 0.50f);
	hardButton->SetPosition(-Graphics::SCREEN_WIDTH * 0.8f, -Graphics::SCREEN_HEIGHT * 0.25f);
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
	screenLabel->Render();
	easyButton->Render();
	mediumButton->Render();
	hardButton->Render();
}

void DifficultyScreen::Update()
{
	if (input->MouseButtonPressed(input->Left)) {
		std::cout << "left pressed\n";
		if (ContainsPoint(easyButton, input->MousePosition().x, input->MousePosition().y)) {
			std::cout << "clicked easy button\n";
		}
		else if (ContainsPoint(mediumButton, input->MousePosition().x, input->MousePosition().y)) {
			std::cout << "clicked medium button\n";
		}
		else if (ContainsPoint(hardButton, input->MousePosition().x, input->MousePosition().y)) {
			std::cout << "clicked hard button\n";
		}
	}
}

bool DifficultyScreen::ContainsPoint(Texture* texture, int x, int y)
{
	if (texture) {
		if ((x > texture->Position().x - texture->GetWidth() * 0.5f) && (x < texture->Position().x + texture->GetWidth() * 0.5f)
			&& (y > texture->Position().y - texture->GetHeight() * 0.5f) && (y < texture->Position().y + texture->GetHeight() * 0.5f)) {
			return true;
		}
	}
	
	return false;
}