#include <coin.hpp>

#include <constants.hpp>
#include <global.hpp>

Coin::Coin(int val,int mPosX,int mPosY, LTexture* coinTexture){
	this->value=val;
	this->mPosX=mPosX;
	this->mPosY=mPosY;
	this->coinTexture=coinTexture;
}

Coin::~Coin(){
	this->coinTexture=NULL;
}

void Coin::render(int cameraX,int cameraY){
    SDL_Rect renderQuad = { mPosX-cameraX, mPosY-cameraY, TILE_SIZE/2, TILE_SIZE/2 };

    //Render to screen
    SDL_RenderCopy( gRenderer, coinTexture->getTexture(), NULL, &renderQuad);

}

