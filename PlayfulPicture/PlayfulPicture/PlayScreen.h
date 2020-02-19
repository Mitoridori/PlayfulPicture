#pragma once
#include "Texture.h"
#include "Board.h"
#include "InGameUI.h"
#include "Screens.h"
#include <vector>

namespace SDLFramework {

	class PlayScreen : public Screens {

	private:
		static int totalMoves;

		InGameUI* playerUI;

		Board* board;

		bool haveCreatedBoard = false;

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