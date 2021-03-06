#include "TitleScreen.h"
#include "ScreensStates.h"

namespace SDLFramework
{
	TitleScreen::TitleScreen() : Screens()
	{
		audioManager = AudioManager::Instance();

		// logo entities
		mLogo = new Texture("PlayfulPictures logo.png", 0, 0, 440, 150);
		mLogo->SetParent(this);

		mAnimatedLogo = new AnimatedTexture("PlayfulPictures logo.png", 0, 0, 440, 150, 3, 0.9f, AnimatedTexture::Horizontal);
		mAnimatedLogo->SetParent(this);

		mLogo->SetPosition(Graphics::SCREEN_WIDTH * 0.50f, Graphics::SCREEN_HEIGHT * 0.40f);
		mAnimatedLogo->SetPosition(Graphics::SCREEN_WIDTH * 0.50f, Graphics::SCREEN_HEIGHT * 0.40f);
		//mAnimatedLogo->SetScale(Vector2(2, 2));

		//push start
		mPushStart = new GameEntity(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.55f);

		mPushLogo = new Texture("PUSH START","emulogic.ttf", 32, { 230, 230, 230 });
		mPushAnimated = new Texture("PUSH START", "emulogic.ttf", 32, {230, 0, 150});
		mPushStart->SetParent(this);
		mPushLogo->SetPosition(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.5f);
		mPushAnimated->SetPosition(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.5f);
		mPushLogo->SetParent(mPushStart);
		mPushAnimated->SetParent(mPushStart);

		//background 
		mBackground = new Texture("Background.png", 0, 0, 1100, 900);
		mBackground->SetParent(this);
		mBackground->SetPosition(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.5f);
		//mBackground->SetScale(Vector2(2.9648f, 2.9648f));

		// screen animation variables
		/*mAnimationStartPos = Vector2(0.0f, Graphics::SCREEN_HEIGHT);
		mAnimationEndPos = Vec2_Zero;
		mAnimationTotalTime = 5.0f;
		mAnimationTimer = 0.0f;
		mAnimationDone = false;*/
		audioManager->PlayMusic("Music/Intoleranzen.mp3", -1);

		//ResetAnimation();*/
	}

	TitleScreen::~TitleScreen()
	{

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

	void TitleScreen::Update()
	{
		if (!mAnimationDone) {
			mAnimationTimer += timer->GetDeltaTime();
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
			if (input->MouseButtonPressed(input->Left)) {
				//ChangeScreenState(MainMenuState::Instance());
			}

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
