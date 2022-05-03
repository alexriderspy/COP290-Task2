#include <player.hpp>

#include <constants.hpp>
#include <global.hpp>

Player::Player(std::string hostel,std::string name, int lives,int points)
{
    //Initialize the offsets
    mPosX = 0*TILE_SIZE;
    mPosY = 60*TILE_SIZE;

    this->hostel=hostel;
    this->name = name;
    this->lives=lives;
    this->points=points;

    int map_flat[MAP_WIDTH*MAP_HEIGHT] = MAP;
    int id=0;
    for(int i=0;i<MAP_HEIGHT;++i){
        for(int j=0;j<MAP_WIDTH;++j){
            map[i][j]=map_flat[id++];
        }
    }

    int mapLHC_flat[MAPLHC_WIDTH*MAPLHC_HEIGHT] = MAPLHC;
    id=0;
    for(int i=0;i<MAPLHC_HEIGHT;++i){
        for(int j=0;j<MAPLHC_WIDTH;++j){
            mapLHC[i][j]=mapLHC_flat[id++];
        }
    }
    yulu = false;
}

int getTileX(int mPosX,int mPosY){
    return mPosY/TILE_SIZE;
}

int getTileY(int mPosX,int mPosY){
    return mPosX/TILE_SIZE;
}

void Player::handleEvent( SDL_Event& e , LTexture* currentTexture)
{
    //If a key was pressed
    if(currentTexture == &gGameTexture){
        if( e.type == SDL_KEYDOWN)
        {
            //Adjust the velocity
            switch( e.key.keysym.sym )
            {
                case SDLK_UP: mPosY -= (yulu?PLAYER_VEL_YULU:PLAYER_VEL); if(map[getTileX(mPosX,mPosY)][getTileY(mPosX,mPosY)]==1) mPosY+= PLAYER_VEL; break;
                case SDLK_DOWN: mPosY += (yulu?PLAYER_VEL_YULU:PLAYER_VEL); if(map[getTileX(mPosX,mPosY)][getTileY(mPosX,mPosY)]==1) mPosY-= PLAYER_VEL;break;
                case SDLK_LEFT: mPosX -= (yulu?PLAYER_VEL_YULU:PLAYER_VEL); if(map[getTileX(mPosX,mPosY)][getTileY(mPosX,mPosY)]==1) mPosX+= PLAYER_VEL;break;
                case SDLK_RIGHT: mPosX += (yulu?PLAYER_VEL_YULU:PLAYER_VEL); if(map[getTileX(mPosX,mPosY)][getTileY(mPosX,mPosY)]==1) mPosX-= PLAYER_VEL;break;
            }
        }
        if(mPosX <0){
            mPosX = 0;
        }

        if(mPosX + PLAYER_WIDTH > LEVEL_WIDTH){
            mPosX = LEVEL_WIDTH-PLAYER_WIDTH;
        }

        if(mPosY < 0){
            mPosY=0;
        }

        if(mPosY + PLAYER_HEIGHT > LEVEL_HEIGHT){
            mPosY = LEVEL_HEIGHT-PLAYER_HEIGHT;
        }

    }
    else if(currentTexture == &gLHCTexture){
        if( e.type == SDL_KEYDOWN)
        {
            //Adjust the velocity
            switch( e.key.keysym.sym )
            {
                case SDLK_UP: mPosY -= PLAYER_VEL; if(map[getTileX(mPosX,mPosY)][getTileY(mPosX,mPosY)]==1) mPosY+= PLAYER_VEL; break;
                case SDLK_DOWN: mPosY += PLAYER_VEL; if(map[getTileX(mPosX,mPosY)][getTileY(mPosX,mPosY)]==1) mPosY-= PLAYER_VEL;break;
                case SDLK_LEFT: mPosX -= PLAYER_VEL; if(map[getTileX(mPosX,mPosY)][getTileY(mPosX,mPosY)]==1) mPosX+= PLAYER_VEL;break;
                case SDLK_RIGHT: mPosX += PLAYER_VEL; if(map[getTileX(mPosX,mPosY)][getTileY(mPosX,mPosY)]==1) mPosX-= PLAYER_VEL;break;
            }
        }
        if(mPosX <0){
            mPosX = 0;
        }

        if(mPosX + PLAYER_WIDTH > SCREEN_WIDTH){
            mPosX = SCREEN_WIDTH-PLAYER_WIDTH;
        }

        if(mPosY < 0){
            mPosY=0;
        }

        if(mPosY + PLAYER_HEIGHT > SCREEN_HEIGHT){
            mPosY = SCREEN_HEIGHT-PLAYER_HEIGHT;
        }

    }
}


void Player::render(int camX,int camY){
    gPlayerTexture.render(mPosX - camX, mPosY - camY);
    SDL_Color textColor = {0,0xFF,0xFF};
    if(!nameTexture.loadFromRenderedText(name,textColor)){
        printf("name cant be loaded");
    }
    nameTexture.render(mPosX-camX,mPosY-camY);
}

void Player::render(LTexture* currentTexture){
    if(currentTexture == &gLHCTexture){
        gPlayerTexture.render(mPosX, mPosY);
        SDL_Color textColor = {0,0xFF,0xFF};
        if(!nameTexture.loadFromRenderedText(name,textColor)){
            printf("name cant be loaded");
        }
        nameTexture.render(mPosX,mPosY);
    }
}

int Player::getmPosX(){
    return mPosX;
}

int Player::getmPosY(){
    return mPosY;
}
