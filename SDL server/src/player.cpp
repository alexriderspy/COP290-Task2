#include <player.hpp>

#include <constants.hpp>
#include <global.hpp>

Player::Player(std::string hostel,std::string name, int lives,int points,std::string pathUp,std::string pathDown,std::string pathLeft,std::string pathRight)
{
    //Initialize the offsets
    mPosX = 95*TILE_SIZE;
    mPosY = 12*TILE_SIZE;

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

    int mapStaffCanteen_flat[MAPSTAFF_WIDTH*MAPSTAFF_HEIGHT] = MAPSTAFFCANTEEN;
    id=0;
    for(int i=0;i<MAPSTAFF_HEIGHT;++i){
        for(int j=0;j<MAPSTAFF_WIDTH;++j){
            mapStaffCanteen[i][j]=mapStaffCanteen_flat[id++];
        }
    }

    int mapScoops_flat[MAPSCOOPS_WIDTH*MAPSCOOPS_HEIGHT] = MAPSCOOPS;
    id=0;
    for(int i=0;i<MAPSCOOPS_HEIGHT;++i){
        for(int j=0;j<MAPSCOOPS_WIDTH;++j){
            mapScoops[i][j]=mapScoops_flat[id++];
        }
    }

    int mapLibrary_flat[MAPLIBRARY_WIDTH*MAPLIBRARY_HEIGHT] = MAPLIBRARY;
    id=0;
    for(int i=0;i<MAPLIBRARY_HEIGHT;++i){
        for(int j=0;j<MAPLIBRARY_WIDTH;++j){
            mapLibrary[i][j]=mapLibrary_flat[id++];
        }
    }

    int mapHostel_flat[MAPHOSTEL_WIDTH*MAPHOSTEL_HEIGHT] = MAPHOSTEL;
    id=0;
    for(int i=0;i<MAPHOSTEL_HEIGHT;++i){
        for(int j=0;j<MAPHOSTEL_WIDTH;++j){
            mapHostel[i][j]=mapHostel_flat[id++];
        }
    }

    if(!playerUpTexture.loadFromFile(pathUp)){
        std::cout<<"failed to load texture";
    }

    if(!playerDownTexture.loadFromFile(pathDown)){
        std::cout<<"failed to load texture";
    }
    if(!playerLeftTexture.loadFromFile(pathLeft)){
        std::cout<<"failed to load texture";
    }
    if(!playerRightTexture.loadFromFile(pathRight)){
        std::cout<<"failed to load texture";
    }

    this->pathDown = pathDown;
    this->pathUp = pathUp;
    this->pathLeft=pathLeft;
    this->pathRight=pathRight;

    lastTexture = playerDownTexture;

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
                case SDLK_UP: mPosY -= (PLAYER_VEL); if(map[getTileX(mPosX,mPosY)][getTileY(mPosX,mPosY)]==BLOCK || map[getTileX(mPosX,mPosY)][getTileY(mPosX,mPosY)]==BOUNDARY) mPosY+= (PLAYER_VEL); break;
                case SDLK_DOWN: mPosY += (PLAYER_VEL); if(map[getTileX(mPosX,mPosY)][getTileY(mPosX,mPosY)]==BLOCK || map[getTileX(mPosX,mPosY)][getTileY(mPosX,mPosY)]==BOUNDARY) mPosY-= (PLAYER_VEL);break;
                case SDLK_LEFT: mPosX -= (PLAYER_VEL); if(map[getTileX(mPosX,mPosY)][getTileY(mPosX,mPosY)]==BLOCK || map[getTileX(mPosX,mPosY)][getTileY(mPosX,mPosY)]==BOUNDARY) mPosX+= (PLAYER_VEL);break;
                case SDLK_RIGHT: mPosX += (PLAYER_VEL); if(map[getTileX(mPosX,mPosY)][getTileY(mPosX,mPosY)]==BLOCK || map[getTileX(mPosX,mPosY)][getTileY(mPosX,mPosY)]==BOUNDARY) mPosX-= (PLAYER_VEL);break;
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
        if( e.type == SDL_KEYDOWN){
    
            //Adjust the velocity
            switch( e.key.keysym.sym )
            {
                case SDLK_UP: mPosY -= PLAYER_VEL; if(mapLHC[getTileX(mPosX,mPosY)][getTileY(mPosX,mPosY)]==OBSTACLES_LHC || mapLHC[getTileX(mPosX,mPosY)][getTileY(mPosX,mPosY)]==BOUNDARY_LHC || mapLHC[getTileX(mPosX,mPosY)][getTileY(mPosX,mPosY)]==DIAMOND) mPosY+= PLAYER_VEL; break;
                case SDLK_DOWN: mPosY += PLAYER_VEL; if(mapLHC[getTileX(mPosX,mPosY)][getTileY(mPosX,mPosY)]==OBSTACLES_LHC || mapLHC[getTileX(mPosX,mPosY)][getTileY(mPosX,mPosY)]==BOUNDARY_LHC || mapLHC[getTileX(mPosX,mPosY)][getTileY(mPosX,mPosY)]==DIAMOND) mPosY-= PLAYER_VEL;break;
                case SDLK_LEFT: mPosX -= PLAYER_VEL; if(mapLHC[getTileX(mPosX,mPosY)][getTileY(mPosX,mPosY)]==OBSTACLES_LHC || mapLHC[getTileX(mPosX,mPosY)][getTileY(mPosX,mPosY)]==BOUNDARY_LHC || mapLHC[getTileX(mPosX,mPosY)][getTileY(mPosX,mPosY)]==DIAMOND) mPosX+= PLAYER_VEL;break;
                case SDLK_RIGHT: mPosX += PLAYER_VEL; if(mapLHC[getTileX(mPosX,mPosY)][getTileY(mPosX,mPosY)]==OBSTACLES_LHC || mapLHC[getTileX(mPosX,mPosY)][getTileY(mPosX,mPosY)]==BOUNDARY_LHC || mapLHC[getTileX(mPosX,mPosY)][getTileY(mPosX,mPosY)]==DIAMOND) mPosX-= PLAYER_VEL;break;
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
    else if(currentTexture == &gStaffCanteen){
        if( e.type == SDL_KEYDOWN){
    
            //Adjust the velocity
            switch( e.key.keysym.sym )
            {
                case SDLK_UP: mPosY -= PLAYER_VEL; if(mapStaffCanteen[getTileX(mPosX,mPosY)][getTileY(mPosX,mPosY)]==CHAIRS_CANTEEN || mapStaffCanteen[getTileX(mPosX,mPosY)][getTileY(mPosX,mPosY)]==OBSTACLES_CANTEEN || mapStaffCanteen[getTileX(mPosX,mPosY)][getTileY(mPosX,mPosY)]==BOUNDARY_CANTEEN) mPosY+= PLAYER_VEL; break;
                case SDLK_DOWN: mPosY += PLAYER_VEL; if(mapStaffCanteen[getTileX(mPosX,mPosY)][getTileY(mPosX,mPosY)]==CHAIRS_CANTEEN || mapStaffCanteen[getTileX(mPosX,mPosY)][getTileY(mPosX,mPosY)]==OBSTACLES_CANTEEN || mapStaffCanteen[getTileX(mPosX,mPosY)][getTileY(mPosX,mPosY)]==BOUNDARY_CANTEEN) mPosY-= PLAYER_VEL;break;
                case SDLK_LEFT: mPosX -= PLAYER_VEL; if(mapStaffCanteen[getTileX(mPosX,mPosY)][getTileY(mPosX,mPosY)]==CHAIRS_CANTEEN || mapStaffCanteen[getTileX(mPosX,mPosY)][getTileY(mPosX,mPosY)]==OBSTACLES_CANTEEN || mapStaffCanteen[getTileX(mPosX,mPosY)][getTileY(mPosX,mPosY)]==BOUNDARY_CANTEEN) mPosX+= PLAYER_VEL;break;
                case SDLK_RIGHT: mPosX += PLAYER_VEL; if(mapStaffCanteen[getTileX(mPosX,mPosY)][getTileY(mPosX,mPosY)]==CHAIRS_CANTEEN || mapStaffCanteen[getTileX(mPosX,mPosY)][getTileY(mPosX,mPosY)]==OBSTACLES_CANTEEN || mapStaffCanteen[getTileX(mPosX,mPosY)][getTileY(mPosX,mPosY)]==BOUNDARY_CANTEEN) mPosX-= PLAYER_VEL;break;
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
    else if(currentTexture == &gScoopsTexture){
        if( e.type == SDL_KEYDOWN){
    
            //Adjust the velocity
            switch( e.key.keysym.sym )
            {
                case SDLK_UP: mPosY -= PLAYER_VEL; if(mapScoops[getTileX(mPosX,mPosY)][getTileY(mPosX,mPosY)]==OBSTACLES_SCOOPS || mapScoops[getTileX(mPosX,mPosY)][getTileY(mPosX,mPosY)]==BOUNDARY_SCOOPS || mapScoops[getTileX(mPosX,mPosY)][getTileY(mPosX,mPosY)]==DESK_SCOOPS) mPosY+= PLAYER_VEL; break;
                case SDLK_DOWN: mPosY += PLAYER_VEL; if(mapScoops[getTileX(mPosX,mPosY)][getTileY(mPosX,mPosY)]==OBSTACLES_SCOOPS || mapScoops[getTileX(mPosX,mPosY)][getTileY(mPosX,mPosY)]==BOUNDARY_SCOOPS || mapScoops[getTileX(mPosX,mPosY)][getTileY(mPosX,mPosY)]==DESK_SCOOPS) mPosY-= PLAYER_VEL;break;
                case SDLK_LEFT: mPosX -= PLAYER_VEL; if(mapScoops[getTileX(mPosX,mPosY)][getTileY(mPosX,mPosY)]==OBSTACLES_SCOOPS || mapScoops[getTileX(mPosX,mPosY)][getTileY(mPosX,mPosY)]==BOUNDARY_SCOOPS || mapScoops[getTileX(mPosX,mPosY)][getTileY(mPosX,mPosY)]==DESK_SCOOPS) mPosX+= PLAYER_VEL;break;
                case SDLK_RIGHT: mPosX += PLAYER_VEL; if(mapScoops[getTileX(mPosX,mPosY)][getTileY(mPosX,mPosY)]==OBSTACLES_SCOOPS || mapScoops[getTileX(mPosX,mPosY)][getTileY(mPosX,mPosY)]==BOUNDARY_SCOOPS || mapScoops[getTileX(mPosX,mPosY)][getTileY(mPosX,mPosY)]==DESK_SCOOPS) mPosX-= PLAYER_VEL;break;
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
    else if(currentTexture == &gHostelTexture){
        if( e.type == SDL_KEYDOWN){
    
            //Adjust the velocity
            switch( e.key.keysym.sym )
            {
                case SDLK_UP: mPosY -= PLAYER_VEL; if(mapHostel[getTileX(mPosX,mPosY)][getTileY(mPosX,mPosY)]==BOUNDARY_HOSTEL) mPosY+= PLAYER_VEL; break;
                case SDLK_DOWN: mPosY += PLAYER_VEL; if(mapHostel[getTileX(mPosX,mPosY)][getTileY(mPosX,mPosY)]==BOUNDARY_HOSTEL) mPosY-= PLAYER_VEL;break;
                case SDLK_LEFT: mPosX -= PLAYER_VEL; if(mapHostel[getTileX(mPosX,mPosY)][getTileY(mPosX,mPosY)]==BOUNDARY_HOSTEL) mPosX+= PLAYER_VEL;break;
                case SDLK_RIGHT: mPosX += PLAYER_VEL; if(mapHostel[getTileX(mPosX,mPosY)][getTileY(mPosX,mPosY)]==BOUNDARY_HOSTEL) mPosX-= PLAYER_VEL;break;
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
    else if(currentTexture == &gLibraryTexture){
        if( e.type == SDL_KEYDOWN){
    
            //Adjust the velocity
            switch( e.key.keysym.sym )
            {
                case SDLK_UP: mPosY -= PLAYER_VEL; if(mapLibrary[getTileX(mPosX,mPosY)][getTileY(mPosX,mPosY)]==OBSTACLES_LIB ||mapLibrary[getTileX(mPosX,mPosY)][getTileY(mPosX,mPosY)]==BOUNDARY_LIB ) mPosY+= PLAYER_VEL; break;
                case SDLK_DOWN: mPosY += PLAYER_VEL; if(mapLibrary[getTileX(mPosX,mPosY)][getTileY(mPosX,mPosY)]==OBSTACLES_LIB ||mapLibrary[getTileX(mPosX,mPosY)][getTileY(mPosX,mPosY)]==BOUNDARY_LIB ) mPosY-= PLAYER_VEL;break;
                case SDLK_LEFT: mPosX -= PLAYER_VEL; if(mapLibrary[getTileX(mPosX,mPosY)][getTileY(mPosX,mPosY)]==OBSTACLES_LIB ||mapLibrary[getTileX(mPosX,mPosY)][getTileY(mPosX,mPosY)]==BOUNDARY_LIB ) mPosX+= PLAYER_VEL;break;
                case SDLK_RIGHT: mPosX += PLAYER_VEL; if(mapLibrary[getTileX(mPosX,mPosY)][getTileY(mPosX,mPosY)]==OBSTACLES_LIB ||mapLibrary[getTileX(mPosX,mPosY)][getTileY(mPosX,mPosY)]==BOUNDARY_LIB ) mPosX-= PLAYER_VEL;break;
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
    lastTexture.render(mPosX -10-camX, mPosY-50 - camY);
    SDL_Color textColor = {0,0xFF,0xFF};
    if(!nameTexture.loadFromRenderedText(name,textColor)){
        printf("name cant be loaded");
    }
    nameTexture.render(mPosX-camX,mPosY-camY);
}
void Player::render(SDL_Event&e,int camX,int camY){
    if(e.type == SDL_KEYDOWN){
        if(e.key.keysym.sym == SDLK_DOWN){
            playerDownTexture.render(mPosX - 10- camX, mPosY-50 - camY);
            lastTexture = playerDownTexture;
            path = pathDown;
        }
        else if(e.key.keysym.sym == SDLK_UP){
            playerUpTexture.render(mPosX - 10-camX, mPosY-50 - camY);
            lastTexture = playerUpTexture;
            path = pathUp;
        }
        else if(e.key.keysym.sym == SDLK_RIGHT){
            playerRightTexture.render(mPosX -10- camX, mPosY-50 - camY);
            lastTexture = playerRightTexture;
            path = pathRight;
        }
        else if(e.key.keysym.sym == SDLK_LEFT){
            playerLeftTexture.render(mPosX -10- camX, mPosY-50 - camY);
            lastTexture = playerLeftTexture;
            path = pathLeft;
        }
    }
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
