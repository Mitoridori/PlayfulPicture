#pragma once
#ifndef __MENUSCREEN_H
#define __MENUSCREEN_H
#include "Texture.h"
#include "AnimatedTexture.h"
#include "Screens.h"

using namespace SDLFramework;

class MenuScreen : public Screens{

private:

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