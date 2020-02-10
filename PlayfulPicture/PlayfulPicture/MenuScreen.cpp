#include "MenuScreen.h"

MenuScreen::MenuScreen()
{
	input = InputManager::Instance();
	button = new Buttons();

	game = false;
	music = false;
	quit = false;

	//General Game Entity for the Menu and the Entities ontop of it
	GreaterScreen = new GameEntity(Graphics::SCREEN_WIDTH, Graphics::SCREEN_HEIGHT);
	SelectOptions = new GameEntity(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.5f);
	StartGameEntity = new GameEntity(60.0f, 20.0f);
	MusicGameEntity = new GameEntity(60.0f, 20.0f);
	QuitGameEntity = new GameEntity(60.0f, 20.0f);

	//Textures inside the Game Entities
	backgroundTexture = new Texture("Background.jpg", 0, 0, 1760, 1200);

	StartTexture = new Texture("Buttons.png", 860, 0, 172, 85);
	MusicTexture = new Texture("Buttons.png", 1032, 0, 172, 85);
	QuitTexture = new Texture("Buttons.png", 1204, 0, 172, 85);

	//Animated Textures
	AnimatedHeader = new AnimatedTexture("PlayfulPictures logo.png", 0, 0, 440, 150, 3, 0.9f, AnimatedTexture::Horizontal);


	//Place Entities
	GreaterScreen->SetParent(this);

	backgroundTexture->SetParent(GreaterScreen);

	SelectOptions->SetParent(GreaterScreen);

	AnimatedHeader->SetParent(GreaterScreen);

	StartGameEntity->SetParent(SelectOptions);
	MusicGameEntity->SetParent(SelectOptions);
	QuitGameEntity->SetParent(SelectOptions);

	StartTexture->SetParent(StartGameEntity);
	MusicTexture->SetParent(MusicGameEntity);
	QuitTexture->SetParent(QuitGameEntity);

	//Set Positions
	GreaterScreen->SetPosition(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.5f);

	AnimatedHeader->SetPosition(0.0f, -Graphics::SCREEN_HEIGHT * 0.3f);
	
	SelectOptions->SetPosition(0.0f, Graphics::SCREEN_HEIGHT * 0.2f);

	backgroundTexture->SetPosition(0.0f, 0.0f);

	StartGameEntity->SetPosition(50.0f, Graphics::SCREEN_HEIGHT * -0.2f);
	MusicGameEntity->SetPosition(50.0f, 0.0f);
	QuitGameEntity->SetPosition(50.0f, Graphics::SCREEN_HEIGHT * 0.2f);

}

MenuScreen::~MenuScreen()
{
	//Delete Input Manager
	input = nullptr;

	//Delete the Game Entities
	delete GreaterScreen;
	GreaterScreen = nullptr;
	delete SelectOptions;
	SelectOptions = nullptr;

	delete StartGameEntity;
	StartGameEntity = nullptr;
	delete MusicGameEntity;
	MusicGameEntity = nullptr;
	delete QuitGameEntity;
	QuitGameEntity = nullptr;

	//Delete the Textures
	delete StartTexture;
	StartTexture = nullptr;
	delete MusicTexture;
	MusicTexture = nullptr;
	delete QuitTexture;
	QuitTexture = nullptr;

	delete backgroundTexture;
	backgroundTexture = nullptr;

	//Delete Animated Texture
	delete AnimatedHeader;
	AnimatedHeader = nullptr;

	//Delete Buttons
	delete button;
	button = nullptr;
}

void MenuScreen::Update()
{
	//Update Header
	AnimatedHeader->Update();

	//Button Funtionality
	if (input->MouseButtonPressed(input->Left))
	{
		if (button->ContainsPoint(StartTexture, input->MousePosition().x, input->MousePosition().y))
		{
			game = true;
		}
		else if (button->ContainsPoint(MusicTexture, input->MousePosition().x, input->MousePosition().y))
		{
			music = true;
		}
		else if (button->ContainsPoint(QuitTexture, input->MousePosition().x, input->MousePosition().y))
		{
			quit = true;
		}
	}
}

void MenuScreen::Render()
{
	//Render the Textures
	backgroundTexture->Render();

	AnimatedHeader->Render();

	StartTexture->Render();
	MusicTexture->Render();
	QuitTexture->Render();

}
