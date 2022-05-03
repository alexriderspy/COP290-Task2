#include <flag.hpp>

#include <constants.hpp>
#include <global.hpp>

Flag::Flag(int posX,int posY,LTexture* texture){
	mPosX = posX;
	mPosY = posY;
	flagTexture = texture;
}

void Flag::render(int cameraX,int cameraY){
    SDL_Rect renderQuad = { mPosX-cameraX, mPosY-cameraY, TILE_SIZE/2, TILE_SIZE/2 };

    //Render to screen
    SDL_RenderCopy( gRenderer, flagTexture->getTexture(), NULL, &renderQuad);

}
