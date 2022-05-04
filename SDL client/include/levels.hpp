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

#include<vector>
void level1(LTexture* &currentTexture,SDL_Rect &camera, Player &dot, Player &dot2, std::stringstream &timeText, int &timeLeft,std::stringstream &score,LTexture &p,SDL_Color &textColor, Text &textPoints, Text &lives, LTimer &timer, std::vector <Entity>&coins, std::vector<Ghost>&ghosts, Entity &winflag);
void level2();

#endif