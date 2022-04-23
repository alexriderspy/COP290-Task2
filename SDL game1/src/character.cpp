#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include <iostream>
#include <string>
#include <sstream>
#include <character.hpp>
#include <global.hpp>
#include <constants.hpp>

Character::Character()
{
    //Initialize the offsets
    mPosX = 0;
    mPosY = 0;

    mVelX = 0;
    mVelY = 0;

    int map_flat[66*61] = MAP;
    int id=0;
    for(int i=0;i<66;++i){
        for(int j=0;j<61;++j){
            map[i][j]=map_flat[id++];
        }
    }
 

}

Character::Character(int hostel,std::string name, int lives,int points)
{
    //Initialize the offsets
    mPosX = 0;
    mPosY = 0;

    mVelX = 0;
    mVelY = 0;

    this->hostel=hostel;
    this->name = name;
    this->lives=lives;
    this->points=points;
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

void Character::move(){
    //mPosX += mVelX;

    int tileX = mPosX/TILE_SIZE;
    int tileY = mPosY/TILE_SIZE;

    if(mPosX <0){
        mPosX = 0;
    }


    if(mPosX + CHARACTER_WIDTH > LEVEL_WIDTH){
        mPosX = LEVEL_WIDTH-CHARACTER_WIDTH;
    }

    //mPosY += mVelY;

    if(mPosY < 0){
        mPosY=0;
    }

    if(mPosY + CHARACTER_HEIGHT > LEVEL_HEIGHT){
        mPosY = LEVEL_HEIGHT-CHARACTER_HEIGHT;
    }

    // if(map[tileX][tileY]==1){
    //     if(tileY>=1 && map[tileX][tileY-1]==0){
    //         mPosX=tileX*TILE_SIZE;
    //         mPosY=(tileY-1)*TILE_SIZE;
    //     }
    //     if(tileX>=1 && map[tileX-1][tileY]==0){
    //         mPosX=(tileX-1)*TILE_SIZE;
    //         mPosY=tileY*TILE_SIZE;
    //     }
    //     if(tileY+1<MAP_HEIGHT && map[tileX][tileY+1]==0){
    //         mPosX=tileX*TILE_SIZE;
    //         mPosY=(tileY+1)*TILE_SIZE;
    //     }
    //     if(tileX+1<MAP_WIDTH && map[tileX+1][tileY]==0){
    //         mPosX=(tileX+1)*TILE_SIZE;
    //         mPosY=tileY*TILE_SIZE;
    //     }
    // }

}

void Character::render(int camX,int camY){
    gCharacterTexture.render(mPosX - camX, mPosY - camY);
}

int Character::getmPosX(){
    return mPosX;
}

int Character::getmPosY(){
    return mPosY;
}

