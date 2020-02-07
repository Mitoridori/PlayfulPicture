//FILE: PictureSelectScreen.cpp
//PROJECT: PlayfulPictures
//PROGRAMMER: John Gotts
//FIRST VERSION: 02/06/2020
#include "PictureSelectScreen.h"

PictureSelectScreen::Pictures PictureSelectScreen::selectedPicture = none;
PictureSelectScreen::PictureSelectScreen()
{
	input = InputManager::Instance();
	button = new Buttons();

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
}

PictureSelectScreen::~PictureSelectScreen()
{
	delete topBar;
	topBar = nullptr;
	delete screenLabel;
	screenLabel = nullptr;

	delete pictureHolder;
	pictureHolder = nullptr;

	delete thumbnail1;
	thumbnail1 = nullptr;
	delete thumbnail2;
	thumbnail2 = nullptr;
	delete thumbnail3;
	thumbnail3 = nullptr;
	delete thumbnail4;
	thumbnail4 = nullptr;
	delete thumbnail5;
	thumbnail5 = nullptr;
	delete thumbnail6;
	thumbnail6 = nullptr;
	delete backgroundImage;
	backgroundImage = nullptr;

	delete button;
	button = nullptr;
}

void PictureSelectScreen::Render()
{
	backgroundImage->Render();
	screenLabel->Render();
	thumbnail1->Render();
	thumbnail2->Render();
	thumbnail3->Render();
	thumbnail4->Render();;
	thumbnail5->Render();
	thumbnail6->Render();
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
