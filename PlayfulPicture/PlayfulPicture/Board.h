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
		float tileSize;

		int sliceX;
		int sliceY;
		int pieceAmount;
		int column;
		int row;

		Texture* boardBackground;
		GameEntity* boardHolder;
		//Texture* pieceTexture[pieceAmount];
		Texture* tilePiece;

		std::vector<Texture> Tiles;
		

	public:
		Board();
		~Board();

		



		void Update() override;
		void Render() override;

		void loadTiles(std::vector<Texture>& Tiles, const int& gridsize);

		void scrambleTiles(/*std::vector<Tile>& t, std::vector<Tile>& tshadow*/);

		void CreateBoard();
		void SetChallange(int difficulty);

	};



}