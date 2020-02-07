#pragma once
#include "Timer.h"
#include "Texture.h"
#include "InputManager.h"
#include "Buttons.h"
#include "PlayScreen.h"

using namespace SDLFramework;

class WinScreen : public GameEntity {

public:
	bool menu = false;
	bool quit = false;

private:
	Timer* timer;
	InputManager* input;

	Texture* backgroundImage;

	GameEntity* topBar;
	Texture* screenLabel;
	Texture* movesCounter;

	GameEntity* buttonHolder;
	Texture* menuButtonTexture;
	Texture* quitButtonTexture;

	Buttons* button;

public:
	WinScreen();
	~WinScreen();
	void Render() override;
	void Update() override;
};