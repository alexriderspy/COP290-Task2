#ifndef _MAP_H
#define _MAP_H
#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <iostream>
#include <string>
#include <sstream>

SDL_Texture* get_map_texture(SDL_Renderer *renderer);
SDL_Texture* get_mapLHC_texture(SDL_Renderer *renderer);
void save_texture(SDL_Renderer* ren, SDL_Texture* tex, const char* filename);

#endif