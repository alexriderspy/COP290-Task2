#ifndef _GLOBAL_H

#define _GLOBAL_H
#pragma once

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
extern LTexture gPlayerTexture;
extern LTexture gCoinTexture;
extern LTexture gFlagTexture;
extern LTexture gScoreBoardTexture;
extern LTexture gScoreTexture;
extern LTexture gGhostTexture;
extern LTexture gGameOverTexture;
extern LTexture gGamePauseTexture;
extern LTexture gLHCTexture;

#endif