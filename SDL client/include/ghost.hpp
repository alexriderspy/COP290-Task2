#pragma once

#include <ltexture.hpp>
#include <constants.hpp>
#include <global.hpp>

class Ghost{
public:
	int mPosX,mPosY;
	LTexture* ghostTexture;
	int mVelX, mVelY;

	Ghost(int mPosX,int mPosY,LTexture* tex,int mVelX,int mVelY);

	~Ghost();

	void move();
	void render(int camX,int camY);


};