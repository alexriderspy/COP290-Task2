#include <player.hpp>

#include <constants.hpp>
#include <global.hpp>

// Player::Player()
// {
//     //Initialize the offsets
//     mPosX = 0*TILE_SIZE;
//     mPosY = 60*TILE_SIZE;

//     mVelX = 0;
//     mVelY = 0;

//     int map_flat[MAP_WIDTH*MAP_HEIGHT] = MAP;
//     int id=0;
//     for(int i=0;i<MAP_HEIGHT;++i){
//         for(int j=0;j<MAP_WIDTH;++j){
//             map[i][j]=map_flat[id++];
//         }
//     }
// }

Player::Player(std::string hostel,std::string name, int lives,int points)
{
    //Initialize the offsets
    mPosX = 0*TILE_SIZE;
    mPosY = 60*TILE_SIZE;

    mVelX = 0;
    mVelY = 0;

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

}

int getTileX(int mPosX,int mPosY){
    return mPosY/TILE_SIZE;
}

int getTileY(int mPosX,int mPosY){
    return mPosX/TILE_SIZE;
}

void Player::handleEvent( SDL_Event& e )
{
    //If a key was pressed
    if( e.type == SDL_KEYDOWN)
    {
        //Adjust the velocity
        switch( e.key.keysym.sym )
        {
            case SDLK_UP: mPosY -= PLAYER_POS; if(map[getTileX(mPosX,mPosY)][getTileY(mPosX,mPosY)]==1) mPosY+= PLAYER_POS; break;
            case SDLK_DOWN: mPosY += PLAYER_POS; if(map[getTileX(mPosX,mPosY)][getTileY(mPosX,mPosY)]==1) mPosY-= PLAYER_POS;break;
            case SDLK_LEFT: mPosX -= PLAYER_POS; if(map[getTileX(mPosX,mPosY)][getTileY(mPosX,mPosY)]==1) mPosX+= PLAYER_POS;break;
            case SDLK_RIGHT: mPosX += PLAYER_POS; if(map[getTileX(mPosX,mPosY)][getTileY(mPosX,mPosY)]==1) mPosX-= PLAYER_POS;break;
        }
    }
}

void Player::move(){
    //mPosX += mVelX;
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

void Player::render(int camX,int camY){
    gPlayerTexture.render(mPosX - camX, mPosY - camY);
    SDL_Color textColor = {0,0xFF,0xFF};
    if(!nameTexture.loadFromRenderedText(name,textColor)){
        printf("name cant be loaded");
    }
    nameTexture.render(mPosX-camX,mPosY-camY);
}

int Player::getmPosX(){
    return mPosX;
}

int Player::getmPosY(){
    return mPosY;
}
