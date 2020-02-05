#ifndef __INPUTMANAGER_H
#define __INPUTMANAGER_H
#include <SDL.h>
#include "MathHelper.h"

namespace SDLFramework
{
    class InputManager {

    private:
        InputManager();
        ~InputManager();

        static InputManager* sInstance;

        Uint32 mMouseState;
        Uint32 mPrevMouseState;

        int mMouseXPos;
        int mMouseYPos;

    public:
        enum MouseButton { Left = 0, Right, Middle, Back, Forward };

        static InputManager* Instance();
        static void Release();

        bool MouseButtonDown(MouseButton button);
        bool MouseButtonPressed(MouseButton button);
        bool MouseButtonReleased(MouseButton button);
        Vector2 MousePosition();

        void Update();
        void UpdatePrevInput();
    };
}

#endif