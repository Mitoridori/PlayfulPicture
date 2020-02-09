#include "Graphics.h"

namespace SDLFramework {

	Graphics* Graphics::instance = nullptr;
	bool Graphics::didInit = false;

	//Function: Graphics
	//DESCRIPTION: constructor used to init class, runs based on if the renderer already exists or not
	//PARAMETERS: None
	//RETURNS: None
	Graphics::Graphics() : renderer(nullptr)
	{
		didInit = Init();
	}

	//Function:~Graphics
	//DESCRIPTION: deconstructor, used to destroy the window when closed
	//PARAMETERS: None
	//RETURNS: None
	Graphics::~Graphics()
	{
		SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(window);
	}

	//Function: Instance
	//DESCRIPTION: singleton, used to create the instance of this class if none exist
	//PARAMETERS: None
	//RETURNS: instance
	Graphics* Graphics::Instance()
	{
		if (instance == nullptr) {
			instance = new Graphics();
		}
		return instance;
	}

	//Function: Init
	//DESCRIPTION: function used to initialize the window and renderer, does not run if a component does not init
	//PARAMETERS: None
	//RETURNS: bool
	bool Graphics::Init()
	{
		if (SDL_InitSubSystem(SDL_INIT_VIDEO) < 0) {
			std::cerr << "SDL did not init. Error: " << SDL_GetError() << std::endl;
			return false;
		}

		window = SDL_CreateWindow(
			WINDOW_TITLE,
			SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED,
			SCREEN_WIDTH,
			SCREEN_HEIGHT,
			SDL_WINDOW_SHOWN);

		if (window == nullptr) {
			std::cerr << "window did not get created. Error: " << SDL_GetError() << std::endl;
			return false;
		}

		if (TTF_Init() == -1) {
			std::cerr << "SDL_ttf unable to init. Error: " << TTF_GetError() << std::endl;
			return false;
		}

		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
		if (renderer == nullptr) {
			std::cerr << "renderer did not get created. Error: " << SDL_GetError() << std::endl;
			return false;
		}

		return true;
	}

	//Function: GetDidInit
	//DESCRIPTION: function used to get the didInit variable
	//PARAMETERS: None
	//RETURNS: bool didInit
	bool Graphics::GetDidInit()
	{
		return didInit;
	}

	SDL_Renderer* Graphics::GetRenderer()
	{
		return renderer;
	}

	//Function: Release
	//DESCRIPTION: function to be called when deconstructed
	//PARAMETERS: None
	//RETURNS: None
	void Graphics::Release()
	{
		delete instance;
		instance = nullptr;
	}

	//Function: ClearRenderer
	//DESCRIPTION: function used to clear the renderer completely
	//PARAMETERS: None
	//RETURNS: None
	void Graphics::ClearRenderer()
	{
		SDL_RenderClear(renderer);
	}

	//Function: Render
	//DESCRIPTION: function used to render the current renderer
	//PARAMETERS: None
	//RETURNS: None
	void Graphics::Render()
	{
		SDL_RenderPresent(renderer);
	}

	//Function: DrawTexture
	//DESCRIPTION: function used to draw a specified texture to the screen using the renderer
	//PARAMETERS: SDL_Texture* tex, SDL_Rect* srcRect, SDL_Rect* dstRect, float angle, SDL_RendererFlip flip
	//RETURNS: None
	void Graphics::DrawTexture(SDL_Texture* tex, SDL_Rect* srcRect, SDL_Rect* dstRect, float angle, SDL_RendererFlip flip)
	{
		SDL_RenderCopyEx(renderer, tex, srcRect, dstRect, angle, nullptr, flip);
	}

	//Function: SetTextTexture
	//DESCRIPTION: function used to set the text texture based on the font, color and text provided
	//PARAMETERS: TTF_Font* font, std::string text, SDL_Color color
	//RETURNS: SDL_Texture*
	SDL_Texture* Graphics::SetTextTexture(TTF_Font* font, std::string text, SDL_Color color)
	{
		SDL_Surface* surface = TTF_RenderText_Solid(font, text.c_str(), color);
		if (surface == nullptr) {
			std::cerr << "TTF_RenderText_Solid error. Error: " << TTF_GetError() << std::endl;
			return nullptr;
		}

		SDL_Texture* tex = SDL_CreateTextureFromSurface(renderer, surface);
		if (tex == nullptr) {
			std::cerr << "SDL_CreateTextureFromSurface error. Error: " << SDL_GetError() << std::endl;
			return nullptr;
		}
		SDL_FreeSurface(surface);
		return tex;
	}

	//Function: SetTexture
	//DESCRIPTION: function used to set the texture resource for the game
	//PARAMETERS: std::string path
	//RETURNS: SDL_Texture*
	SDL_Texture* Graphics::SetTexture(std::string path)
	{
		SDL_Texture* tex = nullptr;
		SDL_Surface* surface = IMG_Load(path.c_str());

		if (surface == nullptr) {
			std::cerr << "Unable to load " << path << ". IMG Error: " << IMG_GetError() << std::endl;
			return nullptr;
		}

		tex = SDL_CreateTextureFromSurface(renderer, surface);
		if (tex == nullptr) {
			std::cerr << "Texture failed to create from surface. Error: " << IMG_GetError() << std::endl;
			return nullptr;
		}
		SDL_FreeSurface(surface);
		return tex;
	}

	SDL_Texture* Graphics::renderText(const std::string& message, const std::string& filepath, SDL_Color colour, int fontsize) {
		//Open the font
		TTF_Font* font = TTF_OpenFont(filepath.c_str(), fontsize);
		if (font == nullptr) {
			std::cerr << "TTF_OpenFont" << TTF_GetError;
			return nullptr;
		}
		//render to a surface as that's what TTF_RenderText returns
		SDL_Surface* surf = TTF_RenderText_Blended(font, message.c_str(), colour);
		if (surf == nullptr) {
			TTF_CloseFont(font);
			std::cout << "TTF_RenderText" << TTF_GetError;
			return nullptr;
		}
		//load that surface into texture
		SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surf);
		if (texture == nullptr) {
			std::cout << "CreateTexture" << SDL_GetError();
		}
		//Clean up surface and font
		SDL_FreeSurface(surf);
		TTF_CloseFont(font);
		return texture;
	}

	void Graphics::renderTexture(SDL_Texture* tex, int x, int y, SDL_Rect* clip = nullptr) {
		SDL_Rect dst;
		dst.x = x;
		dst.y = y;
		if (clip != nullptr) {
			dst.w = clip->w;
			dst.h = clip->h;
		}
		else {
			SDL_QueryTexture(tex, NULL, NULL, &dst.w, &dst.h);
		}
		SDL_RenderCopy(renderer, tex, clip, &dst);
	}



}