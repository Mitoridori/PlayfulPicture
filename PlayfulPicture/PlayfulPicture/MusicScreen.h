#pragma once
#include "Screens.h"
#include "Texture.h"
#include "AudioManager.h"
#include <string>

using namespace SDLFramework;

class MusicScreen : public Screens{

private:
	static MusicScreen* sInstance;

	Timer* mTimer;
	InputManager* mInput;
	AudioManager* mAudio;

	GameEntity* iconHolder;
	Texture* backgroundTexture;
	Texture* music1ButtonTexture;
	Texture* music2ButtonTexture;
	Texture* music3ButtonTexture;
	Texture* backButtonTexture;

	Buttons* button;

	void ToggleButton(Texture* texture, std::string fileName, int x, int y, int w, int h, float xMod, float yMod);

public:
	MusicScreen();
	~MusicScreen();

	static MusicScreen* Instance();

	bool back = false;

	void Render();
	void Update();
};