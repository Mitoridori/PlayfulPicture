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

using namespace SDLFramework;
class DifficultyScreen : public GameEntity {

private:
	Timer* timer;

	InputManager* input;

	GameEntity* topBar;
	Texture* screenLabel;

	GameEntity* iconHolder;
	Texture* easyButton;
	Texture* mediumButton;
	Texture* hardButton;

public:
	DifficultyScreen();
	~DifficultyScreen();
	void Render() override;
	void Update() override;

	bool ContainsPoint(Texture* texture, int x, int y);
};