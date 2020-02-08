#pragma once
#ifndef __MENUSCREEN_H
#define __MENUSCREEN_H
#include "Timer.h"
#include "Texture.h"
#include "InputManager.h"
#include "Buttons.h"
#include "AnimatedTexture.h"

using namespace SDLFramework;

class MenuScreen : public GameEntity{

private:
	Timer* timer;
	InputManager* input;

	Buttons* button;

	GameEntity* GreaterScreen;
	GameEntity* SelectOptions;
	GameEntity* StartGameEntity;
	GameEntity* MusicGameEntity;
	GameEntity* QuitGameEntity;

	Texture* backgroundTexture;

	Texture* StartTexture;
	Texture* MusicTexture;
	Texture* QuitTexture;

	AnimatedTexture* AnimatedHeader;

public:
	MenuScreen();
	~MenuScreen();
	void Update() override;
	void Render() override;

	bool game;
	bool music;
	bool quit;
};
#endif