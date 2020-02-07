#include "MusicScreen.h"

MusicScreen* MusicScreen::sInstance = nullptr;

MusicScreen::MusicScreen()
{
	mTimer = Timer::Instance();
	mInput = InputManager::Instance();
	mAudio = AudioManager::Instance();

	button = new Buttons();

	iconHolder = new GameEntity(Graphics::SCREEN_WIDTH, Graphics::SCREEN_HEIGHT);
	music1ButtonTexture = new Texture("Buttons.jpg", 0, 0, 238, 200);
	music2ButtonTexture = new Texture("Buttons.jpg", 0, 0, 238, 200);
	music3ButtonTexture = new Texture("Buttons.jpg", 0, 0, 238, 200);
	backButtonTexture = new Texture("Buttons.jpg", 0, 0, 238, 200);

	//iconHolder->SetParent(this);
	music1ButtonTexture->SetParent(iconHolder);
	music2ButtonTexture->SetParent(iconHolder);
	music3ButtonTexture->SetParent(iconHolder);
	backButtonTexture->SetParent(iconHolder);

	music1ButtonTexture->SetPosition(-Graphics::SCREEN_WIDTH * 0.25f, -Graphics::SCREEN_HEIGHT * 0.5f);
	music2ButtonTexture->SetPosition(-Graphics::SCREEN_WIDTH * 0.5f, -Graphics::SCREEN_HEIGHT * 0.5f);
	music3ButtonTexture->SetPosition(-Graphics::SCREEN_WIDTH * 0.75f, -Graphics::SCREEN_HEIGHT * 0.5f);
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
		}
		else if (button->ContainsPoint(music2ButtonTexture, mInput->MousePosition().x, mInput->MousePosition().y)) 
		{
			mAudio->PlaySFX("Music/reCreation.mp3", 0, 1);
		}
		else if (button->ContainsPoint(music3ButtonTexture, mInput->MousePosition().x, mInput->MousePosition().y)) 
		{
			mAudio->PlaySFX("Music/The_Mellotron.mp3", 0, 1);
		}
		else if (button->ContainsPoint(backButtonTexture, mInput->MousePosition().x, mInput->MousePosition().y))
		{
			//send back to main screen
		}
		else 
		{	
		}
	}
}
