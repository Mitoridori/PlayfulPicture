#include "AssetManager.h"

namespace SDLFramework
{

	AssetManager* AssetManager::sInstance = nullptr;

	AssetManager* AssetManager::Instance()
	{

		if (sInstance == nullptr)
		{
			sInstance = new AssetManager();
		}
		return sInstance;
	}

	void AssetManager::Release()
	{
		delete sInstance;
		sInstance = nullptr;

	}

	AssetManager::AssetManager() {

	}

	//FUNCTION : GetTexture
	//DESCRIPTION : Getting the texture information.
	//PARAMETERS : string filename, bool managed
	//RETURNS : none
	SDL_Texture* AssetManager::GetTexture(std::string filename, bool managed)
	{
		std::string fullPath = SDL_GetBasePath();

		fullPath.append("Assets/" + filename);

		if (textures[fullPath] == nullptr)
		{
			textures[fullPath] = Graphics::Instance()->SetTexture(fullPath);
		}

		if (textures[fullPath] != nullptr && managed)
		{
			textureRefCount[textures[fullPath]] += 1;
		}

		return textures[fullPath];
	}


	//FUNCTION : GetFont
	//DESCRIPTION : gets the fonts
	//PARAMETERS : string filename, int size
	//RETURNS : none
	TTF_Font* AssetManager::GetFont(std::string filename, int size)
	{
		std::string fullPath = SDL_GetBasePath();
		fullPath.append("Assets/" + filename);

		std::stringstream ss;
		ss << size;
		std::string key = fullPath + ss.str();

		if (fonts[key] == nullptr)
		{
			fonts[key] = TTF_OpenFont(fullPath.c_str(), size);

			if (fonts[key] == nullptr)
			{
				std::cerr << "Unable to load font " << filename << "! TTF Error: " << TTF_GetError() << std::endl;
			}
		}

		return fonts[key];
	}


	//FUNCTION : GetText
	//DESCRIPTION : getting test
	//PARAMETERS : string text, std::string filename, int size, SDL_Color color, bool managed
	//RETURNS : none
	SDL_Texture* AssetManager::GetText(std::string text, std::string filename, int size, SDL_Color color, bool managed)
	{
		std::stringstream ss;
		ss << size << (int)color.r << (int)color.g << (int)color.b;
		std::string key = text + filename + ss.str();

		if (textureText[key] == nullptr)
		{
			TTF_Font* font = GetFont(filename, size);
			textureText[key] = Graphics::Instance()->SetTextTexture(font, text, color);
		}

		if (textureText[key] != nullptr && managed)
		{
			textureRefCount[textureText[key]] += 1;
		}

		return textureText[key];
	}

	//FUNCTION : GetMusic
	//DESCRIPTION : getting the music asset
	//PARAMETERS : string filename, bool managed
	//RETURNS : none
	Mix_Music* AssetManager::GetMusic(std::string filename, bool managed)
	{
		std::string fullPath = SDL_GetBasePath();
		fullPath.append("Assets/" + filename);

		if (mixMusic[fullPath] == nullptr)
		{
			mixMusic[fullPath] = Mix_LoadMUS(fullPath.c_str());
		}

		if (mixMusic[fullPath] == nullptr)
		{
			std::cerr << "Unable to load music " << filename << "! Mix error: " << Mix_GetError() << std::endl;
		}
		else if (managed)
		{
			musicRefCount[mixMusic[fullPath]] += 1;
		}

		return mixMusic[fullPath];
	}

	//FUNCTION : GetSFX
	//DESCRIPTION : getting the sound effects
	//PARAMETERS : string filename, bool managed
	//RETURNS : none
	Mix_Chunk* AssetManager::GetSFX(std::string filename, bool managed)
	{
		std::string fullPath = SDL_GetBasePath();
		fullPath.append("Assets/" + filename);

		if (SFX[fullPath] == nullptr)
		{
			SFX[fullPath] = Mix_LoadWAV(fullPath.c_str());
		}
		if (SFX[fullPath] == nullptr)
		{
			std::cerr << "Unable to load SFX " << filename << "! Mix error: " << Mix_GetError() << std::endl;
		}
		else if (managed)
		{
			SFXRefCount[SFX[fullPath]] += 1;
		}

		return SFX[fullPath];
	}


	AssetManager::~AssetManager()
	{
		for (auto tex : textures)
		{
			if (tex.second != nullptr)
			{
				SDL_DestroyTexture(tex.second);
			}
		}

		textures.clear();
	}

	void AssetManager::DestroyTexture(SDL_Texture* texture)
	{
		if (textureRefCount.find(texture) != textureRefCount.end())
		{
			textureRefCount[texture] -= 1;

			if (textureRefCount[texture] == 0)
			{
				for (auto elem : textures)
				{
					if (elem.second == texture)
					{
						SDL_DestroyTexture(elem.second);
						textures.erase(elem.first);
						return; // work finished, leave function
					}
				}

				for (auto elem : textureText)
				{
					if (elem.second == texture)
					{
						SDL_DestroyTexture(elem.second);
						textureText.erase(elem.first);
						return; // work finished, leave function
					}
				}
			}
		}
	}

	void AssetManager::DestroyMusic(Mix_Music* music)
	{
		for (auto elem : mixMusic)
		{
			if (elem.second == music)
			{
				musicRefCount[elem.second] -= 1;

				if (musicRefCount[elem.second] == 0)
				{
					Mix_FreeMusic(elem.second);
					mixMusic.erase(elem.first);
				}
				return; // work finished, leave function
			}
		}
	}

	void AssetManager::DestroySFX(Mix_Chunk* sfx)
	{
		for (auto elem : SFX)
		{
			if (elem.second == sfx) {

				SFXRefCount[elem.second] -= 1;

				if (SFXRefCount[elem.second] == 0)
				{
					Mix_FreeChunk(elem.second);
					SFX.erase(elem.first);
				}

				return; // work finished, leave function
			}
		}
	}
}