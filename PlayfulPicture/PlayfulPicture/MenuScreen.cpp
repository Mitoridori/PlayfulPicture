#include "MenuScreen.h"

namespace SDLFramework
{
	MenuScreen* MenuScreen::sInstance = nullptr;

	MenuScreen::MenuScreen()
	{
		//timer and input
		mTimer = Timer::Instance();
		mInput = InputManager::Instance();
		mAudio = AudioManager::Instance();
		mTypeManager = TypeManager::GetInstance();

		//Arrows
		mArrowTypeL = new Texture("TitleSheet.png", 255, 72, 10, 10);
		mArrowTypeL->SetParent(this);
		mArrowTypeL->SetScale(Vector2(2.9648f, 2.9648f));
		mArrowTypeL->SetPosition(Graphics::SCREEN_WIDTH * 0.25f, Graphics::SCREEN_HEIGHT * 0.255f);

		mArrowTypeR = new Texture("TitleSheet.png", 264, 72, 10, 10);
		mArrowTypeR->SetParent(this);
		mArrowTypeR->SetScale(Vector2(2.9648f, 2.9648f));
		mArrowTypeR->SetPosition(Graphics::SCREEN_WIDTH * 0.475f, Graphics::SCREEN_HEIGHT * 0.255f);

		mArrowMusicL = new Texture("TitleSheet.png", 255, 72, 10, 10);
		mArrowMusicL->SetParent(this);
		mArrowMusicL->SetScale(Vector2(2.9648f, 2.9648f));
		mArrowMusicL->SetPosition(Graphics::SCREEN_WIDTH * 0.41f, Graphics::SCREEN_HEIGHT * 0.61f);

		mArrowMusicR = new Texture("TitleSheet.png", 264, 72, 10, 10);
		mArrowMusicR->SetParent(this);
		mArrowMusicR->SetScale(Vector2(2.9648f, 2.9648f));
		mArrowMusicR->SetPosition(Graphics::SCREEN_WIDTH * 0.695f, Graphics::SCREEN_HEIGHT * 0.61f);

		//background 
		mBackground = new Texture("Tetris_MenuSheet.png", 0, 0, 255, 240);
		mBackground->SetParent(this);
		mBackground->SetScale(Vector2(2.9648f, 2.9648f));
		mBackground->SetPosition(Graphics::SCREEN_WIDTH * 0.174f, Graphics::SCREEN_HEIGHT * 0.174f);

	}

	MenuScreen::~MenuScreen()
	{
		mTimer = nullptr;
		mInput = nullptr;

		delete mArrowTypeL;
		mArrowTypeL = nullptr;

		delete mArrowTypeR;
		mArrowTypeR = nullptr;

		delete mArrowMusicL;
		mArrowMusicL = nullptr;

		delete mArrowMusicR;
		mArrowMusicR = nullptr;

		delete mBackground;
		mBackground = nullptr;

		delete sInstance;
		sInstance = nullptr;

		mTypeManager = nullptr;

	}

	MenuScreen* MenuScreen::Instance()
	{
		if (sInstance == nullptr)
		{
			sInstance = new MenuScreen();
		}
		return sInstance;
	}

	void MenuScreen::ResetAnimation()
	{
		mAnimationStartPos = Vector2(0.0f, Graphics::SCREEN_HEIGHT);
		mAnimationEndPos = Vec2_Zero;
		mAnimationTotalTime = 5.0f;
		mAnimationTimer = 0.0f;
		mAnimationDone = false;

		SetPosition(mAnimationStartPos);
	}

	void MenuScreen::ChangeSelectedMode(int change)
	{

		mSelectedMode += change;

		if (mSelectedMode < 0)
		{
			mSelectedMode = 1;
		}

		else if (mSelectedMode > 1)
		{
			mSelectedMode = 0;
		}
	}
	
	void MenuScreen::Update()
	{
		if (mInput->KeyPressed(SDL_SCANCODE_RIGHT))
		{
			mTypeManager->SetGameType(true);
			mArrowTypeL->SetPosition(Graphics::SCREEN_WIDTH * 0.625f, Graphics::SCREEN_HEIGHT * 0.255f);
			mArrowTypeR->SetPosition(Graphics::SCREEN_WIDTH * 0.85f, Graphics::SCREEN_HEIGHT * 0.255f);
			mAudio->PlaySFX("SFX/MenuMovement.wav", 0, 1);
			mSelectedMode = 1;
		}
		else if (mInput->KeyPressed(SDL_SCANCODE_LEFT))
		{
			mTypeManager->SetGameType(false);
			mArrowTypeL->SetPosition(Graphics::SCREEN_WIDTH * 0.25f, Graphics::SCREEN_HEIGHT * 0.255f);
			mArrowTypeR->SetPosition(Graphics::SCREEN_WIDTH * 0.475f, Graphics::SCREEN_HEIGHT * 0.255f);
			mAudio->PlaySFX("SFX/MenuMovement.wav", 0, 1);
			mSelectedMode = 0;
		}

		if (mAudio->CurrentMusic < 4 && mInput->KeyPressed(SDL_SCANCODE_DOWN))
		{
			mArrowMusicL->Translate(Vector2(0.0f, +49));
			mArrowMusicR->Translate(Vector2(0.0f, +49));
			mAudio->CurrentMusic = mAudio->CurrentMusic + 1;
			mAudio->Playing = false;
			mAudio->PlaySFX("SFX/MenuMovement.wav", 0, 1);
		}
		else if (mAudio->CurrentMusic > 1 && mInput->KeyPressed(SDL_SCANCODE_UP))
		{
			mArrowMusicL->Translate(Vector2(0.0f, -49));
			mArrowMusicR->Translate(Vector2(0.0f, -49));
			mAudio->CurrentMusic = mAudio->CurrentMusic - 1;
			mAudio->Playing = false;
			mAudio->PlaySFX("SFX/MenuMovement.wav", 0, 1);
		}
	}

	void MenuScreen::Render()
	{
		mBackground->Render();
		mArrowTypeL->Render();
		mArrowTypeR->Render();
		mArrowMusicL->Render();
		mArrowMusicR->Render();
	}
}
