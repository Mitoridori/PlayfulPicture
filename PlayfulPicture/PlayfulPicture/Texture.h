#ifndef __TEXTURE_H
#define __TEXTURE_H
#include "Graphics.h"
#include "GameEntity.h"
#include "AssetManager.h"

namespace SDLFramework {

	class Texture : public GameEntity {
	protected:
		SDL_Texture* tex;
		Graphics* graphics;
		AssetManager* assetManager;

		int width;
		int height;

		bool clipped;
		SDL_Rect sourceRect;
		SDL_Rect destinationRect;

	public:
		Texture();
		Texture(std::string filename, bool managed = true);
		Texture(std::string filename, int x, int y, int w, int h, bool managed = false);
		Texture(std::string text, std::string fontPath, int size, SDL_Color color, bool managed = false);
		~Texture();

		bool LoadFromImage(std::string path, Uint8 r = 0, Uint8 g = 0, Uint8 b = 0);

		Vector2 ScaledDimensions();

		int GetWidth();
		int GetHeight();

		void Render() override;
	};
}
#endif

