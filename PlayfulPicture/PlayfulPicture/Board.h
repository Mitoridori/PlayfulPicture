#pragma once
#include <SDL.h>
#include "Graphics.h"
#include "DifficultyScreen.h"
#include "PictureSelectScreen.h"
#include "Tile.h"
#include "RandomNumber.h"



namespace SDLFramework {
	class Board : public GameEntity{

	private:

		Graphics* graphics;
		InputManager* input;
		RandomNumber* random;

		bool didCreateBoard = false;
		bool firstPicture = true;
		bool gameOver;
		bool tilesSwapped;
		int activeTile = -1;
		std::string ImageName;

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
		int startY = 98;
		int startX = 166;
		int tilenum;
		int gridSize = 700;
		//array
		int **gridLocation;
		int tempX;
		int tempY;
		int lastTileX;
		int lastTileY;

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

		void createPositions(std::vector<SDL_Rect>& positions, const int& gridsize);

		void makeTiles(std::vector<Tile>& tiles, const std::vector<SDL_Rect>& positions, const int& tiletype);

		void scrambleTiles(std::vector<Tile>& t, std::vector<Tile>& tshadow);

		void GetPicture();

		void renderPicture(const std::vector<Tile>& tiles, const std::vector<SDL_Rect>& positions);

		void CreateBoard();
		void createArray();

		void swapArray(Tile& t,Tile& t2, Tile& tS, Tile& tS2);

		void SetChallange(int difficulty);

		int getActiveTile(const int& x, const int& y);

		bool isBeside(const Tile& a, const Tile& b);

		bool isSolved();

	};



}