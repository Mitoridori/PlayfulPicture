//FILE: Timer.h
//PROJECT: PlayfulPictures
//PROGRAMMER: John Gotts
//FIRST VERSION: 02/03/2020
#pragma once
#include <SDL.h>

namespace SDLFramework {

	class Timer {

	private:
		static Timer* instance;
		unsigned int startTick;
		unsigned int elapsedTicks;
		float deltaTime;
		float timeScale;

	public:
		static Timer* Instance();
		static void Release();

		void ResetTimer();
		float GetDeltaTime();
		void SetTimeScale(float scale);
		float GetTimeScale();
		void Update();

	private:
		Timer();
		~Timer();
		float ConvertTicksToSeconds();
	};
}