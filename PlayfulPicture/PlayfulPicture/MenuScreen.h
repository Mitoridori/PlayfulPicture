#ifndef __MENUSCREEN_H
#define __MENUSCREEN_H
#include "AnimatedTexture.h"
#include "InputManager.h"
#include "AudioManager.h"
#include "GameScreen.h"
#include "TypeManager.h"

namespace SDLFramework
{
	class MenuScreen : public GameEntity
	{
	private:
		//timer and input
		Timer* mTimer;
		InputManager* mInput;
		AudioManager* mAudio;
		TypeManager* mTypeManager;

		//Arrows
		Texture* mArrowTypeL;
		Texture* mArrowTypeR;
		Texture* mArrowMusicL;
		Texture* mArrowMusicR;

		static MenuScreen* sInstance;

		//background
		Texture* mBackground;

		//Screen Animation Variables
		Vector2 mAnimationStartPos;
		Vector2 mAnimationEndPos;
		float mAnimationTotalTime;
		float mAnimationTimer;
		bool mAnimationDone;

	public:
		MenuScreen();
		~MenuScreen();

		static MenuScreen* Instance();

		bool mGameType;

		void ChangeSelectedMode(int change);
		void ResetAnimation();

		void Update() override;
		void Render() override;

		//Options	
		int mSelectedMode = 0;	//0 Type A, 1 Type B
	};
}

#endif