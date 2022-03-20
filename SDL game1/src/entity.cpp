#include "Entity.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

Entity::Entity(float p_x, float p_y, float sz_w, float sz_h, SDL_Texture* p_tex)
:x(p_x), y(p_y), tex(p_tex)
{
	currentFrame.x = 0;
	currentFrame.y = 0;
	currentFrame.w = sz_w;
	currentFrame.h = sz_h;
}

float Entity::getX()
{
	return x;
}
float Entity::getY()
{
	return y;
}

SDL_Texture* Entity::getTex()
{
	return tex;
}

SDL_Rect Entity::getCurrentFrame()
{
	return currentFrame;
}