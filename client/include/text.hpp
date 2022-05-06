#ifndef _TEXT_H
#define _TEXT_H

#pragma once

#include <SDL2/SDL_ttf.h>

#include <ltexture.hpp>

class Text{
public:
	std::string text;

	Text(std::string text);

	std::string getText();
	void addText(std::string text);
	LTexture load(SDL_Color textColor);
};

#endif