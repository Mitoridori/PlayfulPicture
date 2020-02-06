#pragma once
#include "Texture.h"

using namespace SDLFramework;

class Buttons {

public:
	Buttons();
	~Buttons();
	bool ContainsPoint(Texture* texture, int x, int y);
};