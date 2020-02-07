#include "MusicScreen.h"

MusicScreen* MusicScreen::sInstance = nullptr;

MusicScreen::MusicScreen()
{
	mTimer = Timer::Instance();
	mInput = InputManager::Instance();
	mAudio = AudioManager::Instance();

	button = new Buttons();

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
}

MusicScreen::~MusicScreen()
{
	mTimer = nullptr;
	mInput = nullptr;

	delete iconHolder;
	iconHolder = nullptr;

	delete music1ButtonTexture;
	music1ButtonTexture = nullptr;

	delete music2ButtonTexture;
	music2ButtonTexture = nullptr;

	delete music3ButtonTexture;
	music3ButtonTexture = nullptr;

	delete backButtonTexture;
	backButtonTexture = nullptr;

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
	backgroundTexture->Render();
	music1ButtonTexture->Render();
	music2ButtonTexture->Render();
	music3ButtonTexture->Render();
	backButtonTexture->Render();
}

void MusicScreen::Update()
{
	if (mInput->MouseButtonPressed(mInput->Left)) {

		if (button->ContainsPoint(music1ButtonTexture, mInput->MousePosition().x, mInput->MousePosition().y))
		{
			mAudio->PlaySFX("Music/Intoleranzen.mp3", 0, 1);

			/*ToggleButton(music1ButtonTexture, "Buttons.png", 344, 85, 172, 85, 0.75f, 0.5f);
			ToggleButton(music2ButtonTexture, "Buttons.png", 516, 0, 172, 85, 0.5f, 0.5f);
			ToggleButton(music3ButtonTexture, "Buttons.png", 688, 0, 172, 85, 0.25f, 0.5f);*/

			music1ButtonTexture = new Texture("Buttons.png", 344, 85, 172, 85);
			music2ButtonTexture = new Texture("Buttons.png", 516, 0, 172, 85);
			music3ButtonTexture = new Texture("Buttons.png", 688, 0, 172, 85);
			music1ButtonTexture->SetParent(iconHolder);
			music2ButtonTexture->SetParent(iconHolder);
			music3ButtonTexture->SetParent(iconHolder);
			music1ButtonTexture->SetPosition(-Graphics::SCREEN_WIDTH * 0.75f, -Graphics::SCREEN_HEIGHT * 0.5f);
			music2ButtonTexture->SetPosition(-Graphics::SCREEN_WIDTH * 0.5f, -Graphics::SCREEN_HEIGHT * 0.5f);
			music3ButtonTexture->SetPosition(-Graphics::SCREEN_WIDTH * 0.25f, -Graphics::SCREEN_HEIGHT * 0.5f);

			std::cout << "1\n";
		}
		else if (button->ContainsPoint(music2ButtonTexture, mInput->MousePosition().x, mInput->MousePosition().y))
		{
			mAudio->PlaySFX("Music/reCreation.mp3", 0, 1);

		/*	ToggleButton(music1ButtonTexture, "Buttons.png", 344, 0, 172, 85, 0.75f, 0.5f);
			ToggleButton(music2ButtonTexture, "Buttons.png", 516, 85, 172, 85, 0.5f, 0.5f);
			ToggleButton(music3ButtonTexture, "Buttons.png", 688, 0, 172, 85, 0.25f, 0.5f);*/

			//Steve checked and couldn't figure it out
			music1ButtonTexture = new Texture("Buttons.png", 344, 0, 172, 85);
			music2ButtonTexture = new Texture("Buttons.png", 516, 85, 172, 85);
			music3ButtonTexture = new Texture("Buttons.png", 688, 0, 172, 85);
			music1ButtonTexture->SetParent(iconHolder);
			music2ButtonTexture->SetParent(iconHolder);
			music3ButtonTexture->SetParent(iconHolder);
			music1ButtonTexture->SetPosition(-Graphics::SCREEN_WIDTH * 0.75f, -Graphics::SCREEN_HEIGHT * 0.5f);
			music2ButtonTexture->SetPosition(-Graphics::SCREEN_WIDTH * 0.5f, -Graphics::SCREEN_HEIGHT * 0.5f);
			music3ButtonTexture->SetPosition(-Graphics::SCREEN_WIDTH * 0.25f, -Graphics::SCREEN_HEIGHT * 0.5f);

			std::cout << "2\n";
		}
		else if (button->ContainsPoint(music3ButtonTexture, mInput->MousePosition().x, mInput->MousePosition().y))
		{
			mAudio->PlaySFX("Music/The_Mellotron.mp3", 0, 1);

			music1ButtonTexture = new Texture("Buttons.png", 344, 0, 172, 85);
			music2ButtonTexture = new Texture("Buttons.png", 516, 0, 172, 85);
			music3ButtonTexture = new Texture("Buttons.png", 688, 85, 172, 85);
			music1ButtonTexture->SetParent(iconHolder);
			music2ButtonTexture->SetParent(iconHolder);
			music3ButtonTexture->SetParent(iconHolder);
			music1ButtonTexture->SetPosition(-Graphics::SCREEN_WIDTH * 0.75f, -Graphics::SCREEN_HEIGHT * 0.5f);
			music2ButtonTexture->SetPosition(-Graphics::SCREEN_WIDTH * 0.5f, -Graphics::SCREEN_HEIGHT * 0.5f);
			music3ButtonTexture->SetPosition(-Graphics::SCREEN_WIDTH * 0.25f, -Graphics::SCREEN_HEIGHT * 0.5f);;

			std::cout << "3\n";
		}
		else if (button->ContainsPoint(backButtonTexture, mInput->MousePosition().x, mInput->MousePosition().y))
		{
			std::cout << "4\n";
			//send back to main screen
		}
		else
		{
		}
	}
}

//Steve checked and couldn't figure it out
void MusicScreen::ToggleButton(Texture * texture, std::string fileName, int x, int y, int w, int h, float xMod, float yMod) 
{
	texture = new Texture(fileName, x, y, w, h);
	texture->SetParent(iconHolder);
	texture->SetPosition(-Graphics::SCREEN_WIDTH * xMod, -Graphics::SCREEN_HEIGHT * yMod);
}
