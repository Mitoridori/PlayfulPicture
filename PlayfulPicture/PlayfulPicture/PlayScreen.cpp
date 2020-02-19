#include "PlayScreen.h"

/* John Gotts
	The changes made to this class are as follows:
	- The variables for the screen elements such as the board and the player UI, have now been stored in an array of type GameEntity, this has been done
		to keep with Big-O notation for O(1), this was done to make accessing the elements faster with less calls to specific variables in the code
	- This was done to keep a constant time for compile time, versus a somewhat lengthy compile time*/

int SDLFramework::PlayScreen::totalMoves = 0;

SDLFramework::PlayScreen::PlayScreen() : Screens()
{
	playerUI = new InGameUI();

	board = new Board();

	//John Gotts: adding elements to a vector to store them in one place for any further calls.
	gameEntityList.push_back(playerUI);
	gameEntityList.push_back(board);
}

SDLFramework::PlayScreen::~PlayScreen()
{

	//clearing the objects from the vector and calling their deconstructors
	for (int i = gameEntityList.size(); i >= 0; i--)
	{
		delete gameEntityList[i];
		gameEntityList[i] = nullptr;
	}
	delete[] & gameEntityList;
}

InGameUI* SDLFramework::PlayScreen::GetPlayerUI()
{
	return playerUI;
}

void SDLFramework::PlayScreen::Update()
{
	//updating the elements in the vector
	for (unsigned int i = 0; i < gameEntityList.size(); i++)
	{
		gameEntityList[i]->Update();
	}
}

void SDLFramework::PlayScreen::Render()
{
	//rendering the objects from the vector
	for (unsigned int i = 0; i < gameEntityList.size(); i++)
	{
		gameEntityList[i]->Render();
	}
}

int SDLFramework::PlayScreen::GetTotalMoves()
{
	return totalMoves;
}

void SDLFramework::PlayScreen::IncrementTotalMoves(int amount)
{
	totalMoves += amount;
}
