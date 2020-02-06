//FILE: DifficultyScreen.h
//PROJECT: PlayfulPictures
//PROGRAMMER: John Gotts
//FIRST VERSION: 02/05/2020
#pragma once
#include "GameEntity.h"
#include "Timer.h"
#include "Texture.h"
#include "InputManager.h"
#include "Board.h"
#include "Buttons.h"

using namespace SDLFramework;
class DifficultyScreen : public GameEntity {

private:

	static enum Difficulties {none, easy, medium, hard};
	static Difficulties selectedDifficulty;
	Timer* timer;

	InputManager* input;

	GameEntity* topBar;
	Texture* screenLabel;

	GameEntity* iconHolder;
	Texture* easyButtonTexture;
	Texture* mediumButtonTexture;
	Texture* hardButtonTexture;

	Buttons* easyButton;
	Buttons* mediumButton;
	Buttons* hardButton;

public:
	DifficultyScreen();
	~DifficultyScreen();
	void Render() override;
	void Update() override;

	static Difficulties GetDifficulty();
};