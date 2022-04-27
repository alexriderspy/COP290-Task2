#ifndef _PLAYER_H
#define _PLAYER_H

#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>

#include <iostream>
#include <string>
#include <sstream>

#include <constants.hpp>

enum{
    NONE,
    HIMADRI,
    KAILASH,
    UDAIGIRI,
    ZANSKAR

};
class Player
{
    public:
        //The dimensions of the Player
        int hostel;
        int lives;
        std::string name;
        int points;
        int map[MAP_HEIGHT][MAP_WIDTH];

        //Initializes the variables
        Player();
        Player(int hostel,std::string name, int lives,int points);

        //Takes key presses and adjusts the Player's velocity
        void handleEvent( SDL_Event& e );

        //Moves the Player
        void move();

        //Shows the Player on the screen
        void render(int camX,int camY);

        int getmPosX();
        int getmPosY();

    private:
        //The X and Y offsets of the Player
        int mPosX, mPosY;

        //The velocity of the Player
        int mVelX, mVelY;
};

#endif

