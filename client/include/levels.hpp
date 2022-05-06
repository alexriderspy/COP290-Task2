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
#include <utility>

class Level1{
public:
    std::vector<bool>lhc_vis;
    std::vector<bool> hasEaten;
    std::vector<bool>football;
    std::vector<std::pair<int,int>>pos_football;
    std::vector<std::pair<int,int>>pos_LHC;
    std::vector<std::pair<int,int>>pos_staff_canteen;

    Level1();

    bool checkLHC(Player&dot,LTexture* currentTexture);
    bool checkStaffCanteen(Player&dot,LTexture* currentTexture);
    bool checkFootball(Player&dot);
    void print();

};

class Level2{
public:
    std::vector <bool>hostel;
    std::vector<bool>scoops;
    std::vector<bool>library;
    std::vector<bool>sac;
    std::vector <std::pair<int,int>>pos_hostel;
    std::vector <std::pair<int,int>>pos_scoops;
    std::vector <std::pair<int,int>>pos_library;
    std::vector <std::pair<int,int>>pos_sac;

    Level2();

    bool checkHostel(Player&dot,LTexture* currentTexture);
    bool checkScoops(Player&dot,LTexture* currentTexture);
    bool checkLibrary(Player&dot,LTexture* currentTexture);
    bool checkSac(Player&dot);
    void print();
    

};

void level1(LTexture* &currentTexture,SDL_Rect &camera, Player &dot, Player &dot2, std::stringstream &timeText, int &timeLeft,std::stringstream &score,LTexture &p,SDL_Color &textColor, Text &textPoints, Text &lives, LTimer &timer, std::vector <Entity>&coins, std::vector<Ghost>&ghosts, Entity &winflag,Level1 &lev1,int &tex_server);
void level2(LTexture* &currentTexture,SDL_Rect &camera, Player &dot, Player &dot2, std::stringstream &timeText, int &timeLeft,std::stringstream &score,LTexture &p,SDL_Color &textColor, Text &textPoints, Text &lives, LTimer &timer, std::vector <Entity>&coins, std::vector<Ghost>&ghosts, Entity &winflag,Level2 &lev2,int &tex_server);

#endif