#ifndef __RANDOM_H
#define __RANDOM_H
#include <cstdlib>
#include <ctime>
#include <iostream>

namespace SDLFramework {

	class RandomNumber {
	private:

		RandomNumber();
		~RandomNumber();

		static int mRandomPieceCurrent;
		static int mRandomPieceNext;

		static RandomNumber* sInstance;

	public:
		static RandomNumber* Instance();
		static void Release();

		int GetNextPiece();
		void SetNextPiece();
		int GetCurrentPiece();

		void SetCurrentPiece();

	};
}
#endif