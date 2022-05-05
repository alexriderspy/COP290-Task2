#ifndef _GLOBAL_H

#define _GLOBAL_H
#pragma once

#include "ltexture.hpp"

extern SDL_Window* gWindow;

extern SDL_Renderer* gRenderer;

extern TTF_Font* gFont;

extern Mix_Music* gMusic;

//The sound effects that will be used

extern Mix_Chunk* gArm,*gCreature,*gEnterDarkness,*gBlood;

extern LTexture gScreen1Texture;

extern LTexture gEnterTexture;
extern LTexture gMazeTexture;

extern LTexture gTextTexture;

extern LTexture gLoading1Texture;
extern LTexture gLoading2Texture;
extern LTexture gLoading3Texture;

extern LTexture gGameTexture;
extern LTexture gLHCTexture;
extern LTexture gStaffCanteen;
extern LTexture gBroomTexture;
extern LTexture gScoopsTexture;
extern LTexture gLibraryTexture;
extern LTexture gHostelTexture;


extern LTexture gTimeTextTexture;
extern LTexture gInputTextTexture;

extern LTexture gPlayerTexture;
extern LTexture gCoinTexture;
extern LTexture gFlagTexture;
extern LTexture gScoreBoardTexture;

extern LTexture gScoreTexture;
extern LTexture gGhostTexture;
extern LTexture gGameOverTexture;

#endif