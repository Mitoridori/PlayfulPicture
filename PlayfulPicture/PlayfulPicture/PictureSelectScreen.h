//FILE: PictureSelectScreen.h
//PROJECT: PlayfulPictures
//PROGRAMMER: John Gotts
//FIRST VERSION: 02/06/2020
#pragma once
#include "Screens.h"
#include "Texture.h"
using namespace SDLFramework;

class PictureSelectScreen : public Screens {

private:
	static enum Pictures {none, one, two, three, four, five, six};
	static Pictures selectedPicture;

	GameEntity* topBar;
	Texture* screenLabel;

	GameEntity* pictureHolder;
	Texture* thumbnail1;
	Texture* thumbnail2;
	Texture* thumbnail3;
	Texture* thumbnail4;
	Texture* thumbnail5;
	Texture* thumbnail6;
	Texture* backgroundImage;

public:
	PictureSelectScreen();
	~PictureSelectScreen();
	void Render() override;
	void Update() override;

	static Pictures GetSelectedPicture();
};