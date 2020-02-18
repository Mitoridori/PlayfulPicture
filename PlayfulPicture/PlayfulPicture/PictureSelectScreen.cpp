//FILE: PictureSelectScreen.cpp
//PROJECT: PlayfulPictures
//PROGRAMMER: John Gotts
//FIRST VERSION: 02/06/2020
#include "PictureSelectScreen.h"

PictureSelectScreen::Pictures PictureSelectScreen::selectedPicture = none;
/* Steven
	This is considered along the lines of code cleanup, the reason being accessing a variable would also have a bigO of O(1). 

	The performance doesnt actually change here, however I like the cleanup. +0.5
*/
/*John Gotts optimization changes:
	- stored all local textures to a vector in the parent class, this follows the O(1) as accessing the array is a constant time for compile time
	- the render and update were changed to follow the O(n) format as they now access the elements of the individual array index to render them*/

PictureSelectScreen::PictureSelectScreen() : Screens()
{

	topBar = new GameEntity(Graphics::SCREEN_WIDTH, 50.0f);
	screenLabel = new Texture("Picture Selection", "emulogic.ttf", 32, { 255, 0, 111 });
	topBar->SetParent(this);
	screenLabel->SetParent(topBar);
	screenLabel->SetPosition(-Graphics::SCREEN_WIDTH * 0.5f, 0.0f);

	pictureHolder = new GameEntity(Graphics::SCREEN_WIDTH, Graphics::SCREEN_HEIGHT);
	thumbnail1 = new Texture("pic1.png", 0, 0, 238, 200);
	thumbnail2 = new Texture("pic2.png", 0, 0, 238, 200);
	thumbnail3 = new Texture("pic3.png", 0, 0, 238, 200);
	thumbnail4 = new Texture("pic4.png", 0, 0, 238, 200);
	thumbnail5 = new Texture("pic5.png", 0, 0, 238, 200);
	thumbnail6 = new Texture("pic6.png", 0, 0, 238, 200);
	backgroundImage = new Texture("Background.jpg", 0, 0, 1760, 1200);

	pictureHolder->SetParent(this);
	thumbnail1->SetParent(pictureHolder);
	thumbnail2->SetParent(pictureHolder);
	thumbnail3->SetParent(pictureHolder);
	thumbnail4->SetParent(pictureHolder);
	thumbnail5->SetParent(pictureHolder);
	thumbnail6->SetParent(pictureHolder);
	backgroundImage->SetParent(pictureHolder);

	thumbnail1->SetPosition(-Graphics::SCREEN_WIDTH * 0.8f, -Graphics::SCREEN_HEIGHT * 0.75f);
	thumbnail2->SetPosition(-Graphics::SCREEN_WIDTH * 0.8f, -Graphics::SCREEN_HEIGHT * 0.50f);
	thumbnail3->SetPosition(-Graphics::SCREEN_WIDTH * 0.8f, -Graphics::SCREEN_HEIGHT * 0.25f);
	
	thumbnail4->SetPosition(-Graphics::SCREEN_WIDTH * 0.2f, -Graphics::SCREEN_HEIGHT * 0.75f);
	thumbnail5->SetPosition(-Graphics::SCREEN_WIDTH * 0.2f, -Graphics::SCREEN_HEIGHT * 0.50f);
	thumbnail6->SetPosition(-Graphics::SCREEN_WIDTH * 0.2f, -Graphics::SCREEN_HEIGHT * 0.25f);

	backgroundImage->SetPosition(-Graphics::SCREEN_WIDTH * 0.5f, -Graphics::SCREEN_HEIGHT * 0.5f);

	gameEntityList.push_back(screenLabel);
	gameEntityList.push_back(thumbnail1);
	gameEntityList.push_back(thumbnail2);
	gameEntityList.push_back(thumbnail3);
	gameEntityList.push_back(thumbnail4);
	gameEntityList.push_back(thumbnail5);
	gameEntityList.push_back(thumbnail6);
	gameEntityList.push_back(backgroundImage);
}

PictureSelectScreen::~PictureSelectScreen()
{
	delete topBar;
	topBar = nullptr;
	delete pictureHolder;
	pictureHolder = nullptr;
	/* Steven 
		When deleting an array always cycle from the back to the front i.e i-- instead of i++ 
		The reason for this is due to the potential of removing an element at an index, by adjusting the array you'd run into a "Out of Access" error

		Another thing to note, you keep positions in the memory for each element, 
		so however big GameEntity is you're keeping that * the number of elements,
		Say it was an array of Integers which takes up 4 bytes, if there were 10 elements 
		that would give you 40 bytes of memory used for this empty array until you shutdown your PC at least.

		Should pop_back to remove each elements footprint in memory, otherwise in this very specific case you can call
		"delete[] &gameEntityList;" to remove the entire array at the end of the function.
	
	*/
	for (int i = 0; i < gameEntityList.size(); i++)
	{
		delete gameEntityList[i];
		gameEntityList[i] = nullptr;
	}
}

void PictureSelectScreen::Render()
{
	for (int i = 0; i < gameEntityList.size(); i++)
	{
		gameEntityList[i]->Render();
	}
}

void PictureSelectScreen::Update()
{
	if (input->MouseButtonPressed(input->Left)) {
		if (button->ContainsPoint(thumbnail1, input->MousePosition().x, input->MousePosition().y)) {
			selectedPicture = one;
		}
		else if (button->ContainsPoint(thumbnail2, input->MousePosition().x, input->MousePosition().y)) {
			selectedPicture = two;
		}
		else if (button->ContainsPoint(thumbnail3, input->MousePosition().x, input->MousePosition().y)) {
			selectedPicture = three;
		}
		else if (button->ContainsPoint(thumbnail4, input->MousePosition().x, input->MousePosition().y)) {
			selectedPicture = four;
		}
		else if (button->ContainsPoint(thumbnail5, input->MousePosition().x, input->MousePosition().y)) {
			selectedPicture = five;
		}
		else if (button->ContainsPoint(thumbnail6, input->MousePosition().x, input->MousePosition().y)) {
			selectedPicture = six;
		}
		else {
			selectedPicture = none;
		}
	}
}

PictureSelectScreen::Pictures PictureSelectScreen::GetSelectedPicture()
{
	return selectedPicture;
}
