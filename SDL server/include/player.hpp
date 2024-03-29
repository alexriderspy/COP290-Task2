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
        int mapStaffCanteen[MAPSTAFF_HEIGHT][MAPSTAFF_WIDTH];
        int mapLibrary[MAPLIBRARY_HEIGHT][MAPLIBRARY_WIDTH];
        int mapHostel[MAPHOSTEL_HEIGHT][MAPHOSTEL_WIDTH];
        int mapScoops[MAPSCOOPS_HEIGHT][MAPSCOOPS_WIDTH];

        LTexture playerUpTexture;
        std::string pathUp;
        LTexture playerDownTexture;
        std::string pathDown;
        LTexture playerLeftTexture;
        std::string pathLeft;
        LTexture playerRightTexture;
        std::string pathRight;
        std::string path;

        LTexture lastTexture;
        LTexture nameTexture;

        //Initializes the variables
        
        Player(std::string hostel,std::string name, int lives,int points,std::string pathUp,std::string pathDown,std::string pathLeft,std::string pathRight);

        //Takes key presses and adjusts the Player's velocity
        void handleEvent(SDL_Event&e, LTexture* currentTexture);

        //Shows the Player on the screen
        void render(SDL_Event &e, int camX,int camY);
        void render(int camX,int camY);

        int getmPosX();
        int getmPosY();

        //The X and Y offsets of the Player
        int mPosX, mPosY;

        //The velocity of the Player
        
};

#endif

