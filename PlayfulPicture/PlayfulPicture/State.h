#pragma once


class Screens;

class State {

public:
	virtual ~State() {}

	virtual void Enter(Screens*) = 0;
	virtual void Render(Screens*) = 0;
	virtual void Update(Screens*) = 0;
	virtual void Exit(Screens*) = 0;

};