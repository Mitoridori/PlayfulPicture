#pragma once
#ifndef __MENUSCREEN_H
#define __MENUSCREEN_H
#include "Timer.h"
#include "Texture.h"
#include "InputManager.h"

using namespace SDLFramework;

class MenuScreen : public GameEntity{

private:
	Timer* timer;
	InputManager* input;

	GameEntity* SelectOptions;
	GameEntity* StartGameEntity;
	GameEntity* MusicGameEntity;
	GameEntity* QuitGameEntity;

	Texture* StartTexture;
	Texture* MusicTexture;
	Texture* QuitTexture;


public:
	MenuScreen();
	~MenuScreen();
	void Update() override;
	void Render() override;
};
#endif