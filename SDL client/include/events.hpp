#ifndef _EVENTS_H

#define _EVENTS_H
#pragma once

#include <global.hpp>
#include <constants.hpp>
#include <timer.hpp>
#include <player.hpp>

void events(SDL_Event &e,std::string &inputText, bool &renderText, bool &quit, LTimer &timer, Player &dot, LTexture * &currentTexture,SDL_Rect &camera);

#endif