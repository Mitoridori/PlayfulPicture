#ifndef __ASSETMANAGER_H
#define __ASSETMANAGER_H

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <iostream>
#include <string>
#include <map>
#include <unordered_map>
#include <sstream>
#include "Graphics.h"

namespace SDLFramework {

	class AssetManager {

	private:
		static AssetManager* sInstance;

		std::map<std::string, SDL_Texture*> textures;
		std::map<std::string, TTF_Font*> fonts;
		std::map<std::string, SDL_Texture*> textureText;
		std::map<std::string, Mix_Music*> mixMusic;
		std::map<std::string, Mix_Chunk*> SFX;

		std::map<SDL_Texture*, unsigned> textureRefCount;
		std::map<Mix_Music*, unsigned> musicRefCount;
		std::map<Mix_Chunk*, unsigned*> SFXRefCount;

		TTF_Font* GetFont(std::string filename, int size);

		AssetManager();

	public:
		static AssetManager* Instance();
		static void Release();

		SDL_Texture* GetTexture(std::string filename, bool managed = false);
		SDL_Texture* GetText(std::string text, std::string filename, int size, SDL_Color color, bool managed = false);

		Mix_Music* GetMusic(std::string filename, bool managed = false);
		Mix_Chunk* GetSFX(std::string filename, bool managed = false);

		void DestroyTexture(SDL_Texture* texture);

		void DestroyMusic(Mix_Music* music);
		void DestroySFX(Mix_Chunk* sfx);
		~AssetManager();
	};
}
#endif

