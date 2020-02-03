//FILE: Timer.cpp
//PROJECT: PlayfulPictures
//PROGRAMMER: John Gotts
//FIRST VERSION: 02/03/2020
#include "Timer.h"


namespace SDLFramework {

	Timer* Timer::instance = nullptr;

	//Function: Timer
	//DESCRIPTION: timer constructor
	//PARAMETERS: None
	//RETURNS: None
	Timer::Timer()
	{
		ResetTimer();
		timeScale = 1.0f;
	}

	//Function: ~Timer
	//DESCRIPTION: timer deconstructor
	//PARAMETERS: None
	//RETURNS: None
	Timer::~Timer()
	{

	}

	//Function: ConvertTicksToSeconds
	//DESCRIPTION: function used to convert the elapsed ticks to seconds
	//PARAMETERS: None
	//RETURNS: elapsedTicks * 0.001f
	float Timer::ConvertTicksToSeconds()
	{
		return elapsedTicks * 0.001f;
	}

	//Function: Instance
	//DESCRIPTION: setting the instance singleton for the timer
	//PARAMETERS: None
	//RETURNS: instance
	Timer* Timer::Instance()
	{
		if (instance == nullptr) {
			instance = new Timer();
		}
		return instance;
	}

	//Function: Release
	//DESCRIPTION: used to clear the instance
	//PARAMETERS: None
	//RETURNS: None
	void Timer::Release()
	{
		delete instance;
		instance = nullptr;
	}

	//Function: ResetTimer
	//DESCRIPTION: function used to reset the timer tick variables and delta time
	//PARAMETERS: None
	//RETURNS: None
	void Timer::ResetTimer()
	{
		startTick = SDL_GetTicks();
		elapsedTicks = 0;
		deltaTime = 0.0f;
	}

	//Function: GetDeltaTime
	//DESCRIPTION: function used to get the current delta time
	//PARAMETERS: None
	//RETURNS: float deltaTime
	float Timer::GetDeltaTime()
	{
		return deltaTime;
	}

	//Function: SetTimeScale
	//DESCRIPTION: function used to set the timeScale variable
	//PARAMETERS: float scale
	//RETURNS: None
	void Timer::SetTimeScale(float scale)
	{
		timeScale = scale;
	}

	//Function: GetTimeScale
	//DESCRIPTION: function used to get the timeScale
	//PARAMETERS: None
	//RETURNS: float timeScale
	float Timer::GetTimeScale()
	{
		return timeScale;
	}

	//Function: Update
	//DESCRIPTION: function used to update the timer
	//PARAMETERS: None
	//RETURNS: None
	void Timer::Update()
	{
		elapsedTicks = SDL_GetTicks() - startTick;
		deltaTime = ConvertTicksToSeconds();
	}
}