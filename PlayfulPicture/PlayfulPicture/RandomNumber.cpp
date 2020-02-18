#include "RandomNumber.h"

namespace SDLFramework
{

	RandomNumber* RandomNumber::sInstance = nullptr;
	int RandomNumber::mRandomPieceCurrent = 0;
	int RandomNumber::mRandomPieceNext = 0;

	RandomNumber* RandomNumber::Instance()
	{
		sInstance = new RandomNumber();
		return sInstance;
	}

	void RandomNumber::Release()
	{
		delete sInstance;
		sInstance = nullptr;
	}

	int RandomNumber::GetNextPiece()
	{
		//SetNextPiece();
		return mRandomPieceNext;
	}

	void RandomNumber::SetNextPiece()
	{
		mRandomPieceNext = ((rand() * 100) % 7);
	}

	int RandomNumber::GetCurrentPiece()
	{
		//SetCurrentPiece();
		return mRandomPieceCurrent;
	}

	void RandomNumber::SetCurrentPiece()
	{
		mRandomPieceCurrent = mRandomPieceNext;
	}

	RandomNumber::RandomNumber()
	{
		srand((unsigned)time(0));
	}

	RandomNumber::~RandomNumber()
	{
		Release();
	}


	int RandomNumber::RandomTiles(int NumTiles)
	{

		std::random_device rd;
		std::mt19937 rng(rd());
		std::uniform_int_distribution<int> tilerange(0, NumTiles - 1); // don't scramble last ('empty') tile
		int n = tilerange(rng);
		return n;
	}
}