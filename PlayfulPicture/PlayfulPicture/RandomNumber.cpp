#include "RandomNumber.h"

namespace SDLFramework
{

	RandomNumber* RandomNumber::sInstance = nullptr;
	int Random::mRandomPieceCurrent = 0;
	int Random::mRandomPieceNext = 0;

	Random* Random::Instance()
	{
		sInstance = new Random();
		return sInstance;
	}

	void Random::Release()
	{
		delete sInstance;
		sInstance = nullptr;
	}

	int Random::GetNextPiece()
	{
		//SetNextPiece();
		return mRandomPieceNext;
	}

	void Random::SetNextPiece()
	{
		mRandomPieceNext = ((rand() * 100) % 7);
	}

	int Random::GetCurrentPiece()
	{
		//SetCurrentPiece();
		return mRandomPieceCurrent;
	}

	void Random::SetCurrentPiece()
	{
		mRandomPieceCurrent = mRandomPieceNext;
	}

	Random::Random()
	{
		srand((unsigned)time(0));
	}

	Random::~Random()
	{
		Release();
	}
}