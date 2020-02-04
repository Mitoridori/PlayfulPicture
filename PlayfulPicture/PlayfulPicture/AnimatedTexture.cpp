#include "AnimatedTexture.h"

namespace SDLFramework {

	//FUNCTION : RunAnimation
	//DESCRIPTION : making the animation run
	//PARAMETERS : none
	//RETURNS : none
	void AnimatedTexture::RunAnimation() {
		if (!animationFinished) {
			animationTimer += timer->GetDeltaTime();

			if (animationTimer >= animationSpeed) {
				if (wrapMode == Loop) {
					// reset timer, accounting for extra time
					animationTimer -= animationSpeed;
				}
				else {
					animationFinished = true;
					// back up the timer to the last frame
					animationTimer = animationSpeed - timePerFrame;
				}
			}

			if (animationDirection == Horizontal) {
				sourceRect.x = startX + (int)(animationTimer / timePerFrame) * width;
			}
			else {
				sourceRect.y = startY + (int)(animationTimer / timePerFrame) * height;
			}
		}
	}

	AnimatedTexture::AnimatedTexture(std::string filename, int x, int y, int w, int h, int frameCount, float animationSpeed, AnimDir animationDir, bool managed)
		: Texture(filename, x, y, w, h, managed) {
		timer = Timer::Instance();

		startX = x;
		startY = y;

		frameCount = frameCount;
		animationSpeed = animationSpeed;
		timePerFrame = animationSpeed / frameCount;
		animationTimer = 0.0f;

		wrapMode = Loop;
		animationDirection = animationDir;

		animationFinished = false;
	}

	AnimatedTexture::~AnimatedTexture() { }

	void AnimatedTexture::SetWrapMode(WrapMode wrapMode) {
		wrapMode = wrapMode;
	}

	void AnimatedTexture::ResetAnimation() {
		animationTimer = 0.0f;
		animationFinished = false;
	}

	bool AnimatedTexture::IsDying() {
		return !animationFinished;
	}

	void AnimatedTexture::Update() {
		RunAnimation();
	}
}