#include "Board.h"




namespace SDLFramework {
	Board::Board()
	{
		graphics = Graphics::Instance();

	}

	Board::~Board()
	{
		graphics = nullptr;

	}

	void Board::CreateBoard(/*Take in tile size*/)
	{
		//SetChallange(DifficultyScreen::GetDifficulty());
		//draw board to be 700 by 700
		switch (challenge)
		{
		case 1:
			boardSize = 700 / 3;
			break;
		case 2:
			boardSize = 700 / 4;
			break;
		case 3:
			boardSize = 700 / 5;
			break;
		}

		tileHeight = boardSize;
		tileWidth = boardSize;

		// create a square
		SDL_Rect outlineRect = { 0, 0, 700, 700 };
		SDL_SetRenderDrawColor(graphics->GetRenderer(), 0xFF, 0x00, 0x00, 0xFF);
		SDL_RenderFillRect(graphics->GetRenderer(), &outlineRect);
		SDL_RenderDrawRect(graphics->GetRenderer(), &outlineRect);

		//Create a tiled grid



	}

	void Board::SetChallange(int difficulty)
	{
		challenge = difficulty;
	}



}