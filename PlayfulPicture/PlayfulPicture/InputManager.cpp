#include "InputManager.h"
#include <string.h>
namespace SDLFramework
{
    InputManager* InputManager::sInstance = nullptr;

    InputManager* InputManager::Instance()
    {
        if (sInstance == nullptr)
        {
            sInstance = new InputManager();
        }
        return sInstance;
    }
    void InputManager::Release()
    {
        delete sInstance;
        sInstance = nullptr;
    }

    bool InputManager::MouseButtonDown(MouseButton button)
    {
        Uint32 mask = 0;

        switch (button) {
        case Left:
            mask = SDL_BUTTON_LMASK;
            break;
        case Right:
            mask = SDL_BUTTON_RMASK;
            break;
        case Middle:
            mask = SDL_BUTTON_MMASK;
            break;
        case Back:
            mask = SDL_BUTTON_X1MASK;
            break;
        case Forward:
            mask = SDL_BUTTON_X2MASK;
            break;
        }
        return (mMouseState & mask) != 0;
    }

    bool InputManager::MouseButtonPressed(MouseButton button)
    {
        Uint32 mask = 0;

        switch (button) {
        case Left:
            mask = SDL_BUTTON_LMASK;
            break;
        case Right:
            mask = SDL_BUTTON_RMASK;
            break;
        case Middle:
            mask = SDL_BUTTON_MMASK;
            break;
        case Back:
            mask = SDL_BUTTON_X1MASK;
            break;
        case Forward:
            mask = SDL_BUTTON_X2MASK;
            break;
        }
        return !(mPrevMouseState & mask) && (mMouseState & mask);
    }

    bool InputManager::MouseButtonReleased(MouseButton button)
    {
        Uint32 mask = 0;

        switch (button) {
        case Left:
            mask = SDL_BUTTON_LMASK;
            break;
        case Right:
            mask = SDL_BUTTON_RMASK;
            break;
        case Middle:
            mask = SDL_BUTTON_MMASK;
            break;
        case Back:
            mask = SDL_BUTTON_X1MASK;
            break;
        case Forward:
            mask = SDL_BUTTON_X2MASK;
            break;
        }
        return (mPrevMouseState & mask) && !(mMouseState & mask);
    }

    Vector2 InputManager::MousePosition()
    {
        return Vector2((float)mMouseXPos, (float)mMouseYPos);
    }

    void InputManager::Update()
    {
        mMouseState = SDL_GetMouseState(&mMouseXPos, &mMouseYPos);
    }

    void InputManager::UpdatePrevInput()
    {
        mPrevMouseState = mMouseState;
    }

    InputManager::InputManager()
    {
       
    }

    InputManager::~InputManager()
    {

    }


}