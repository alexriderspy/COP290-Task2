#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_net.h>
#include <iostream>
#include <string>
#include <sstream>
#include "ltexture.hpp"

extern SDL_Window* gWindow;

extern SDL_Renderer* gRenderer;

extern TTF_Font* gFont;

extern Mix_Music* gMusic;

//The sound effects that will be used
extern Mix_Chunk *gScratch;

extern LTexture gScreen1Texture;
extern LTexture gScreen2Texture;
extern LTexture gTextTexture;
extern LTexture gGameTexture;
extern LTexture gTimeTextTexture;
extern LTexture gCharacterTexture;
