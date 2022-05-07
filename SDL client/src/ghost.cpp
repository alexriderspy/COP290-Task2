#include <ghost.hpp>

Ghost::Ghost(int mPosX,int mPosY, LTexture* ghostTexture,int velX,int velY){
	this->mPosX=mPosX;
	this->mPosY=mPosY;
	this->ghostTexture=ghostTexture;
	this->mVelX=velX;
	this->mVelY=velY;
}

Ghost::~Ghost(){
	this->ghostTexture=NULL;
}

void Ghost::move(){
    //mPosX += mVelX;

	srand(time(0));

	int xdir = rand()%2;
	int ydir = rand()%2;
    
    mPosX = (xdir == 1) ? (mPosX + mVelX) : (mPosX - mVelX);
    mPosY = (ydir == 1) ? (mPosY + mVelY) : (mPosY - mVelY);

    if(mPosX <0){
        mPosX = 0;
    }

    if(mPosX + GHOST_WIDTH > LEVEL_WIDTH){
        mPosX = LEVEL_WIDTH-GHOST_WIDTH;
    }

    if(mPosY < 0){
        mPosY=0;
    }

    if(mPosY + GHOST_HEIGHT > LEVEL_HEIGHT){
        mPosY = LEVEL_HEIGHT-GHOST_HEIGHT;
    }

}

void Ghost::render(int cameraX,int cameraY){
    SDL_Rect renderQuad = { mPosX-cameraX, mPosY-cameraY, TILE_SIZE, TILE_SIZE*2 };

    //Render to screen
    SDL_RenderCopy( gRenderer, ghostTexture->getTexture(), NULL, &renderQuad);

}

