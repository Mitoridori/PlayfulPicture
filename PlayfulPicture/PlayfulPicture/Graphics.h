#ifndef __GRAPHICS_H 
#define __GRAPHICS_H 
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <SDL_ttf.h>

namespace SDLFramework {

	//NAME: Graphics
	//PURPOSE: class used to set up the display window of the game for all visuals
	class Graphics {

	public:
		static const short SCREEN_WIDTH = 1024;
		static const short SCREEN_HEIGHT = 896;
		const char* WINDOW_TITLE = "Playful Picture";

	private:
		static Graphics* instance;
		static bool didInit;
		SDL_Window* window;
		SDL_Renderer* renderer;

	public:
		static Graphics* Instance();
		static void Release();
		static bool GetDidInit();

		SDL_Renderer* GetRenderer();

		void ClearRenderer();
		void Render();
		void DrawTexture(SDL_Texture* tex, SDL_Rect* srcRect = nullptr, SDL_Rect* dstRect = nullptr, float angle = 0.0f, SDL_RendererFlip flip = SDL_FLIP_NONE);
		SDL_Texture* SetTextTexture(TTF_Font* font, std::string text, SDL_Color color);
		SDL_Texture* SetTexture(std::string path);

	private:
		Graphics();
		~Graphics();
		bool Init();
	};

}
#endif
