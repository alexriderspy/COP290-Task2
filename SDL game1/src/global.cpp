#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_net.h>
#include <iostream>
#include <string>
#include <sstream>
#include "../include/timer.hpp"
#include "../include/character.hpp"
#include "../include/map.hpp"
#include "../include/ltexture.hpp"
#include "../include/global.hpp"

SDL_Window* gWindow = NULL;

//The window renderer
SDL_Renderer* gRenderer = NULL;

TTF_Font* gFont = NULL;

Mix_Music* gMusic = NULL;

//The sound effects that will be used
Mix_Chunk *gScratch = NULL;

LTexture gScreen1Texture;
LTexture gScreen2Texture;
LTexture gGameTexture;
LTexture gTextTexture;
LTexture gTimeTextTexture;
LTexture gCharacterTexture;
LTexture gCoinTexture;
LTexture gFlagTexture;
LTexture gScoreBoardTexture;