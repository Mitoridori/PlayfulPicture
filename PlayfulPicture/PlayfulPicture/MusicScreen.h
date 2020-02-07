#pragma once
#include "GameEntity.h"
#include "Timer.h"
#include "Texture.h"
#include "InputManager.h"
#include "AudioManager.h"
#include "Buttons.h"

using namespace SDLFramework;

class MusicScreen {

private:
	static MusicScreen* sInstance;

	Timer* mTimer;
	InputManager* mInput;
	AudioManager* mAudio;

	GameEntity* iconHolder;
	Texture* music1ButtonTexture;
	Texture* music2ButtonTexture;
	Texture* music3ButtonTexture;
	Texture* backButtonTexture;

	Buttons* button;

public:
	MusicScreen();
	~MusicScreen();

	static MusicScreen* Instance();

	void Render();
	void Update();
};