#include "Board.h"



namespace SDLFramework {
	Board::Board()
	{
		graphics = Graphics::Instance();
		input = InputManager::Instance();
		random = RandomNumber::Instance();

		boardHolder = new GameEntity(Graphics::SCREEN_WIDTH, Graphics::SCREEN_HEIGHT);
	}

	Board::~Board()
	{
		graphics = nullptr;
		input = nullptr;
		random = nullptr;

		delete tilePiece;
		tilePiece = nullptr;
	}

	void Board::Update()
	{
		//Ryan
		//Only checks to see if the picture is solved or if the mouse button is pressed on update instead of those plus which tile is active. 
		//Instead it waits for the click to check which tile is active. This is still an O(1), but slightly more optimized.

		if (isSolved())
		{
			gameOver = true;
		}
		else if (input->MouseButtonPressed(input->Left))
		{
			int x; int y;
			SDL_GetMouseState(&x, &y);
			activeTile = getActiveTile(x, y); // retreives clicked tile number or -1
			if (activeTile >= 0 && isBeside(tiles[activeTile], tiles[tiles.size() - 1]))
			{
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
			tilesSwapped = true;
		}
		renderPicture(tiles, positions);
		if (tilesSwapped)
		{
			scrambleTiles(tiles, shadowTiles);
			tilesSwapped = false;
		}
	}

	void Board::drawBoard(const std::vector<Tile>& t) {
		for (int i = 0; i < t.size(); ++i) {
			SDL_Rect temp = t[i].position();

			if (t[i].tileType() == Tile::type::invisible)
				SDL_SetRenderDrawColor(graphics->GetRenderer(), 163, 118, 172, 1); // bg colour

			else if (t[i].tileType() == Tile::type::shadow)
				SDL_SetRenderDrawColor(graphics->GetRenderer(), 100, 65, 107, 1); // shadow colour

			else
				SDL_SetRenderDrawColor(graphics->GetRenderer(), 237, 229, 239, 1); // default colour

			SDL_RenderFillRect(graphics->GetRenderer(), &temp);
		}
	}

	void Board::createPositions(std::vector<SDL_Rect>& positions, const int& gridsize) {
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

	//Rebecca:
	//When this function had the random select information it was having to run it each time it ran the function O(n)
	//now by removing it and putting it in its own function in the RandomNumber it is only run when called. 

	void Board::scrambleTiles(std::vector<Tile>& t, std::vector<Tile>& tshadow)
	{
		for (int i = t.size() - 1; i >= 0; --i) {
			int n = random->RandomTiles(pieceAmount);
			//std::cout << n << std::endl;
			t[i].swap(t[n]);
			tshadow[i].swap(tshadow[n]);
		}
	}

	void Board::GetPicture()
	{
		switch (PictureSelectScreen::GetSelectedPicture())
		{
		case 1:
			ImageName = "number2.png";
			break;
		case 2:
			ImageName = "Image2.png";
			break;
		case 3:
			ImageName = "Image3.png";
			break;
		case 4:
			ImageName = "Image4.png";
			break;
		case 5:
			ImageName = "Image5.png";
			break;
		case 6:
			ImageName = "Image6.png";
			break;
		}
	}
	/* Steven

		More so a good code cleanup.
		however for optimization you defiantly improved your Invoke calls +1.
	*/

	//Rebecca
	//By removing the switch in the for loop to be always picking the picture into its own function, the picture is
	//then only needed to be found once, instead of each time through the loop.
	void Board::renderPicture(const std::vector<Tile>& tiles, const std::vector<SDL_Rect>& positions) {
		// for all but the last (invisible) tile
		float a = 0;
		int b = 0;
		int z = 0;
		int w = tiles.size() - 1;
		int k;
		GetPicture();
		for (int j = tiles.size() - 1; j >= 1; --j) {
			k = w - j;
			a = k / row * tileSize;
			b = z * tileSize;
			if (z > (row - 2))
				z = 0;
			else
				z++;

			tilePiece = new Texture(ImageName, static_cast<int>(a), b, tileSize, tileSize);
			tilePiece->SetParent(boardHolder);
			tilePiece->SetPosition((-tiles[j].position().y - tileSize / 2) - (startY / 2), (-tiles[j].position().x - tileSize / 2) + (startX / 2));
			tilePiece->Render();
		}
	}

	void Board::CreateBoard()
	{
		SetChallange(DifficultyScreen::GetDifficulty());
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
		//scrambleTiles(tiles, shadowTiles);
		didCreateBoard = true;
	}

	void Board::SetChallange(int difficulty)
	{
		challenge = difficulty;
	}

	/* Steven

	 If we were to have a game with 100,000 tiles how long would it take this function to execute?
	 Searching each tile isn't the best idea. perhaps we could have a multi-dimensional array for x and y - this would allow us to visit the exact spot in the array
	 then check our neighbors e.g up, right, down and left.

	 This function executes from update, perhaps we could also hold that information per click? so every time we click we can just store the neighboring tiles until
	 a new tile is selected

	I know Rebecca made this function, however if she isn't planning on editing this guy you can john.
	*/
	int Board::getActiveTile(const int& x, const int& y) {
		int tilenum = -1;
		for (int i = 0; i < tiles.size(); ++i) {
			if (!(x < tiles[i].position().x || x > tiles[i].position().x + tileSize || y < tiles[i].position().y || y > tiles[i].position().y + tileSize))
				tilenum = i;
		}
		std::cout << tilenum << std::endl;
		return tilenum;
	}

	bool Board::isBeside(const Tile& a, const Tile& b) {

		bool move = false;
		float Apos = a.posNumber();
		float Bpos = b.posNumber();

		if (Apos / row == static_cast<int>(Apos / row) && Bpos < Apos)
			move = true;
		else if (Apos / row == static_cast<int>(Apos / row) && Bpos > Apos)
			move = false;
		if (Bpos / row == static_cast<int>(Bpos / row) && Bpos > Apos)
			move = true;
		else if (Bpos / row == static_cast<int>(Bpos / row) && Bpos < Apos)
			move = false;
		if (Apos / row != static_cast<int>(Apos / row) && Bpos / row != static_cast<int>(Bpos / row))
			move = true;
		else if (Apos / row == static_cast<int>(Apos / row) && Bpos / row == static_cast<int>(Bpos / row))
			move = true;

		if (move && (Apos == Bpos - 1 || Apos == Bpos + 1 || Apos == Bpos + row || Apos == Bpos - row))
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