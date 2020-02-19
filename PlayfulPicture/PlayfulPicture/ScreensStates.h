#pragma once

#include "State.h"


class Screens;

class TitleScreenState : public State {

private:
	TitleScreenState() {}

	TitleScreenState& operator=(const TitleScreenState&);

public:
	static TitleScreenState* Instance();

	virtual void Enter(Screens* screen);
	virtual void Render(Screens* screen);
	virtual void Update(Screens* screen);
	virtual void Exit(Screens* screen);
};

class MainMenuState : public State {

private:
	MainMenuState() {}

	MainMenuState& operator=(const MainMenuState&);

public:
	static MainMenuState* Instance();

	virtual void Enter(Screens* screen);
	virtual void Render(Screens* screen);
	virtual void Update(Screens* screen);
	virtual void Exit(Screens* screen);
};