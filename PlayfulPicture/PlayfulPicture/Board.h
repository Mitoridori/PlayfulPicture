#pragma once
#include <SDL.h>
#include "Graphics.h"

namespace SDLFramework {
	class Board {

	private:

		Graphics* graphics;

		enum Challange {beginner, intermediate, hard};
		Challange challange;
		//make setter

		float boardSize;
		float tileWidth;
		float tileHeight;


	public:
		Board();
		~Board();

		void CreateBoard();


	};



}