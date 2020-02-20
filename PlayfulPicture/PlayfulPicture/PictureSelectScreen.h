//FILE: PictureSelectScreen.h
//PROJECT: PlayfulPictures
//PROGRAMMER: John Gotts
//FIRST VERSION: 02/06/2020
#pragma once
#include "Screens.h"
#include "Texture.h"
#include <algorithm>
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

private:
	template<typename T>
	int Binary_Search(const vector<T*> &v, const T &value, const int xPos, const int yPos)
	{
		int low = 0;
		int high = (int)v.size() - 1;


		while (low <= high) {
			int mid = (low + high) / 2;
			if (v[mid] > value)
				high = mid - 1;
			else if (v[mid] < value)
				low = mid + 1;
			else
				return mid;  // found
		}
		return -1;  // not found
	}
};

