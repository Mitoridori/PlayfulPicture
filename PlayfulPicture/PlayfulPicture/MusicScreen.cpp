#include "MusicScreen.h"

MusicScreen::MusicScreen()
{
	mTimer = Timer::Instance();
	mInput = InputManager::Instance();
	mAudio = AudioManager::Instance();

	button = new Buttons();

	iconHolder = new GameEntity(Graphics::SCREEN_WIDTH, Graphics::SCREEN_HEIGHT);
	music1ButtonTexture = new Texture("3x3.png", 0, 0, 238, 200);
	music2ButtonTexture = new Texture("4x4.png", 0, 0, 238, 200);
	music3ButtonTexture = new Texture("5x5.png", 0, 0, 238, 200);
	backButtonTexture = new Texture("5x5.png", 0, 0, 238, 200);

	//iconHolder->SetParent(this);
	music1ButtonTexture->SetParent(iconHolder);
	music2ButtonTexture->SetParent(iconHolder);
	music3ButtonTexture->SetParent(iconHolder);
	backButtonTexture->SetParent(iconHolder);

	music1ButtonTexture->SetPosition(-Graphics::SCREEN_WIDTH * 0.8f, -Graphics::SCREEN_HEIGHT * 0.75f);
	music2ButtonTexture->SetPosition(-Graphics::SCREEN_WIDTH * 0.8f, -Graphics::SCREEN_HEIGHT * 0.50f);
	music3ButtonTexture->SetPosition(-Graphics::SCREEN_WIDTH * 0.8f, -Graphics::SCREEN_HEIGHT * 0.25f);
	backButtonTexture->SetPosition(-Graphics::SCREEN_WIDTH * 0.8f, -Graphics::SCREEN_HEIGHT * 0.25f);
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
