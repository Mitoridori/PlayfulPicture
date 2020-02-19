#include "WinScreen.h"

/*John Gotts optimization changes:
	- stored all local textures to a vector in the parent class, this follows the O(1) as accessing the array is a constant time for compile time
	- the render and update were changed to follow the O(n) format as they now access the elements of the individual array index to render them
	- the menu and quit bools were made private and then functions were made to access them from outside of this class to avoid global variables*/

WinScreen::WinScreen() : Screens()
{
	topBar = new GameEntity(Graphics::SCREEN_WIDTH, 50.0f);
	screenLabel = new Texture("You Win!!", "emulogic.ttf", 32, { 255, 0, 111 });
	topBar->SetParent(this);
	screenLabel->SetParent(topBar);
	screenLabel->SetPosition(-Graphics::SCREEN_WIDTH * 0.5f, 0.0f);

	buttonHolder = new GameEntity(Graphics::SCREEN_WIDTH, Graphics::SCREEN_HEIGHT);
	menuButtonTexture = new Texture("Buttons.png", 0, 0, 172, 85);
	quitButtonTexture = new Texture("Buttons.png", 1204, 0, 172, 85);

	movesCounter = new Texture("Total Moves: " + PlayScreen::GetTotalMoves(), "emulogic.ttf", 32, { 255, 0, 111 });
	movesCounter->SetParent(buttonHolder);
	movesCounter->SetPosition(-Graphics::SCREEN_WIDTH * 0.7f, -Graphics::SCREEN_HEIGHT * 0.5f);

	backgroundImage = new Texture("Background.jpg", 0, 0, 1760, 1200);

	buttonHolder->SetParent(this);
	menuButtonTexture->SetParent(buttonHolder);
	quitButtonTexture->SetParent(buttonHolder);
	backgroundImage->SetParent(buttonHolder);

	menuButtonTexture->SetPosition(-Graphics::SCREEN_WIDTH * 0.2f, -Graphics::SCREEN_HEIGHT * 0.3f);
	quitButtonTexture->SetPosition(-Graphics::SCREEN_WIDTH * 0.8f, -Graphics::SCREEN_HEIGHT * 0.3f);
	backgroundImage->SetPosition(-Graphics::SCREEN_WIDTH * 0.5f, -Graphics::SCREEN_HEIGHT * 0.5f);

	gameEntityList.push_back(backgroundImage);
	gameEntityList.push_back(screenLabel);
	gameEntityList.push_back(menuButtonTexture);
	gameEntityList.push_back(quitButtonTexture);
	gameEntityList.push_back(movesCounter);
}

WinScreen::~WinScreen()
{
	delete topBar;
	topBar = nullptr;

	delete buttonHolder;
	buttonHolder = nullptr;

	delete button;
	button = nullptr;

	for (int i = 0; i < gameEntityList.size(); i++)
	{
		delete gameEntityList[i];
		gameEntityList[i] = nullptr;
	}
	delete[] &gameEntityList;
}

void WinScreen::Render()
{
	for (int i = 0; i < gameEntityList.size(); i++)
	{
		gameEntityList[i]->Render();
	}
}

void WinScreen::Update()
{
	if (input->MouseButtonPressed(input->Left)) {
		if (button->ContainsPoint(menuButtonTexture, input->MousePosition().x, input->MousePosition().y)) {
			menu = true;
		}
		else if (button->ContainsPoint(quitButtonTexture, input->MousePosition().x, input->MousePosition().y)) {
			quit = true;
		}

	}
}

bool WinScreen::GetMenu()
{
	return menu;
}

bool WinScreen::GetQuit()
{
	return quit;
}
