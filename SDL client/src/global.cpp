#include "global.hpp"

SDL_Window* gWindow = NULL;

//The window renderer
SDL_Renderer* gRenderer = NULL;

TTF_Font* gFont = NULL;

Mix_Music* gMusic = NULL;

//The sound effects that will be used
Mix_Chunk* gArm,*gCreature,*gEnterDarkness,*gBlood;

LTexture gScreen1Texture;
LTexture gEnterTexture;
LTexture gGameTexture;
LTexture gTextTexture;
LTexture gInputTextTexture;
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

