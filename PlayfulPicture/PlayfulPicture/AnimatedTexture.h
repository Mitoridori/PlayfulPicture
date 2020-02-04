#ifndef __ANIMATEDTEXTURE_H
#define __ANIMATEDTEXTURE_H
#include "Texture.h"
#include "Timer.h"

namespace SDLFramework {

	class AnimatedTexture :
		public Texture
	{
	public:
		enum WrapMode { Once = 0, Loop = 1 };
		enum AnimDir { Horizontal = 0, Vertical = 1 };

	protected:
		Timer* timer;
		int startX;
		int startY;

		int frameCount; // total frames

		float animationSpeed = 1; // in seconds
		float timePerFrame; // time to display
		float animationTimer; // time displayed

		WrapMode wrapMode;
		AnimDir animationDirection;

		bool animationFinished;

		virtual void RunAnimation();

	public:
		AnimatedTexture(std::string filename, int x, int y, int w, int h, int frameCount, float animationSpeed, AnimDir animationDir, bool managed = false);
		~AnimatedTexture();

		void SetWrapMode(WrapMode mode);

		virtual void ResetAnimation();
		bool IsDying();

		void Update();
	};
}
#endif

