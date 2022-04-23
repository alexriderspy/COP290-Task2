#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_net.h>
#include <iostream>
#include <string>
#include <sstream>

SDL_Texture* get_map_texture(SDL_Renderer *renderer);
void save_texture(SDL_Renderer* ren, SDL_Texture* tex, const char* filename);