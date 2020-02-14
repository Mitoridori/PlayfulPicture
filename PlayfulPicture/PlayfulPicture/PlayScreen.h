#pragma once
#include "Timer.h"
#include "Texture.h"
#include "InputManager.h"
#include "Board.h"
#include "InGameUI.h"
#include <vector>

namespace SDLFramework {
	class PlayScreen : public GameEntity {

	private:
		static int totalMoves;
		Timer* timer;
		InputManager* input;

		InGameUI* playerUI;

		Board* board;

		bool haveCreatedBoard = false;

		std::vector<GameEntity*> gameEntityList;

	public:
		PlayScreen();
		~PlayScreen();

		InGameUI* GetPlayerUI();

		void Update() override;
		void Render() override;

		static int GetTotalMoves();
		static void IncrementTotalMoves(int amount);

	};
}