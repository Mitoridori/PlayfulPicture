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
		//draw board to be 700 by 700
		switch (challange)
		{
		case beginner:
			boardSize = 700 / 3;
			break;
		case intermediate:
			boardSize = 700 / 4;
			break;
		case hard:
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

	void Board::SetChallange(Challange difficulty)
	{
		challange = difficulty;
	}



}