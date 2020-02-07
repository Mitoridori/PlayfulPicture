#include "MenuScreen.h"

MenuScreen::MenuScreen()
{
	//General Game Entity for the Menu and the Entities ontop of it
	SelectOptions = new GameEntity(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.5f);
	StartGameEntity = new GameEntity(100.0f, 100.0f);
	MusicGameEntity = new GameEntity(100.0f, 100.0f);
	QuitGameEntity = new GameEntity(100.0f, 100.0f);

	//Textures inside the Game Entities
	StartTexture = new Texture("Start Game", "emulogic.ttf", 32, { 230, 230, 230 });
	MusicTexture = new Texture("Music", "emulogic.ttf", 32, { 230, 230, 230 });
	QuitTexture = new Texture("Quit", "emulogic.ttf", 32, { 230, 230, 230 });

	//Place Entities
	SelectOptions->SetParent(this);

	StartGameEntity->SetParent(SelectOptions);
	MusicGameEntity->SetParent(SelectOptions);
	QuitGameEntity->SetParent(SelectOptions);

	StartTexture->SetParent(StartGameEntity);
	MusicGameEntity->SetParent(MusicGameEntity);
	QuitGameEntity->SetParent(QuitGameEntity);

	//Set Positions
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
