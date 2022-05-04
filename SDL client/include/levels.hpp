#ifndef _LEVEL_H
#define _LEVEL_H

#pragma once

#include <constants.hpp>
#include <global.hpp>
#include <player.hpp>
#include <text.hpp>
#include <ghost.hpp>
#include <entity.hpp>
#include <timer.hpp>
#include <coordinates.hpp>

#include<vector>
#include <utility>

class Level1{
public:
    std::vector<bool>lhc_vis;
    std::vector<bool> hasEaten;
    std::vector<bool>football;
    std::vector<std::pair<int,int>>pos;

    Level1();

    bool checkLHC(Player&dot,LTexture* currentTexture,Coordinates c1,Coordinates c2,Coordinates c3,Coordinates c4);
    bool checkStaffCanteen(Player&dot,LTexture* currentTexture,Coordinates c1,Coordinates c2);
    bool checkFootball(Player&dot);

};

void level1(LTexture* &currentTexture,SDL_Rect &camera, Player &dot, Player &dot2, std::stringstream &timeText, int &timeLeft,std::stringstream &score,LTexture &p,SDL_Color &textColor, Text &textPoints, Text &lives, LTimer &timer, std::vector <Entity>&coins, std::vector<Ghost>&ghosts, Entity &winflag,Level1 &lev1);
void level2();

#endif