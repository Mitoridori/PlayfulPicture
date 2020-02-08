#pragma once
#include <SDL.h>
#include "Graphics.h"
#include "DifficultyScreen.h"

namespace SDLFramework {
	class Board : public GameEntity{

	private:

		Graphics* graphics;



		/*enum Challange {beginner, intermediate, hard};
		Challange challange;*/
		int challenge;

		float boardSize;
		float tileWidth;
		float tileHeight;

		int sliceX;
		int sliceY;
		int pieceAmount;
		int column;
		int row;

		Texture* boardBackground;
		GameEntity* boardHolder;
		//Texture* pieceTexture[pieceAmount];

	public:
		Board();
		~Board();

		void Update() override;
		void Render() override;


		void CreateBoard();
		void SetChallange(int difficulty);

	};



}