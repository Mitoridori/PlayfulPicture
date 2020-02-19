#ifndef __TITLESCREEN_H
#define __TITLESCREEN_H
#include "AnimatedTexture.h"
#include "AudioManager.h"
#include "Screens.h"

namespace SDLFramework
{
	class TitleScreen : public Screens
	{
	private:
		AudioManager* audioManager;

		//logo
		Texture* mLogo;
		AnimatedTexture* mAnimatedLogo;

		//push start
		GameEntity* mPushStart;
		Texture* mPushLogo;
		Texture* mPushAnimated;

		//background
		Texture* mBackground;

		// Screen Animation Variables
		Vector2 mAnimationStartPos;
		Vector2 mAnimationEndPos;
		float mAnimationTotalTime;
		float mAnimationTimer;
		bool mAnimationDone;
		float mPushTimer;

		int mSelectedMode;

	public:
		TitleScreen();
		~TitleScreen();

		void ResetAnimation();

		void Update() override;
		void Render() override;
	};
}

#endif