//FILE: InGameUI.h
//PROJECT: PlayfulPictures
//PROGRAMMER: John Gotts
//FIRST VERSION: 02/07/2020
#pragma once
#include "Timer.h"
#include "GameEntity.h"
#include "Texture.h"
#include "Buttons.h"
#include "InputManager.h"
#include <string>

using namespace SDLFramework;

class InGameUI : public GameEntity {

private:
	Timer* timer;
	InputManager* input;

	GameEntity* topBar;

	Texture* timeCounter;
	Texture* movesCounter;
	Texture* backButtonTexture;
	Buttons* button;
	std::string timeCounterText;

	int totalMoves;
	int seconds;
	int minutes;

	bool quit = false;

public:
	InGameUI();
	~InGameUI();

	void Update() override;
	void Render() override;

	bool GetQuit();

private:
	void UpdateTimeCounterText();
};