#include "global.hpp"

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
LTexture gPlayerTexture;
LTexture gCoinTexture;
LTexture gFlagTexture;
LTexture gScoreBoardTexture;
LTexture gScoreTexture;
LTexture gGhostTexture;
LTexture gGameOverTexture;
LTexture gGamePauseTexture;