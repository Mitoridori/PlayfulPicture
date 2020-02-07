#include "TitleScreen.h"

namespace SDLFramework
{
	TitleScreen::TitleScreen()
	{
		//timer and input
		mTimer = Timer::Instance();
		mInput = InputManager::Instance();

		// logo entities
		mLogo = new Texture("PlayfulPictures logo.png", 0.5, 0.5, 800, 65);
		mLogo->SetParent(this);
		//mLogo->SetScale(Vector2(2, 2));

		mAnimatedLogo = new AnimatedTexture("PlayfulPictures logo.png", 0.5, 0.5, 800, 65, 3, 1.0f, AnimatedTexture::Vertical);
		mAnimatedLogo->SetParent(this);

		mLogo->SetPosition(Graphics::SCREEN_WIDTH * 0.50f, Graphics::SCREEN_HEIGHT * 0.40f);
		mAnimatedLogo->SetPosition(Graphics::SCREEN_WIDTH * 0.50f, Graphics::SCREEN_HEIGHT * 0.40f);
		//mAnimatedLogo->SetScale(Vector2(2, 2));

		//push start
		mPushStart = new GameEntity(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.55f);

		mPushLogo = new Texture("PUSH START","emulogic.ttf", 32, { 0, 0, 0 });
		mPushAnimated = new Texture("PUSH START", "emulogic.ttf", 32, {230, 230, 230 });
		mPushStart->SetParent(this);
		mPushLogo->SetPosition(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.7f);
		mPushAnimated->SetPosition(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.7f);
		mPushLogo->SetParent(mPushStart);
		mPushAnimated->SetParent(mPushStart);

		//background 
		mBackground = new Texture("background2.png", 0, 0, 1100, 900);
		mBackground->SetParent(this);
		mBackground->SetPosition(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.5f);
		//mBackground->SetScale(Vector2(2.9648f, 2.9648f));

		// screen animation variables
		mAnimationStartPos = Vector2(0.0f, Graphics::SCREEN_HEIGHT);
		mAnimationEndPos = Vec2_Zero;
		mAnimationTotalTime = 5.0f;
		mAnimationTimer = 0.0f;
		mAnimationDone = false;

		ResetAnimation();
	}

	TitleScreen::~TitleScreen()
	{
		mTimer = nullptr;
		mInput = nullptr;

		delete mLogo;
		mLogo = nullptr;

		delete mAnimatedLogo;
		mAnimatedLogo = nullptr;

		delete mPushStart;
		mPushStart = nullptr;

		delete mPushLogo;
		mPushLogo = nullptr;

		delete mBackground;
		mBackground = nullptr;

	}

	void TitleScreen::ResetAnimation()
	{
		mAnimationStartPos = Vector2(0.0f, Graphics::SCREEN_HEIGHT);
		mAnimationEndPos = Vec2_Zero;
		mAnimationTotalTime = 5.0f;
		mAnimationTimer = 0.0f;
		mAnimationDone = false;

		Position(mAnimationStartPos);
	}

	void TitleScreen::ChangeSelectedMode(int change)
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

	void TitleScreen::Update()
	{
		if (!mAnimationDone) {
			mAnimationTimer += mTimer->GetDeltaTime();
			Position(Lerp(mAnimationStartPos, mAnimationEndPos, mAnimationTimer / mAnimationTotalTime));

			if (mAnimationTimer >= mAnimationTotalTime) {
				mAnimationDone = true;
			}

			//if (mInput->KeyPressed(SDL_SCANCODE_SPACE)) {
			//	mAnimationTimer = mAnimationTotalTime;
			//}
		}
		else {
			mAnimatedLogo->Update();
			//if (mInput->KeyPressed(SDL_SCANCODE_RETURN))
			//{
			//	ChangeSelectedMode(1);
			//}

		}

	}

	void TitleScreen::Render()
	{
		mBackground->Render();
		mPushLogo->Render();

		if (!mAnimationDone)
		{
			mLogo->Render();
		}
		else if (mAnimationDone)
		{
			mPushTimer += 1;
			mAnimatedLogo->Render();
			if (mPushTimer >= 20 && mPushTimer <= 40)
			{
				mPushAnimated->Render();
				if (mPushTimer >= 40)
				{
					mPushTimer = 0;
				}
			}
		}
	}
}
