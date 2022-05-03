#include <entity.hpp>

#include <constants.hpp>
#include <global.hpp>

Entity::Entity(int val,int mPosX,int mPosY, LTexture* coinTexture){
	this->value=val;
	this->mPosX=mPosX;
	this->mPosY=mPosY;
	this->entityTexture=coinTexture;
}

Entity::~Entity(){
	this->entityTexture=NULL;
}

void Entity::render(int cameraX,int cameraY){
    SDL_Rect renderQuad = { mPosX-cameraX, mPosY-cameraY, TILE_SIZE/2, TILE_SIZE/2 };

    //Render to screen
    SDL_RenderCopy( gRenderer, entityTexture->getTexture(), NULL, &renderQuad);

}

