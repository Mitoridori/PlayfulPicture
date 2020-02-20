#include "MusicScreen.h"

MusicScreen* MusicScreen::sInstance = nullptr;

MusicScreen::MusicScreen() : Screens()
{
	mAudio = AudioManager::Instance();

	backgroundTexture = new Texture("Background.jpg", 0, 0, 1760, 1200);

	iconHolder = new GameEntity(Graphics::SCREEN_WIDTH, Graphics::SCREEN_HEIGHT);
	music1ButtonTexture = new Texture("Buttons.png", 344, 85, 172, 85);
	music2ButtonTexture = new Texture("Buttons.png", 516, 0, 172, 85);
	music3ButtonTexture = new Texture("Buttons.png", 688, 0, 172, 85);
	backButtonTexture = new Texture("Buttons.png", 172, 0, 172, 85);

	iconHolder->SetParent(this);
	backgroundTexture->SetParent(iconHolder);
	music1ButtonTexture->SetParent(iconHolder);
	music2ButtonTexture->SetParent(iconHolder);
	music3ButtonTexture->SetParent(iconHolder);
	backButtonTexture->SetParent(iconHolder);

	backgroundTexture->SetPosition(-Graphics::SCREEN_WIDTH *0.5f, -Graphics::SCREEN_HEIGHT*0.5f);
	music1ButtonTexture->SetPosition(-Graphics::SCREEN_WIDTH * 0.75f, -Graphics::SCREEN_HEIGHT * 0.5f);
	music2ButtonTexture->SetPosition(-Graphics::SCREEN_WIDTH * 0.5f, -Graphics::SCREEN_HEIGHT * 0.5f);
	music3ButtonTexture->SetPosition(-Graphics::SCREEN_WIDTH * 0.25f, -Graphics::SCREEN_HEIGHT * 0.5f);
	backButtonTexture->SetPosition(-Graphics::SCREEN_WIDTH * 0.9f, -Graphics::SCREEN_HEIGHT * 0.1f);

	//Ryan
	// * = parts of this comment
	// Push all the textures into a list for easier access when deleting and rendering the textures. 
	// The list itself is O(1) while the new render and delete functions are O(n) where n is the size of the list

	gameEntityList.push_back(backgroundTexture);
	gameEntityList.push_back(music1ButtonTexture);
	gameEntityList.push_back(music2ButtonTexture);
	gameEntityList.push_back(music3ButtonTexture); 
	gameEntityList.push_back(backButtonTexture);
}

MusicScreen::~MusicScreen()
{
	// *
	for (int i = gameEntityList.size(); i >= 0; i--)
	{
		delete gameEntityList[i];
		gameEntityList[i] = nullptr;
	}

	delete iconHolder;
	iconHolder = nullptr;

	delete button;
	button = nullptr;
}

MusicScreen* MusicScreen::Instance()
{
	if (sInstance == nullptr)
	{
		sInstance = new MusicScreen();
	}
	return sInstance;
}

void MusicScreen::Render()
{
	// *
	for (int i = 0; i < gameEntityList.size(); i++)
	{
		gameEntityList[i]->Render();
	}
}

void MusicScreen::Update()
{
	if (input->MouseButtonPressed(input->Left)) {

		if (button->ContainsPoint(music1ButtonTexture, input->MousePosition().x, input->MousePosition().y))
		{
			mAudio->CurrentMusic = 0;

			// Ryan
			// created a function to make the buttons modular, also combining with the prior improvement (noted above) to add the 
			// new textures into the texture list. This change has made the buttons more modular but has kept the O(1) notation.

			ToggleButton(music1ButtonTexture, "Buttons.png", 344, 85, 172, 85, 0.75f, 0.5f);
			ToggleButton(music2ButtonTexture, "Buttons.png", 516, 0, 172, 85, 0.5f, 0.5f);
			ToggleButton(music3ButtonTexture, "Buttons.png", 688, 0, 172, 85, 0.25f, 0.5f);

			std::cout << "1\n";
		}
		else if (button->ContainsPoint(music2ButtonTexture, input->MousePosition().x, input->MousePosition().y))
		{
			mAudio->CurrentMusic = 1;

			ToggleButton(music1ButtonTexture, "Buttons.png", 344, 0, 172, 85, 0.75f, 0.5f);
			ToggleButton(music2ButtonTexture, "Buttons.png", 516, 85, 172, 85, 0.5f, 0.5f);
			ToggleButton(music3ButtonTexture, "Buttons.png", 688, 0, 172, 85, 0.25f, 0.5f);

			std::cout << "2\n";
		}
		else if (button->ContainsPoint(music3ButtonTexture, input->MousePosition().x, input->MousePosition().y))
		{
			mAudio->CurrentMusic = 2;

			ToggleButton(music1ButtonTexture, "Buttons.png", 344, 0, 172, 85, 0.75f, 0.5f);
			ToggleButton(music2ButtonTexture, "Buttons.png", 516, 0, 172, 85, 0.5f, 0.5f);
			ToggleButton(music3ButtonTexture, "Buttons.png", 688, 85, 172, 85, 0.25f, 0.5f);

			std::cout << "3\n";
		}
		else if (button->ContainsPoint(backButtonTexture, input->MousePosition().x, input->MousePosition().y))
		{
			std::cout << "4\n";
			//send back to main screen
			back = true;
		}
	}
}

void MusicScreen::ToggleButton(Texture * texture, std::string fileName, int x, int y, int w, int h, float xMod, float yMod) 
{
	// * 
	texture = new Texture(fileName, x, y, w, h);
	texture->SetParent(iconHolder);
	texture->SetPosition(-Graphics::SCREEN_WIDTH * xMod, -Graphics::SCREEN_HEIGHT * yMod);
	gameEntityList.push_back(texture);
}
