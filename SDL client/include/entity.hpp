#ifndef _ENTITY_H
#define _ENTITY_H

#pragma once
#include <ltexture.hpp>

class Entity{
public:
	int value;
	int mPosX, mPosY;
	
	LTexture* entityTexture;

	Entity(int val,int posX,int posY,LTexture* entityTexture);

	~Entity();

	void render(int cameraX, int cameraY);
};

#endif

