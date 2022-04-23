#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include <iostream>
#include <string>
#include <sstream>
#include <character.hpp>
#include <constants.hpp>

enum{
    NONE,
    HIMADRI,
    KAILASH,
    UDAIGIRI,
    ZANSKAR

};
class Character
{
    public:
        //The dimensions of the Character
        static const int CHARACTER_WIDTH = 20;
        static const int CHARACTER_HEIGHT = 20;

        //Maximum axis velocity of the Character
        static const int CHARACTER_POS = 10;

        int hostel;
        int lives;
        std::string name;
        int points;
        int map[MAP_HEIGHT][MAP_WIDTH];

        //Initializes the variables
        Character();
        Character(int hostel,std::string name, int lives,int points);

        //Takes key presses and adjusts the Character's velocity
        void handleEvent( SDL_Event& e );

        //Moves the Character
        void move();

        //Shows the Character on the screen
        void render(int camX,int camY);

        int getmPosX();
        int getmPosY();

    private:
        //The X and Y offsets of the Character
        int mPosX, mPosY;

        //The velocity of the Character
        int mVelX, mVelY;
};

