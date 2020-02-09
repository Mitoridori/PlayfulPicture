#include "Board.h"
#include <random>



namespace SDLFramework {
	Board::Board()
	{
		graphics = Graphics::Instance();

		boardHolder = new GameEntity(Graphics::SCREEN_WIDTH, Graphics::SCREEN_HEIGHT);

		//background for tiles
		boardBackground = new Texture("boardBackground.png", 0, 0, 700, 700);
		boardBackground->SetParent(boardHolder);
		boardBackground->SetPosition(-Graphics::SCREEN_WIDTH/2, -Graphics::SCREEN_HEIGHT/2);

		challenge = 1;

		CreateBoard();
	}

	Board::~Board()
	{
		graphics = nullptr;

	}

	void Board::Update()
	{

	}

	void Board::Render()
	{
		boardBackground->Render();

		//for (int i = 0; i < Tiles.size(); i++)
		//{
		//	tilePiece->Render();
		//}
		tilePiece->Render();
	}

	void Board::loadTiles(std::vector<Texture>& Tiles, const int& gridsize)
	{
		int startY = -98;
		int startX = -166;
		int y;
		int x;
		int a;
		int b;
		int n = 0;

		for (int i = 1; i <= gridsize; ++i) {
			y = startY - (tileSize/2 * i);
			a = tileSize * (i - 1);
			for (int j = 1; j <= gridsize; ++j) {
				x = startX - (tileSize / 2 * j);
				b = tileSize * (j - 1);
				
				tilePiece = new Texture("rose.jpg", a, b, tileSize, tileSize);
				tilePiece ->SetParent(boardHolder);
				tilePiece ->SetPosition(x, y);
				tilePiece ->Render();
				n++;

			}
		}
	}

	void Board::scrambleTiles(/*std::vector<Tile>& t, std::vector<Tile>& tshadow*/)
	{
		//std::random_device rd;
		//std::mt19937 rng(rd());
		//std::uniform_int_distribution<int> tilerange(0, t.size() - 2); // don't scramble last ('empty') tile

		//for (int i = t.size() - 2; i >= 0; --i) {
		//	int n = tilerange(rng);
		//	t[i].swap(t[n]);
		//	//tshadow[i].swap(tshadow[n]);
		//}
	}

	void Board::CreateBoard(/*Take in tile size*/)
	{
		//SetChallange(DifficultyScreen::GetDifficulty());
		//draw board to be 700 by 700
		switch (challenge)
		{
		case 1:
			boardSize = 700 / 3;
			pieceAmount = 9;
			row = 3;
			break;
		case 2:
			boardSize = 700 / 4;
			pieceAmount = 16;
			row = 4;
			break;
		case 3:
			boardSize = 700 / 5;
			pieceAmount = 25;
			row = 5;
			break;
		}

		tileSize = boardSize;

		
		loadTiles(Tiles, row);
		



	}

	void Board::SetChallange(int difficulty)
	{
		challenge = difficulty;
	}



}