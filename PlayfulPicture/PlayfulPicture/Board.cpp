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

		//CreateBoard();
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
		CreateBoard();
		drawBoard(shadowTiles);
		drawBoard(tiles);

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

				if (t[i].tileType() != Tile::type::invisible) {
					
					std::string num = std::to_string(i + 1); // position numbers count from 1
					screenLabel = new Texture(num, "emulogic.ttf", 24, { 255, 0, 111 });
					screenLabel->SetPosition(tileSize / 2, tileSize / 2);
					screenLabel->Render();
					
					//SDL_QueryTexture(screenLabel, NULL, NULL, &temp.w, &temp.h);
					//graphics->renderTexture(screenLabel, temp.x + (tileSize / 2 - temp.w / 2), temp.y + (tileSize / 2 - temp.h / 2), nullptr);
				}
		}
	}

	void Board::loadPositions(std::vector<SDL_Rect>& positions, const int& gridsize) {
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
		for (int i = tiles.size() - 2; i >= 0; --i) {
			for (int j = tiles.size() - 2; j >= 0; --j) {
				// 'attach' tile position n to position of cat photo
				SDL_Rect temp = positions[j];
				Texture* tilePiece;
				tilePiece = new Texture("rose.jpg", 0, 0, tileSize, tileSize);
				tilePiece->SetParent(boardHolder);
				tilePiece->SetPosition(tiles[j].position().x, tiles[j].position().y);
				tilePiece->Render();
				//render(cat, tiles[j].position().x, tiles[j].position().y, &temp);
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
		loadPositions(positions, row);
		loadPositions(shadowPositions, row);
		// Assign these starting positions to n*n tiles in vector<Tile> 'tiles' & make tile shadows
		makeTiles(tiles, positions, Tile::type::button);
		makeTiles(shadowTiles, shadowPositions, Tile::type::shadow);

		//renderPicture(tiles, positions);

		scrambleTiles(tiles, shadowTiles);

	}

	void Board::SetChallange(int difficulty)
	{
		challenge = difficulty;
	}



}