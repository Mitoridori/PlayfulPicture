#include "MenuScreen.h"

MenuScreen::MenuScreen()
{
	//General Game Entity for the Menu and the Entities ontop of it
	SelectOptions = new GameEntity(Graphics::SCREEN_WIDTH, Graphics::SCREEN_HEIGHT);
	StartGameEntity = new GameEntity(60.0f, 20.0f);
	MusicGameEntity = new GameEntity(60.0f, 20.0f);
	QuitGameEntity = new GameEntity(60.0f, 20.0f);

	//Textures inside the Game Entities
	StartTexture = new Texture("Buttons.png", 860, 0, 172, 85);
	MusicTexture = new Texture("Buttons.png", 1032, 0, 172, 85);
	QuitTexture = new Texture("Buttons.png", 1204, 0, 172, 85);

	//Place Entities
	SelectOptions->SetParent(this);

	StartGameEntity->SetParent(SelectOptions);
	MusicGameEntity->SetParent(SelectOptions);
	QuitGameEntity->SetParent(SelectOptions);

	StartTexture->SetParent(StartGameEntity);
	MusicTexture->SetParent(MusicGameEntity);
	QuitTexture->SetParent(QuitGameEntity);

	//Set Positions
	SelectOptions->SetPosition(Graphics::SCREEN_WIDTH * 0.5, Graphics::SCREEN_HEIGHT * 0.5);

	StartGameEntity->SetPosition(0.0f, Graphics::SCREEN_HEIGHT * -0.3f);
	MusicGameEntity->SetPosition(0.0f, 0.0f);
	QuitGameEntity->SetPosition(0.0f, Graphics::SCREEN_HEIGHT * 0.3f);



}

MenuScreen::~MenuScreen()
{
	//Delete the Game Entities
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
}

void MenuScreen::Update()
{
	
}

void MenuScreen::Render()
{
	//Render the Textures
	StartTexture->Render();
	MusicTexture->Render();
	QuitTexture->Render();
}
