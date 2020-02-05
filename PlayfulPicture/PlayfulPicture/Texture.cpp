#include "Texture.h"

namespace SDLFramework {

	Texture::Texture()
	{
		tex = nullptr;
		width = 0;
		height = 0;
		graphics = Graphics::Instance();

	}

	Texture::Texture(std::string filename, bool managed) {
		graphics = Graphics::Instance();
		tex = AssetManager::Instance()->GetTexture(filename, managed);

		SDL_QueryTexture(tex, nullptr, nullptr, &width, &height);

		clipped = false;
		destinationRect.w = width;
		destinationRect.h = height;
	}

	Texture::Texture(std::string filename, int x, int y, int w, int h, bool managed) {
		graphics = Graphics::Instance();
		tex = AssetManager::Instance()->GetTexture(filename, managed);

		width = w;
		height = h;

		clipped = true;
		destinationRect.w = width;
		destinationRect.h = height;

		sourceRect.x = x;
		sourceRect.y = y;
		sourceRect.w = width;
		sourceRect.h = height;
	}

	Texture::Texture(std::string text, std::string fontPath, int size, SDL_Color color, bool managed) {
		graphics = Graphics::Instance();
		tex = AssetManager::Instance()->GetText(text, fontPath, size, color, managed);

		clipped = false;

		SDL_QueryTexture(tex, nullptr, nullptr, &width, &height);

		destinationRect.w = width;
		destinationRect.h = height;
	}

	Texture::~Texture() {
		AssetManager::Instance()->DestroyTexture(tex);
		tex = nullptr;
		graphics = nullptr;
	}

	bool Texture::LoadFromImage(std::string filename, Uint8 r, Uint8 g, Uint8 b)
	{

		// Return if the renderer was not set
		if (Graphics::Instance()->GetRenderer() == nullptr)
			return false;

		// Load image to a surface
		SDL_Surface* loadedSurface = SDL_LoadBMP(filename.c_str());
		if (loadedSurface == nullptr) {
			printf("Unable to load image %s! SDL Error: %s\n", filename.c_str(), SDL_GetError());
			return false;
		}

		// Create texture from the surface
		tex = SDL_CreateTextureFromSurface(Graphics::Instance()->GetRenderer(), loadedSurface);
		if (tex == nullptr) {
			printf("Unable to create texture from surface %s! SDL Error: %s\n", filename.c_str(), SDL_GetError());
			return false;
		}

		// Set width and height of the texture
		width = loadedSurface->w;
		height = loadedSurface->h;

		// Free the surface
		SDL_FreeSurface(loadedSurface);

		return true;
	}

	Vector2 Texture::ScaledDimensions() {
		Vector2 scaledDimensions = Scale();
		scaledDimensions.x *= width;
		scaledDimensions.y *= height;

		return scaledDimensions;
	}

	void Texture::Render() {
		Vector2 pos = Position(World);
		Vector2 scale = Scale(World);
		destinationRect.x = (int)(pos.x - width * scale.x * 0.5f);
		destinationRect.y = (int)(pos.y - height * scale.y * 0.5f);
		destinationRect.w = (int)(width * scale.x);
		destinationRect.h = (int)(height * scale.y);

		graphics->DrawTexture(tex, clipped ? &sourceRect : nullptr, &destinationRect, Rotation(World));
	}
}