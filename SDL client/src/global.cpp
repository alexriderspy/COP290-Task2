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
LTexture gBlankTexture;
LTexture gGameTexture;
LTexture gTextTexture;
LTexture gLoading1Texture;
LTexture gLoading2Texture;
LTexture gLoading3Texture;
LTexture gTimeTextTexture;
LTexture gPlayerTexture;
LTexture gCoinTexture;
LTexture gFlagTexture;
LTexture gScoreBoardTexture;
LTexture gScoreTexture;
LTexture gGhostTexture;
LTexture gGameOverTexture;
LTexture gLHCTexture;