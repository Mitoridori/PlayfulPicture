#pragma once
#include "Texture.h"
#include "PlayScreen.h"
#include "Screens.h"

using namespace SDLFramework;

class WinScreen : public Screens {

private:

	Texture* backgroundImage;

	GameEntity* topBar;
	Texture* screenLabel;
	Texture* movesCounter;

	GameEntity* buttonHolder;
	Texture* menuButtonTexture;
	Texture* quitButtonTexture;

	bool menu = false;
	bool quit = false;

public:
	WinScreen();
	~WinScreen();
	void Render() override;
	void Update() override;

	bool GetMenu();
	bool GetQuit();
};