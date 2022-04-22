#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include <iostream>
#include <string>
#include <sstream>
#include <character.hpp>

Character::Character()
{
    //Initialize the offsets
    mPosX = 700;
    mPosY = 600;
}

void Character::handleEvent( SDL_Event& e )
{
    //If a key was pressed
    if( e.type == SDL_KEYDOWN)
    {
        //Adjust the velocity
        switch( e.key.keysym.sym )
        {
            case SDLK_UP: mPosY -= CHARACTER_POS; break;
            case SDLK_DOWN: mPosY += CHARACTER_POS; break;
            case SDLK_LEFT: mPosX -= CHARACTER_POS; break;
            case SDLK_RIGHT: mPosX += CHARACTER_POS; break;
        }
    }
    else if( e.type == SDL_KEYUP)
    {
        //Adjust the velocity
        switch( e.key.keysym.sym )
        {
            case SDLK_UP: mPosY += CHARACTER_POS; break;
            case SDLK_DOWN: mPosY -= CHARACTER_POS; break;
            case SDLK_LEFT: mPosX += CHARACTER_POS; break;
            case SDLK_RIGHT: mPosX -= CHARACTER_POS; break;
        }
    }
}

int Character::getmPosX(){
    return mPosX;
}

int Character::getmPosY(){
    return mPosY;
}

