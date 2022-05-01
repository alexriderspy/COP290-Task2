#ifndef _PLAYER_H
#define _PLAYER_H

#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>

#include <ltexture.hpp>

#include <iostream>
#include <string>
#include <sstream>

#include <constants.hpp>

class Player
{
    public:
        //The dimensions of the Player
        std::string hostel;
        int lives;
        std::string name;
        int points;
        int map[MAP_HEIGHT][MAP_WIDTH];
        int mapLHC[MAPLHC_HEIGHT][MAPLHC_WIDTH];

        bool yulu;

        LTexture nameTexture;

        //Initializes the variables
        
        Player(std::string hostel,std::string name, int lives,int points);

        //Takes key presses and adjusts the Player's velocity
        void handleEvent( SDL_Event& e );
        void handleEvent(SDL_Event&e, LTexture* currentTexture);

        //Moves the Player
        void move(LTexture* currentTexture);

        //Shows the Player on the screen
        void render(int camX,int camY);
        void render(LTexture* currentTexture);

        int getmPosX();
        int getmPosY();

        //The X and Y offsets of the Player
        int mPosX, mPosY;

        //The velocity of the Player
        
};

#endif

