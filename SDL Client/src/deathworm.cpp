#include <deathworm.hpp>

Worm::Worm(int mPosX,int mPosY, LTexture* wormTexture,int velX,int velY){
	this->mPosX=mPosX;
	this->mPosY=mPosY;
	this->wormTexture=wormTexture;
	this->mVelX=velX;
	this->mVelY=velY;
}

Worm::~Worm(){
	this->wormTexture=NULL;
}

void Worm::move(){
    //mPosX += mVelX;

	srand(time(0));

	int ydir = rand()%2;
    
    mPosY = (ydir == 1) ? (mPosY + mVelY) : (mPosY - mVelY);

    if(mPosY < 0){
        mPosY=0;
    }

    if(mPosY + GHOST_HEIGHT > LEVEL_HEIGHT){
        mPosY = LEVEL_HEIGHT-GHOST_HEIGHT;
    }

}

void Worm::render(int cameraX,int cameraY){
    SDL_Rect renderQuad = { mPosX-cameraX, mPosY-cameraY, TILE_SIZE*2, TILE_SIZE };

    //Render to screen
    SDL_RenderCopy( gRenderer, wormTexture->getTexture(), NULL, &renderQuad);

}

