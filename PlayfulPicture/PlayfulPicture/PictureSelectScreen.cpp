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

	gameEntityList.push_back(backgroundImage);
	gameEntityList.push_back(screenLabel);
	gameEntityList.push_back(thumbnail1);
	gameEntityList.push_back(thumbnail2);
	gameEntityList.push_back(thumbnail3);
	gameEntityList.push_back(thumbnail4);
	gameEntityList.push_back(thumbnail5);
	gameEntityList.push_back(thumbnail6);
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
	for (int i = gameEntityList.size(); i >= 0; i--)
	{
		delete gameEntityList[i];
		gameEntityList[i] = nullptr;
	}
	delete[] & gameEntityList;
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

	/* Steven

		Here we are calling MousePosition a lot, each call is a new invoke which costs time. perhaps re-organizing our check would be more optimal. we know our game is
		divided into a grid, perhaps we can store the mouse Position and depending on which section or spatial coordinate we could activate a specific button on click. this
		would remove the long if/else statement. which is also not modular. what happens if I wanted 1000 thumbnails...

		Another method you can choose to implement is to have an multi-dimensional array, which would house each button in their correct position, depending
		where the player clicks we could activate that button in the array.
	
		however the best approach would be to use a binary search, which could search for the closest position to our mouse x and y position, which would be a super amazing optimization especially if we added
		a 1,000,000 thumbnails, current implementation would stall if I selected the last one. you'll need to add these to a vector or array that is organized.
	*/

	/*John Gotts:
		cut down on amount of invokes for the mouse position, now only does the 2 to find the x and y position, uses the vector for the texture now as well, still O(n), 
		but with far less invokes now, loop only runs one time per click*/
	if (input->MouseButtonPressed(input->Left)) {
		for (int i = 2; i < gameEntityList.size(); i++)
		{
			switch (button->ContainsPoint((Texture*)gameEntityList[i], input->MousePosition().x, input->MousePosition().y))
			{
			case true:
				if (gameEntityList[i] == thumbnail1) {
					selectedPicture = one;
				}
				else if (gameEntityList[i] == thumbnail2) {
					selectedPicture = two;
				}
				else if (gameEntityList[i] == thumbnail3) {
					selectedPicture = three;
				}
				else if (gameEntityList[i] == thumbnail4) {
					selectedPicture = four;
				}
				else if (gameEntityList[i] == thumbnail5) {
					selectedPicture = five;
				}
				else if (gameEntityList[i] == thumbnail6) {
					selectedPicture = six;
				}
				break;
			default:
				break;
			}
		}
	}
}

PictureSelectScreen::Pictures PictureSelectScreen::GetSelectedPicture()
{
	return selectedPicture;
}
