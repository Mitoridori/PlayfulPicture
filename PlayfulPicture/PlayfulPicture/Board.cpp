#include "Board.h"
#include <random>



namespace SDLFramework {
	Board::Board()
	{
		graphics = Graphics::Instance();
		input = InputManager::Instance();

		boardHolder = new GameEntity(Graphics::SCREEN_WIDTH, Graphics::SCREEN_HEIGHT);

		challenge = 1;


	}

	Board::~Board()
	{
		graphics = nullptr;

	}

	void Board::Update()
	{

		if (input->MouseButtonPressed(input->Left)) {

			int x; int y;
			SDL_GetMouseState(&x, &y);
			activeTile = getActiveTile(x, y); // retreives clicked tile number or -1

		}

		if (isSolved()) {
			gameOver = true;
		}

		else if (activeTile >= 0) { // if mouse clicked on a tile
			if (isBeside(tiles[activeTile], tiles[tiles.size() - 1])) {
				tiles[activeTile].swap(tiles[tiles.size() - 1]);
				shadowTiles[activeTile].swap(shadowTiles[shadowTiles.size() - 1]);
				activeTile = -1; // reset to default
			}

		}

	}

	void Board::Render()
	{
		drawBoard(shadowTiles);
		drawBoard(tiles);
		if (didCreateBoard == false) {
			CreateBoard();
		}
		renderPicture(tiles, positions);
	}

	void Board::drawBoard(const std::vector<Tile>& t) {
		for (int i = 0; i < t.size(); ++i) {
			SDL_Rect temp = t[i].position();

			if (t[i].tileType() == Tile::type::invisible)
				SDL_SetRenderDrawColor(graphics->GetRenderer(), 163, 118, 172, 1); // bg colour

			else if (t[i].tileType() == Tile::type::rollover || t[i].tileType() == Tile::type::buttonpressed)
				SDL_SetRenderDrawColor(graphics->GetRenderer(), 255, 255, 255, 1); // highlight colour

			else if (t[i].tileType() == Tile::type::shadow)
				SDL_SetRenderDrawColor(graphics->GetRenderer(), 100, 65, 107, 1); // shadow colour

			else
				SDL_SetRenderDrawColor(graphics->GetRenderer(), 237, 229, 239, 1); // default colour

			SDL_RenderFillRect(graphics->GetRenderer(), &temp);
		}
	}

	void Board::createPositions(std::vector<SDL_Rect>& positions, const int& gridsize) {
		int startY = 98;
		int startX = 166;
		int x = startY;
		int y = startX;

		for (int i = 0; i < gridsize; ++i) {
			y = startY + i * tileSize + i * 5 + 2;
			for (int j = 0; j < gridsize; ++j) {
				x = startX + j * tileSize + j * 5 + 2;
				positions.push_back(SDL_Rect{ x, y, static_cast<int>(tileSize), static_cast<int>(tileSize) });
			}
		}
	}

	void Board::makeTiles(std::vector<Tile>& tiles, const std::vector<SDL_Rect>& positions, const int& tiletype) {
		for (int i = 0; i < positions.size(); ++i) {
			tiles.push_back(Tile{ positions[i], i + 1, tiletype }); // start counting from 1 for positions
		}
		tiles[tiles.size() - 1].setTileType(Tile::type::invisible); // last tile should be invisible
	}

	void Board::scrambleTiles(std::vector<Tile>& t, std::vector<Tile>& tshadow)
	{
		std::random_device rd;
		std::mt19937 rng(rd());
		std::uniform_int_distribution<int> tilerange(0, t.size() - 2); // don't scramble last ('empty') tile

		for (int i = t.size() - 2; i >= 0; --i) {
			int n = tilerange(rng);
			t[i].swap(t[n]);
			tshadow[i].swap(tshadow[n]);
		}
	}

	void Board::renderPicture(const std::vector<Tile>& tiles, const std::vector<SDL_Rect>& positions) {
		// for all but the last (invisible) tile
		int a = 0;
		int b = 0;
		int z = 0;
		int w = 0;
		for (int i = tiles.size() - 2; i >= 0; --i) {			
			//a = tileSize * z;
			//z++;
			for (int j = tiles.size() - 2; j >= 0; --j) {
				//b = tileSize * w;
				//w++;
				switch (PictureSelectScreen::GetSelectedPicture()) {
				case 1:
					tilePiece = new Texture("Image1.png", a, b, tileSize, tileSize);
					break;
				case 2:
					tilePiece = new Texture("Image2.png", a, b, tileSize, tileSize);
					break;
				case 3:
					tilePiece = new Texture("Image3.png", a, b, tileSize, tileSize);
					break;
				case 4:
					tilePiece = new Texture("Image4.png", a, b, tileSize, tileSize);
					break;
				case 5:
					tilePiece = new Texture("Image5.png", a, b, tileSize, tileSize);
					break;
				case 6:
					tilePiece = new Texture("Image6.png", a, b, tileSize, tileSize);
					break;
				}
				tilePiece->SetParent(boardHolder);
				tilePiece->SetPosition(-tiles[j].position().x - tileSize/2, -tiles[j].position().y - tileSize / 2);
				tilePiece->Render();
			}
		}
	}

	void Board::CreateBoard(/*Take in tile size*/)
	{
		SetChallange(DifficultyScreen::GetDifficulty());
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

		// Fill vector<SDL_Rect> 'positions' with possible positions of n*n tiles & make shadow positions
		createPositions(positions, row);
		createPositions(shadowPositions, row);
		// Assign these starting positions to n*n tiles in vector<Tile> 'tiles' & make tile shadows
		makeTiles(tiles, positions, Tile::type::button);
		makeTiles(shadowTiles, shadowPositions, Tile::type::shadow);
		scrambleTiles(tiles, shadowTiles);
		didCreateBoard = true;
	}

	void Board::SetChallange(int difficulty)
	{
		challenge = difficulty;
	}


	int Board::getActiveTile(const int& x, const int& y) {
		int tilenum = -1;
		for (int i = 0; i < tiles.size(); ++i) {
			if (!(x < tiles[i].position().x || x > tiles[i].position().x + tileSize ||
				y < tiles[i].position().y || y > tiles[i].position().y + tileSize))
				tilenum = i;
		}
		return tilenum;
	}

	bool Board::isBeside(const Tile& a, const Tile& b) {
		if (a.posNumber() == b.posNumber() - 1 ||
			a.posNumber() == b.posNumber() + 1 ||
			a.posNumber() == b.posNumber() + row ||
			a.posNumber() == b.posNumber() - row)
			return true;
		return false;
	}

	bool Board::isSolved() {
		int correctTilesN = 0;

		for (int i = 0; i < tiles.size(); ++i) {
			if (tiles[i].position().x == positions[i].x &&
				tiles[i].position().y == positions[i].y)
				correctTilesN += 1;
		}
		if (correctTilesN == row * row)
			return true;
		return false;
	}

}