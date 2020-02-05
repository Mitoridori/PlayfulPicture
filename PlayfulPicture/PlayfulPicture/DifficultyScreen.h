#pragma once
#include "GameEntity.h"
#include "Timer.h"
#include "Texture.h"
#include "InputManager.h"

using namespace SDLFramework;


class DifficultyScreen : public GameEntity {

private:
	Timer* timer;

	InputManager* input;

	GameEntity* iconHolder;
	Texture* easyButton;
	Texture* mediumButton;
	Texture* hardButton;

public:
	DifficultyScreen();
	~DifficultyScreen();
	void Render() override;
	void Update() override;

	void SetGameMode();
};