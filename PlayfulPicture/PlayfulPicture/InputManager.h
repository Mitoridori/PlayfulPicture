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
        //static pointer for an instance of input manager
        static InputManager* sInstance;
        //Uint8 kind of like a char in my research, this one just stores what keys are pressed
        const Uint8* mKeyboardState;
        //kinda same as above, but this one holds what keys were pressed before the current key press
        Uint8* mPrevKeyboardState;
        //key press duration
        int mKeyLength;
        //similar to the keyboard state members, but for the mouse
        Uint32 mMouseState;
        Uint32 mPrevMouseState;
        //the below members hold int values representative of the mouses Cartesian co-ordinate on the screen (X/Y respectively)
        int mMouseXPos;
        int mMouseYPos;

    public:
        //enum for the states of mouse buttons
        enum MouseButton { Left = 0, Right, Middle, Back, Forward };

        //pointer to an instance of the manager
        static InputManager* Instance();
        static void Release();

        //functions that take in a key press or mouse button code as arguement and perform an action accordingly
        bool MouseButtonDown(MouseButton button);
        bool MouseButtonPressed(MouseButton button);
        bool MouseButtonReleased(MouseButton button);
        Vector2 MousePosition();

        void Update();
        void UpdatePrevInput();
    };
}

#endif