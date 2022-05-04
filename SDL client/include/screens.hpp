#ifndef _SCREENS_H
#define _SCREENS_H


#pragma once

#include <constants.hpp>
#include <global.hpp>
#include<timer.hpp>

void title(int &flagLoading, LTexture* &currentTexture, int &timeLeft, LTimer &timerLoading);
void choose(bool &renderText,LTexture* &currentTexture, std::string &inputText, SDL_Color &textColor);

#endif