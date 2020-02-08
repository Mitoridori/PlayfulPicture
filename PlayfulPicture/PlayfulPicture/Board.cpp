#include "Board.h"




namespace SDLFramework {
	Board::Board()
	{
		graphics = Graphics::Instance();

		boardHolder = new GameEntity(Graphics::SCREEN_WIDTH, Graphics::SCREEN_HEIGHT);


		boardBackground = new Texture("boardBackground.png", 0, 0, 700, 700);
		boardBackground->SetParent(boardHolder);
		boardBackground->SetPosition(-Graphics::SCREEN_WIDTH/2, -Graphics::SCREEN_HEIGHT/2);



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

		tileHeight = boardSize;
		tileWidth = boardSize;




		// create a square
		//SDL_Rect outlineRect = { graphics->SCREEN_WIDTH / 4, graphics->SCREEN_HEIGHT / 4, graphics->SCREEN_WIDTH / 2, graphics->SCREEN_HEIGHT / 2 };
		//SDL_SetRenderDrawColor(graphics->GetRenderer(), 0xFF, 0x00, 0x00, 0xFF);
		//SDL_RenderFillRect(graphics->GetRenderer(), &outlineRect);
		//SDL_RenderDrawRect(graphics->GetRenderer(), &outlineRect);

		//Create a tiled grid
		/*for (int i = 0; i < pieceAmount; i++)
		{
			PieceTexture[i] = new Texture(texture, sliceX, sliceY, (sliceX + boardSize) , boardSize);
			sliceX += boardSize;
			column += 1;
			if (column == row)
			{
				sliceY += boardSize;
				sliceX = 0;
				column = 0;
			}
		}*/


	}

	void Board::SetChallange(int difficulty)
	{
		challenge = difficulty;
	}



}