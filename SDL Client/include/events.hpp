#ifndef _EVENTS_H

#define _EVENTS_H
#pragma once

#include <global.hpp>
#include <constants.hpp>
#include <timer.hpp>
#include <player.hpp>
#include<entity.hpp>
void events(SDL_Event &e,std::string &inputText, bool &renderText, bool &quit, LTimer &timer, Player &dot, Player &dot2,LTexture * &currentTexture,SDL_Rect &camera,int &level,Entity &winflag,int &tex,std::string &path,int &tex_server,int &level_server);

#endif