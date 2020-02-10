#pragma once
#include <SDL.h>
#include "Graphics.h"
#include "DifficultyScreen.h"
#include "Tile.h"

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

		Texture* tilePiece;
		Texture* screenLabel;

		SDL_Texture* tilenumber;

		SDL_Colour fontcolour{ 0, 0, 0, 1 };


		std::vector<Texture> Tiles;
		
		std::vector<Tile> tiles;
		std::vector<Tile> shadowTiles;
		std::vector<SDL_Rect> positions;
		std::vector<SDL_Rect> shadowPositions;


	public:
		Board();
		~Board();

		



		void Update() override;
		void Render() override;

		void drawBoard(const std::vector<Tile>& t);

		void loadPositions(std::vector<SDL_Rect>& positions, const int& gridsize);

		void makeTiles(std::vector<Tile>& tiles, const std::vector<SDL_Rect>& positions, const int& tiletype);

		void scrambleTiles(std::vector<Tile>& t, std::vector<Tile>& tshadow);

		void renderPicture(const std::vector<Tile>& tiles, const std::vector<SDL_Rect>& positions);

		void CreateBoard();
		void SetChallange(int difficulty);

	};



}