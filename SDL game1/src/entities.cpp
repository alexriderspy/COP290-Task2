#include <character.hpp>
#include <flag.hpp>
#include <coin.hpp>

#include <constants.hpp>
#include <global.hpp>

//character
Character::Character()
{
    //Initialize the offsets
    mPosX = 0*TILE_SIZE;
    mPosY = 60*TILE_SIZE;

    mVelX = 0;
    mVelY = 0;

    int map_flat[MAP_WIDTH*MAP_HEIGHT] = MAP;
    int id=0;
    for(int i=0;i<MAP_HEIGHT;++i){
        for(int j=0;j<MAP_WIDTH;++j){
            map[i][j]=map_flat[id++];
        }
    }
}

Character::Character(int hostel,std::string name, int lives,int points)
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
}

int getTileX(int mPosX,int mPosY){
    return mPosY/TILE_SIZE;
}

int getTileY(int mPosX,int mPosY){
    return mPosX/TILE_SIZE;
}

void Character::handleEvent( SDL_Event& e )
{
    //If a key was pressed
    if( e.type == SDL_KEYDOWN)
    {
        //Adjust the velocity
        switch( e.key.keysym.sym )
        {
            case SDLK_UP: mPosY -= CHARACTER_POS; if(map[getTileX(mPosX,mPosY)][getTileY(mPosX,mPosY)]==1) mPosY+= CHARACTER_POS; break;
            case SDLK_DOWN: mPosY += CHARACTER_POS; if(map[getTileX(mPosX,mPosY)][getTileY(mPosX,mPosY)]==1) mPosY-= CHARACTER_POS;break;
            case SDLK_LEFT: mPosX -= CHARACTER_POS; if(map[getTileX(mPosX,mPosY)][getTileY(mPosX,mPosY)]==1) mPosX+= CHARACTER_POS;break;
            case SDLK_RIGHT: mPosX += CHARACTER_POS; if(map[getTileX(mPosX,mPosY)][getTileY(mPosX,mPosY)]==1) mPosX-= CHARACTER_POS;break;
        }
    }
}

void Character::move(){
    //mPosX += mVelX;
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

//flag
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

//coin
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

