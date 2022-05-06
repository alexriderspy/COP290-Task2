#ifndef _WORM_H

#define _WORM_H
#pragma once

#include <ltexture.hpp>
#include <constants.hpp>
#include <global.hpp>

class Worm{
public:
	int mPosX,mPosY;
	LTexture* wormTexture;
	int mVelX, mVelY;

	Worm(int mPosX,int mPosY,LTexture* tex,int mVelX,int mVelY);

	~Worm();

	void move();
	void render(int camX,int camY);


};

#endif