#ifndef _PREGAME_H

#define _PREGAME_H

#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_net.h>

#include <global.hpp>

bool init();
bool loadMedia();
void close();

#endif