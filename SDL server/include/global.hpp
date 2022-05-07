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

extern LTexture gScreen2Texture;
extern LTexture gScreen2_2Texture;
extern LTexture gScreen2_3Texture;
extern LTexture gScreen2_4Texture;
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
extern LTexture gHimadriTexture;
extern LTexture gKailashTexture;
extern LTexture gLHC_exTexture;
extern LTexture gGirnarTexture;
extern LTexture gKaraTexture;
extern LTexture gSacTexture;
//extern LTexture gRoom1LHCTexture;

extern LTexture gTimeTextTexture;
extern LTexture gInputTextTexture;

extern LTexture gPlayerTexture;
extern LTexture gCoinTexture;
extern LTexture gFlagTexture;
extern LTexture gScoreBoardTexture;

extern LTexture gScoreTexture;
extern LTexture gGhostTexture;
extern LTexture gGameOverTexture;

extern LTexture gWordOfAdvice;

extern LTexture girl1BackTexture;
extern LTexture girl1LeftTexture;
extern LTexture girl1FrontTexture;
extern LTexture girl1RightTexture;

extern LTexture girl2BackTexture;
extern LTexture girl2LeftTexture;
extern LTexture girl2FrontTexture;
extern LTexture girl2RightTexture;

extern LTexture boy1BackTexture;
extern LTexture boy1LeftTexture;
extern LTexture boy1FrontTexture;
extern LTexture boy1RightTexture;

extern LTexture boy2BackTexture;
extern LTexture boy2LeftTexture;
extern LTexture boy2FrontTexture;
extern LTexture boy2RightTexture;

extern LTexture r_lhc;
extern LTexture r_sc;
extern LTexture r_fb;

extern LTexture lhc1;
extern LTexture lhc2;
extern LTexture lhc3;
extern LTexture lhc4;
extern LTexture sc;
extern LTexture fb;

extern LTexture r_hos;
extern LTexture r_scoops;
extern LTexture r_lib;
extern LTexture r_sac;
extern LTexture r_gate;

extern LTexture hos1;
extern LTexture hos2;

extern LTexture scoops;

extern LTexture lib1;
extern LTexture lib2;
extern LTexture lib3;

extern LTexture sac1;
extern LTexture sac2;

#endif