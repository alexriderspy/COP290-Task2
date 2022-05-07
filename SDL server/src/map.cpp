#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include <iostream>
#include <string>
#include <sstream>

#include <map.hpp>
#include <player.hpp>
#include <constants.hpp>
#include <global.hpp>


SDL_Texture* get_map_texture(SDL_Renderer *renderer) {
    int map_flat[MAP_WIDTH*MAP_HEIGHT] = MAP;

    int map[MAP_HEIGHT][MAP_WIDTH];
    int id=0;
    for(int i=0;i<MAP_HEIGHT;++i){
        for(int j=0;j<MAP_WIDTH;++j){
            map[i][j]=map_flat[id];
            ++id;
        }
    }

SDL_Surface *bitmap1 = NULL;
SDL_Surface *bitmap2 = NULL;
SDL_Surface *bitmap3 = NULL;
SDL_Surface *bitmap4 = NULL;
SDL_Surface *bitmap5 = NULL;
SDL_Surface *bitmap6 = NULL;
SDL_Surface *bitmap7 = NULL;
SDL_Surface *bitmap8 = NULL;
SDL_Surface *bitmap9 = NULL;
SDL_Surface *bitmap10 = NULL;
SDL_Surface *bitmap11 = NULL;
SDL_Surface *bitmap12 = NULL;
SDL_Surface *bitmap13 = NULL;
SDL_Surface *bitmap14 = NULL;
SDL_Surface *bitmap15 = NULL;
SDL_Surface *bitmap16 = NULL;

SDL_Texture *map_texture;

SDL_Rect rectangle_;
rectangle_.w = TILE_SIZE;
rectangle_.h = TILE_SIZE;

bitmap1 = SDL_LoadBMP("res/tile.bmp");
bitmap2 = SDL_LoadBMP("res/LHC.bmp");
bitmap3 = SDL_LoadBMP("res/deathpool.bmp");
bitmap4 = SDL_LoadBMP("res/hostelfront.bmp");
bitmap5 = SDL_LoadBMP("res/boundary.bmp");
bitmap6 = SDL_LoadBMP("res/mainpath.bmp");
bitmap7 = SDL_LoadBMP("res/lawn.bmp");
bitmap8 = SDL_LoadBMP("res/must.bmp");
bitmap9 = SDL_LoadBMP("res/pink.bmp");
bitmap10 = SDL_LoadBMP("res/shine.bmp");
bitmap11 = SDL_LoadBMP("res/skull.bmp");
bitmap12 = SDL_LoadBMP("res/moon_tile.bmp");
bitmap13 = SDL_LoadBMP("res/brown.bmp");
bitmap14 = SDL_LoadBMP("res/red_spots.bmp");
bitmap15 = SDL_LoadBMP("res/stone.bmp");
bitmap16 = SDL_LoadBMP("res/doll_tile.bmp");

SDL_Texture *tex1 = NULL;
SDL_Texture *tex2 = NULL;
SDL_Texture *tex3 = NULL;
SDL_Texture *tex4 = NULL;
SDL_Texture *tex5 = NULL;
SDL_Texture *tex6 = NULL;
SDL_Texture *tex7 = NULL;
SDL_Texture *tex8 = NULL;
SDL_Texture *tex9 = NULL;
SDL_Texture *tex10 = NULL;
SDL_Texture *tex11 = NULL;
SDL_Texture *tex12 = NULL;
SDL_Texture *tex13 = NULL;
SDL_Texture *tex14 = NULL;
SDL_Texture *tex15 = NULL;
SDL_Texture *tex16 = NULL;


tex1 = SDL_CreateTextureFromSurface(gRenderer, bitmap1);
tex2 = SDL_CreateTextureFromSurface(gRenderer, bitmap2);
tex3 = SDL_CreateTextureFromSurface(gRenderer, bitmap3);
tex4 = SDL_CreateTextureFromSurface(gRenderer, bitmap4);
tex5 = SDL_CreateTextureFromSurface(gRenderer, bitmap5);
tex6 = SDL_CreateTextureFromSurface(gRenderer, bitmap6);
tex7 = SDL_CreateTextureFromSurface(gRenderer, bitmap7);
tex8 = SDL_CreateTextureFromSurface(gRenderer, bitmap8);
tex9 = SDL_CreateTextureFromSurface(gRenderer, bitmap9);
tex10 = SDL_CreateTextureFromSurface(gRenderer, bitmap10);
tex11 = SDL_CreateTextureFromSurface(gRenderer, bitmap11);
tex12 = SDL_CreateTextureFromSurface(gRenderer, bitmap12);
tex13 = SDL_CreateTextureFromSurface(gRenderer, bitmap13);
tex14 = SDL_CreateTextureFromSurface(gRenderer, bitmap14);
tex15 = SDL_CreateTextureFromSurface(gRenderer, bitmap15);
tex16 = SDL_CreateTextureFromSurface(gRenderer, bitmap16);
    map_texture = SDL_CreateTexture(renderer,SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, LEVEL_WIDTH, LEVEL_HEIGHT);
    SDL_SetRenderTarget(renderer, map_texture);
    int i, j;

    for (i = 0; i < LEVEL_HEIGHT / TILE_SIZE; i++) {
        for (j = 0; j < LEVEL_WIDTH / TILE_SIZE; j++) {
            if (map[i][j]== PATH) {
                rectangle_.x = TILE_SIZE * j;
                rectangle_.y = TILE_SIZE * i;
                SDL_RenderCopy(renderer, tex3, NULL, &rectangle_);
                
            }else if(map[i][j]==HOSTEL_FRONT){
                rectangle_.x = TILE_SIZE * j;
                rectangle_.y = TILE_SIZE * i;
                SDL_RenderCopy(renderer, tex4, NULL, &rectangle_);

            }else if(map[i][j]==LAWN){
                rectangle_.x = TILE_SIZE * j;
                rectangle_.y = TILE_SIZE * i;
                SDL_RenderCopy(renderer, tex7, NULL, &rectangle_);

            }else if(map[i][j]==BOUNDARY){
                rectangle_.x = TILE_SIZE * j;
                rectangle_.y = TILE_SIZE * i;
                SDL_RenderCopy(renderer, tex5, NULL, &rectangle_);

            }else if(map[i][j]==GROUND){
                rectangle_.x = TILE_SIZE * j;
                rectangle_.y = TILE_SIZE * i;
                SDL_RenderCopy(renderer, tex6, NULL, &rectangle_);

            }else{
                rectangle_.x = TILE_SIZE * j;
                rectangle_.y = TILE_SIZE * i;
                SDL_RenderCopy(renderer, tex14, NULL, &rectangle_);

            }
        }
    }
    SDL_SetRenderTarget(renderer, NULL);
    return map_texture;
}

SDL_Texture* get_mapLHC_texture(SDL_Renderer *renderer) {
    int map_flat[MAPLHC_WIDTH*MAPLHC_HEIGHT] = MAPLHC;

    int map[MAPLHC_HEIGHT][MAPLHC_WIDTH];
    int id=0;
    for(int i=0;i<MAPLHC_HEIGHT;++i){
        for(int j=0;j<MAPLHC_WIDTH;++j){
            map[i][j]=map_flat[id];
            ++id;
        }
    }

SDL_Surface *bitmap1 = NULL;
SDL_Surface *bitmap2 = NULL;
SDL_Surface *bitmap3 = NULL;
SDL_Surface *bitmap4 = NULL;
SDL_Surface *bitmap5 = NULL;
SDL_Surface *bitmap6 = NULL;
SDL_Surface *bitmap7 = NULL;
SDL_Surface *bitmap8 = NULL;
SDL_Surface *bitmap9 = NULL;
SDL_Surface *bitmap10 = NULL;
SDL_Surface *bitmap11 = NULL;
SDL_Surface *bitmap12 = NULL;
SDL_Surface *bitmap13 = NULL;
SDL_Surface *bitmap14 = NULL;
SDL_Surface *bitmap15 = NULL;
SDL_Surface *bitmap16 = NULL;

SDL_Texture *map_texture;

SDL_Rect rectangle_;
rectangle_.w = TILE_SIZE;
rectangle_.h = TILE_SIZE;

bitmap1 = SDL_LoadBMP("res/tile.bmp");
bitmap2 = SDL_LoadBMP("res/LHC.bmp");
bitmap3 = SDL_LoadBMP("res/deathpool.bmp");
bitmap4 = SDL_LoadBMP("res/hostelfront.bmp");
bitmap5 = SDL_LoadBMP("res/boundary.bmp");
bitmap6 = SDL_LoadBMP("res/mainpath.bmp");
bitmap7 = SDL_LoadBMP("res/lawn.bmp");
bitmap8 = SDL_LoadBMP("res/must.bmp");
bitmap9 = SDL_LoadBMP("res/pink.bmp");
bitmap10 = SDL_LoadBMP("res/shine.bmp");
bitmap11 = SDL_LoadBMP("res/skull.bmp");
bitmap12 = SDL_LoadBMP("res/moon_tile.bmp");
bitmap13 = SDL_LoadBMP("res/brown.bmp");
bitmap14 = SDL_LoadBMP("res/red_spots.bmp");
bitmap15 = SDL_LoadBMP("res/stone.bmp");
bitmap16 = SDL_LoadBMP("res/doll_tile.bmp");

SDL_Texture *tex1 = NULL;
SDL_Texture *tex2 = NULL;
SDL_Texture *tex3 = NULL;
SDL_Texture *tex4 = NULL;
SDL_Texture *tex5 = NULL;
SDL_Texture *tex6 = NULL;
SDL_Texture *tex7 = NULL;
SDL_Texture *tex8 = NULL;
SDL_Texture *tex9 = NULL;
SDL_Texture *tex10 = NULL;
SDL_Texture *tex11 = NULL;
SDL_Texture *tex12 = NULL;
SDL_Texture *tex13 = NULL;
SDL_Texture *tex14 = NULL;
SDL_Texture *tex15 = NULL;
SDL_Texture *tex16 = NULL;


tex1 = SDL_CreateTextureFromSurface(gRenderer, bitmap1);
tex2 = SDL_CreateTextureFromSurface(gRenderer, bitmap2);
tex3 = SDL_CreateTextureFromSurface(gRenderer, bitmap3);
tex4 = SDL_CreateTextureFromSurface(gRenderer, bitmap4);
tex5 = SDL_CreateTextureFromSurface(gRenderer, bitmap5);
tex6 = SDL_CreateTextureFromSurface(gRenderer, bitmap6);
tex7 = SDL_CreateTextureFromSurface(gRenderer, bitmap7);
tex8 = SDL_CreateTextureFromSurface(gRenderer, bitmap8);
tex9 = SDL_CreateTextureFromSurface(gRenderer, bitmap9);
tex10 = SDL_CreateTextureFromSurface(gRenderer, bitmap10);
tex11 = SDL_CreateTextureFromSurface(gRenderer, bitmap11);
tex12 = SDL_CreateTextureFromSurface(gRenderer, bitmap12);
tex13 = SDL_CreateTextureFromSurface(gRenderer, bitmap13);
tex14 = SDL_CreateTextureFromSurface(gRenderer, bitmap14);
tex15 = SDL_CreateTextureFromSurface(gRenderer, bitmap15);
tex16 = SDL_CreateTextureFromSurface(gRenderer, bitmap16);
    map_texture = SDL_CreateTexture(renderer,SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, SCREEN_WIDTH, SCREEN_HEIGHT);
    SDL_SetRenderTarget(renderer, map_texture);
    int i, j;

    for (i = 0; i < SCREEN_HEIGHT / TILE_SIZE; i++) {
        for (j = 0; j < SCREEN_WIDTH / TILE_SIZE; j++) {
            if (map[i][j]== DIAMOND) {
                rectangle_.x = TILE_SIZE * j;
                rectangle_.y = TILE_SIZE * i;
                SDL_RenderCopy(renderer, tex10, NULL, &rectangle_);
                
            }else if(map[i][j]==PATH_LHC){
                rectangle_.x = TILE_SIZE * j;
                rectangle_.y = TILE_SIZE * i;
                SDL_RenderCopy(renderer, tex6, NULL, &rectangle_);

            }else if(map[i][j]==ENTRY_EXIT_LHC){
                rectangle_.x = TILE_SIZE * j;
                rectangle_.y = TILE_SIZE * i;
                SDL_RenderCopy(renderer, tex15, NULL, &rectangle_);

            }else if(map[i][j]==BOUNDARY_LHC){
                rectangle_.x = TILE_SIZE * j;
                rectangle_.y = TILE_SIZE * i;
                SDL_RenderCopy(renderer, tex14, NULL, &rectangle_);

            }else if(map[i][j]==ROOMS_LHC){
                rectangle_.x = TILE_SIZE * j;
                rectangle_.y = TILE_SIZE * i;
                SDL_RenderCopy(renderer, tex4, NULL, &rectangle_);

            }else if(map[i][j] == OBSTACLES_LHC){
                rectangle_.x = TILE_SIZE * j;
                rectangle_.y = TILE_SIZE * i;
                SDL_RenderCopy(renderer, tex16, NULL, &rectangle_);

            }
        }
    }
    SDL_SetRenderTarget(renderer, NULL);
    return map_texture;
}

SDL_Texture* get_mapStaffCanteen_texture(SDL_Renderer *renderer) {
    int map_flat[MAPSTAFF_WIDTH*MAPSTAFF_HEIGHT] = MAPSTAFFCANTEEN;

    int map[MAPSTAFF_HEIGHT][MAPSTAFF_WIDTH];
    int id=0;
    for(int i=0;i<MAPSTAFF_HEIGHT;++i){
        for(int j=0;j<MAPSTAFF_WIDTH;++j){
            map[i][j]=map_flat[id];
            ++id;
        }
    }
SDL_Surface *bitmap1 = NULL;
SDL_Surface *bitmap2 = NULL;
SDL_Surface *bitmap3 = NULL;
SDL_Surface *bitmap4 = NULL;
SDL_Surface *bitmap5 = NULL;
SDL_Surface *bitmap6 = NULL;
SDL_Surface *bitmap7 = NULL;
SDL_Surface *bitmap8 = NULL;
SDL_Surface *bitmap9 = NULL;
SDL_Surface *bitmap10 = NULL;
SDL_Surface *bitmap11 = NULL;
SDL_Surface *bitmap12 = NULL;
SDL_Surface *bitmap13 = NULL;
SDL_Surface *bitmap14 = NULL;
SDL_Surface *bitmap15 = NULL;
SDL_Surface *bitmap16 = NULL;

SDL_Texture *map_texture;

SDL_Rect rectangle_;
rectangle_.w = TILE_SIZE;
rectangle_.h = TILE_SIZE;

bitmap1 = SDL_LoadBMP("res/tile.bmp");
bitmap2 = SDL_LoadBMP("res/LHC.bmp");
bitmap3 = SDL_LoadBMP("res/deathpool.bmp");
bitmap4 = SDL_LoadBMP("res/hostelfront.bmp");
bitmap5 = SDL_LoadBMP("res/boundary.bmp");
bitmap6 = SDL_LoadBMP("res/mainpath.bmp");
bitmap7 = SDL_LoadBMP("res/lawn.bmp");
bitmap8 = SDL_LoadBMP("res/must.bmp");
bitmap9 = SDL_LoadBMP("res/pink.bmp");
bitmap10 = SDL_LoadBMP("res/shine.bmp");
bitmap11 = SDL_LoadBMP("res/skull.bmp");
bitmap12 = SDL_LoadBMP("res/moon_tile.bmp");
bitmap13 = SDL_LoadBMP("res/brown.bmp");
bitmap14 = SDL_LoadBMP("res/red_spots.bmp");
bitmap15 = SDL_LoadBMP("res/stone.bmp");
bitmap16 = SDL_LoadBMP("res/doll_tile.bmp");

SDL_Texture *tex1 = NULL;
SDL_Texture *tex2 = NULL;
SDL_Texture *tex3 = NULL;
SDL_Texture *tex4 = NULL;
SDL_Texture *tex5 = NULL;
SDL_Texture *tex6 = NULL;
SDL_Texture *tex7 = NULL;
SDL_Texture *tex8 = NULL;
SDL_Texture *tex9 = NULL;
SDL_Texture *tex10 = NULL;
SDL_Texture *tex11 = NULL;
SDL_Texture *tex12 = NULL;
SDL_Texture *tex13 = NULL;
SDL_Texture *tex14 = NULL;
SDL_Texture *tex15 = NULL;
SDL_Texture *tex16 = NULL;


tex1 = SDL_CreateTextureFromSurface(gRenderer, bitmap1);
tex2 = SDL_CreateTextureFromSurface(gRenderer, bitmap2);
tex3 = SDL_CreateTextureFromSurface(gRenderer, bitmap3);
tex4 = SDL_CreateTextureFromSurface(gRenderer, bitmap4);
tex5 = SDL_CreateTextureFromSurface(gRenderer, bitmap5);
tex6 = SDL_CreateTextureFromSurface(gRenderer, bitmap6);
tex7 = SDL_CreateTextureFromSurface(gRenderer, bitmap7);
tex8 = SDL_CreateTextureFromSurface(gRenderer, bitmap8);
tex9 = SDL_CreateTextureFromSurface(gRenderer, bitmap9);
tex10 = SDL_CreateTextureFromSurface(gRenderer, bitmap10);
tex11 = SDL_CreateTextureFromSurface(gRenderer, bitmap11);
tex12 = SDL_CreateTextureFromSurface(gRenderer, bitmap12);
tex13 = SDL_CreateTextureFromSurface(gRenderer, bitmap13);
tex14 = SDL_CreateTextureFromSurface(gRenderer, bitmap14);
tex15 = SDL_CreateTextureFromSurface(gRenderer, bitmap15);
tex16 = SDL_CreateTextureFromSurface(gRenderer, bitmap16);
    map_texture = SDL_CreateTexture(renderer,SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, SCREEN_WIDTH, SCREEN_HEIGHT);
    SDL_SetRenderTarget(renderer, map_texture);
    int i, j;

    for (i = 0; i < SCREEN_HEIGHT / TILE_SIZE; i++) {
        for (j = 0; j < SCREEN_WIDTH / TILE_SIZE; j++) {
            if(map[i][j]==PATH_CANTEEN){
                rectangle_.x = TILE_SIZE * j;
                rectangle_.y = TILE_SIZE * i;
                SDL_RenderCopy(renderer, tex6, NULL, &rectangle_);

            }else if(map[i][j]==ENTRY_EXIT_CANTEEN){
                rectangle_.x = TILE_SIZE * j;
                rectangle_.y = TILE_SIZE * i;
                SDL_RenderCopy(renderer, tex15, NULL, &rectangle_);

            }else if(map[i][j]==BOUNDARY_CANTEEN){
                rectangle_.x = TILE_SIZE * j;
                rectangle_.y = TILE_SIZE * i;
                SDL_RenderCopy(renderer, tex14, NULL, &rectangle_);

            }else if(map[i][j]==SHOPS_CANTEEN){
                rectangle_.x = TILE_SIZE * j;
                rectangle_.y = TILE_SIZE * i;
                SDL_RenderCopy(renderer, tex4, NULL, &rectangle_);

            }else if(map[i][j] == OBSTACLES_CANTEEN){
                rectangle_.x = TILE_SIZE * j;
                rectangle_.y = TILE_SIZE * i;
                SDL_RenderCopy(renderer, tex16, NULL, &rectangle_);

            }else if(map[i][j] == CHAIRS_CANTEEN){
                rectangle_.x = TILE_SIZE * j;
                rectangle_.y = TILE_SIZE * i;
                SDL_RenderCopy(renderer, tex13, NULL, &rectangle_);

            }
        }
    }
    SDL_SetRenderTarget(renderer, NULL);
    return map_texture;
}

SDL_Texture* get_mapHostel_texture(SDL_Renderer *renderer) {
    int map_flat[MAPHOSTEL_WIDTH*MAPHOSTEL_HEIGHT] = MAPHOSTEL;

    int map[MAPLHC_HEIGHT][MAPLHC_WIDTH];
    int id=0;
    for(int i=0;i<MAPLHC_HEIGHT;++i){
        for(int j=0;j<MAPLHC_WIDTH;++j){
            map[i][j]=map_flat[id];
            ++id;
        }
    }
SDL_Surface *bitmap1 = NULL;
SDL_Surface *bitmap2 = NULL;
SDL_Surface *bitmap3 = NULL;
SDL_Surface *bitmap4 = NULL;
SDL_Surface *bitmap5 = NULL;
SDL_Surface *bitmap6 = NULL;
SDL_Surface *bitmap7 = NULL;
SDL_Surface *bitmap8 = NULL;
SDL_Surface *bitmap9 = NULL;
SDL_Surface *bitmap10 = NULL;
SDL_Surface *bitmap11 = NULL;
SDL_Surface *bitmap12 = NULL;
SDL_Surface *bitmap13 = NULL;
SDL_Surface *bitmap14 = NULL;
SDL_Surface *bitmap15 = NULL;
SDL_Surface *bitmap16 = NULL;

SDL_Texture *map_texture;

SDL_Rect rectangle_;
rectangle_.w = TILE_SIZE;
rectangle_.h = TILE_SIZE;

bitmap1 = SDL_LoadBMP("res/tile.bmp");
bitmap2 = SDL_LoadBMP("res/LHC.bmp");
bitmap3 = SDL_LoadBMP("res/deathpool.bmp");
bitmap4 = SDL_LoadBMP("res/hostelfront.bmp");
bitmap5 = SDL_LoadBMP("res/boundary.bmp");
bitmap6 = SDL_LoadBMP("res/mainpath.bmp");
bitmap7 = SDL_LoadBMP("res/lawn.bmp");
bitmap8 = SDL_LoadBMP("res/must.bmp");
bitmap9 = SDL_LoadBMP("res/pink.bmp");
bitmap10 = SDL_LoadBMP("res/shine.bmp");
bitmap11 = SDL_LoadBMP("res/skull.bmp");
bitmap12 = SDL_LoadBMP("res/moon_tile.bmp");
bitmap13 = SDL_LoadBMP("res/brown.bmp");
bitmap14 = SDL_LoadBMP("res/red_spots.bmp");
bitmap15 = SDL_LoadBMP("res/stone.bmp");
bitmap16 = SDL_LoadBMP("res/doll_tile.bmp");

SDL_Texture *tex1 = NULL;
SDL_Texture *tex2 = NULL;
SDL_Texture *tex3 = NULL;
SDL_Texture *tex4 = NULL;
SDL_Texture *tex5 = NULL;
SDL_Texture *tex6 = NULL;
SDL_Texture *tex7 = NULL;
SDL_Texture *tex8 = NULL;
SDL_Texture *tex9 = NULL;
SDL_Texture *tex10 = NULL;
SDL_Texture *tex11 = NULL;
SDL_Texture *tex12 = NULL;
SDL_Texture *tex13 = NULL;
SDL_Texture *tex14 = NULL;
SDL_Texture *tex15 = NULL;
SDL_Texture *tex16 = NULL;


tex1 = SDL_CreateTextureFromSurface(gRenderer, bitmap1);
tex2 = SDL_CreateTextureFromSurface(gRenderer, bitmap2);
tex3 = SDL_CreateTextureFromSurface(gRenderer, bitmap3);
tex4 = SDL_CreateTextureFromSurface(gRenderer, bitmap4);
tex5 = SDL_CreateTextureFromSurface(gRenderer, bitmap5);
tex6 = SDL_CreateTextureFromSurface(gRenderer, bitmap6);
tex7 = SDL_CreateTextureFromSurface(gRenderer, bitmap7);
tex8 = SDL_CreateTextureFromSurface(gRenderer, bitmap8);
tex9 = SDL_CreateTextureFromSurface(gRenderer, bitmap9);
tex10 = SDL_CreateTextureFromSurface(gRenderer, bitmap10);
tex11 = SDL_CreateTextureFromSurface(gRenderer, bitmap11);
tex12 = SDL_CreateTextureFromSurface(gRenderer, bitmap12);
tex13 = SDL_CreateTextureFromSurface(gRenderer, bitmap13);
tex14 = SDL_CreateTextureFromSurface(gRenderer, bitmap14);
tex15 = SDL_CreateTextureFromSurface(gRenderer, bitmap15);
tex16 = SDL_CreateTextureFromSurface(gRenderer, bitmap16);
    map_texture = SDL_CreateTexture(renderer,SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, SCREEN_WIDTH, SCREEN_HEIGHT);
    SDL_SetRenderTarget(renderer, map_texture);
    int i, j;

    for (i = 0; i < SCREEN_HEIGHT / TILE_SIZE; i++) {
        for (j = 0; j < SCREEN_WIDTH / TILE_SIZE; j++) {
            if(map[i][j]==PATH_HOSTEL){
                rectangle_.x = TILE_SIZE * j;
                rectangle_.y = TILE_SIZE * i;
                SDL_RenderCopy(renderer, tex6, NULL, &rectangle_);

            }else if(map[i][j]==ENTRY_EXIT_HOSTEL){
                rectangle_.x = TILE_SIZE * j;
                rectangle_.y = TILE_SIZE * i;
                SDL_RenderCopy(renderer, tex15, NULL, &rectangle_);

            }else if(map[i][j]==BOUNDARY_HOSTEL){
                rectangle_.x = TILE_SIZE * j;
                rectangle_.y = TILE_SIZE * i;
                SDL_RenderCopy(renderer, tex14, NULL, &rectangle_);

            }else if(map[i][j]==ROOMS_HOSTEL){
                rectangle_.x = TILE_SIZE * j;
                rectangle_.y = TILE_SIZE * i;
                SDL_RenderCopy(renderer, tex4, NULL, &rectangle_);

            }else if(map[i][j] == LOBBY_HOSTEL){
                rectangle_.x = TILE_SIZE * j;
                rectangle_.y = TILE_SIZE * i;
                SDL_RenderCopy(renderer, tex8, NULL, &rectangle_);

            }else if(map[i][j] == COURT_HOSTEL){
                rectangle_.x = TILE_SIZE * j;
                rectangle_.y = TILE_SIZE * i;
                SDL_RenderCopy(renderer, tex10, NULL, &rectangle_);

            }
        }
    }
    SDL_SetRenderTarget(renderer, NULL);
    return map_texture;
}

SDL_Texture* get_mapScoops_texture(SDL_Renderer *renderer) {
    int map_flat[MAPSCOOPS_WIDTH*MAPSCOOPS_HEIGHT] = MAPSCOOPS;

    int map[MAPSCOOPS_HEIGHT][MAPSCOOPS_WIDTH];
    int id=0;
    for(int i=0;i<MAPSCOOPS_HEIGHT;++i){
        for(int j=0;j<MAPSCOOPS_WIDTH;++j){
            map[i][j]=map_flat[id];
            ++id;
        }
    }
SDL_Surface *bitmap1 = NULL;
SDL_Surface *bitmap2 = NULL;
SDL_Surface *bitmap3 = NULL;
SDL_Surface *bitmap4 = NULL;
SDL_Surface *bitmap5 = NULL;
SDL_Surface *bitmap6 = NULL;
SDL_Surface *bitmap7 = NULL;
SDL_Surface *bitmap8 = NULL;
SDL_Surface *bitmap9 = NULL;
SDL_Surface *bitmap10 = NULL;
SDL_Surface *bitmap11 = NULL;
SDL_Surface *bitmap12 = NULL;
SDL_Surface *bitmap13 = NULL;
SDL_Surface *bitmap14 = NULL;
SDL_Surface *bitmap15 = NULL;
SDL_Surface *bitmap16 = NULL;

SDL_Texture *map_texture;

SDL_Rect rectangle_;
rectangle_.w = TILE_SIZE;
rectangle_.h = TILE_SIZE;

bitmap1 = SDL_LoadBMP("res/tile.bmp");
bitmap2 = SDL_LoadBMP("res/LHC.bmp");
bitmap3 = SDL_LoadBMP("res/deathpool.bmp");
bitmap4 = SDL_LoadBMP("res/hostelfront.bmp");
bitmap5 = SDL_LoadBMP("res/boundary.bmp");
bitmap6 = SDL_LoadBMP("res/mainpath.bmp");
bitmap7 = SDL_LoadBMP("res/lawn.bmp");
bitmap8 = SDL_LoadBMP("res/must.bmp");
bitmap9 = SDL_LoadBMP("res/pink.bmp");
bitmap10 = SDL_LoadBMP("res/shine.bmp");
bitmap11 = SDL_LoadBMP("res/skull.bmp");
bitmap12 = SDL_LoadBMP("res/moon_tile.bmp");
bitmap13 = SDL_LoadBMP("res/brown.bmp");
bitmap14 = SDL_LoadBMP("res/red_spots.bmp");
bitmap15 = SDL_LoadBMP("res/stone.bmp");
bitmap16 = SDL_LoadBMP("res/doll_tile.bmp");

SDL_Texture *tex1 = NULL;
SDL_Texture *tex2 = NULL;
SDL_Texture *tex3 = NULL;
SDL_Texture *tex4 = NULL;
SDL_Texture *tex5 = NULL;
SDL_Texture *tex6 = NULL;
SDL_Texture *tex7 = NULL;
SDL_Texture *tex8 = NULL;
SDL_Texture *tex9 = NULL;
SDL_Texture *tex10 = NULL;
SDL_Texture *tex11 = NULL;
SDL_Texture *tex12 = NULL;
SDL_Texture *tex13 = NULL;
SDL_Texture *tex14 = NULL;
SDL_Texture *tex15 = NULL;
SDL_Texture *tex16 = NULL;


tex1 = SDL_CreateTextureFromSurface(gRenderer, bitmap1);
tex2 = SDL_CreateTextureFromSurface(gRenderer, bitmap2);
tex3 = SDL_CreateTextureFromSurface(gRenderer, bitmap3);
tex4 = SDL_CreateTextureFromSurface(gRenderer, bitmap4);
tex5 = SDL_CreateTextureFromSurface(gRenderer, bitmap5);
tex6 = SDL_CreateTextureFromSurface(gRenderer, bitmap6);
tex7 = SDL_CreateTextureFromSurface(gRenderer, bitmap7);
tex8 = SDL_CreateTextureFromSurface(gRenderer, bitmap8);
tex9 = SDL_CreateTextureFromSurface(gRenderer, bitmap9);
tex10 = SDL_CreateTextureFromSurface(gRenderer, bitmap10);
tex11 = SDL_CreateTextureFromSurface(gRenderer, bitmap11);
tex12 = SDL_CreateTextureFromSurface(gRenderer, bitmap12);
tex13 = SDL_CreateTextureFromSurface(gRenderer, bitmap13);
tex14 = SDL_CreateTextureFromSurface(gRenderer, bitmap14);
tex15 = SDL_CreateTextureFromSurface(gRenderer, bitmap15);
tex16 = SDL_CreateTextureFromSurface(gRenderer, bitmap16);
    map_texture = SDL_CreateTexture(renderer,SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, SCREEN_WIDTH, SCREEN_HEIGHT);
    SDL_SetRenderTarget(renderer, map_texture);
    int i, j;

    for (i = 0; i < SCREEN_HEIGHT / TILE_SIZE; i++) {
        for (j = 0; j < SCREEN_WIDTH / TILE_SIZE; j++) {
            if(map[i][j]==PATH_SCOOPS){
                rectangle_.x = TILE_SIZE * j;
                rectangle_.y = TILE_SIZE * i;
                SDL_RenderCopy(renderer, tex6, NULL, &rectangle_);

            }else if(map[i][j]==ENTRY_EXIT_SCOOPS){
                rectangle_.x = TILE_SIZE * j;
                rectangle_.y = TILE_SIZE * i;
                SDL_RenderCopy(renderer, tex15, NULL, &rectangle_);

            }else if(map[i][j]==BOUNDARY_SCOOPS){
                rectangle_.x = TILE_SIZE * j;
                rectangle_.y = TILE_SIZE * i;
                SDL_RenderCopy(renderer, tex14, NULL, &rectangle_);

            }else if(map[i][j]==SHELVES_SCOOPS){
                rectangle_.x = TILE_SIZE * j;
                rectangle_.y = TILE_SIZE * i;
                SDL_RenderCopy(renderer, tex4, NULL, &rectangle_);

            }else if(map[i][j] == DESK_SCOOPS){
                rectangle_.x = TILE_SIZE * j;
                rectangle_.y = TILE_SIZE * i;
                SDL_RenderCopy(renderer, tex8, NULL, &rectangle_);

            }else if(map[i][j] == OBSTACLES_SCOOPS){
                rectangle_.x = TILE_SIZE * j;
                rectangle_.y = TILE_SIZE * i;
                SDL_RenderCopy(renderer, tex16, NULL, &rectangle_);

            }
        }
    }
    SDL_SetRenderTarget(renderer, NULL);
    return map_texture;
}

SDL_Texture* get_mapLibrary_texture(SDL_Renderer *renderer) {
    int map_flat[MAPLIBRARY_WIDTH*MAPLIBRARY_HEIGHT] = MAPLIBRARY;

    int map[MAPLIBRARY_HEIGHT][MAPLIBRARY_WIDTH];
    int id=0;
    for(int i=0;i<MAPLIBRARY_HEIGHT;++i){
        for(int j=0;j<MAPLIBRARY_WIDTH;++j){
            map[i][j]=map_flat[id];
            ++id;
        }
    }
SDL_Surface *bitmap1 = NULL;
SDL_Surface *bitmap2 = NULL;
SDL_Surface *bitmap3 = NULL;
SDL_Surface *bitmap4 = NULL;
SDL_Surface *bitmap5 = NULL;
SDL_Surface *bitmap6 = NULL;
SDL_Surface *bitmap7 = NULL;
SDL_Surface *bitmap8 = NULL;
SDL_Surface *bitmap9 = NULL;
SDL_Surface *bitmap10 = NULL;
SDL_Surface *bitmap11 = NULL;
SDL_Surface *bitmap12 = NULL;
SDL_Surface *bitmap13 = NULL;
SDL_Surface *bitmap14 = NULL;
SDL_Surface *bitmap15 = NULL;
SDL_Surface *bitmap16 = NULL;

SDL_Texture *map_texture;

SDL_Rect rectangle_;
rectangle_.w = TILE_SIZE;
rectangle_.h = TILE_SIZE;

bitmap1 = SDL_LoadBMP("res/tile.bmp");
bitmap2 = SDL_LoadBMP("res/LHC.bmp");
bitmap3 = SDL_LoadBMP("res/deathpool.bmp");
bitmap4 = SDL_LoadBMP("res/hostelfront.bmp");
bitmap5 = SDL_LoadBMP("res/boundary.bmp");
bitmap6 = SDL_LoadBMP("res/mainpath.bmp");
bitmap7 = SDL_LoadBMP("res/lawn.bmp");
bitmap8 = SDL_LoadBMP("res/must.bmp");
bitmap9 = SDL_LoadBMP("res/pink.bmp");
bitmap10 = SDL_LoadBMP("res/shine.bmp");
bitmap11 = SDL_LoadBMP("res/skull.bmp");
bitmap12 = SDL_LoadBMP("res/moon_tile.bmp");
bitmap13 = SDL_LoadBMP("res/brown.bmp");
bitmap14 = SDL_LoadBMP("res/red_spots.bmp");
bitmap15 = SDL_LoadBMP("res/stone.bmp");
bitmap16 = SDL_LoadBMP("res/doll_tile.bmp");

SDL_Texture *tex1 = NULL;
SDL_Texture *tex2 = NULL;
SDL_Texture *tex3 = NULL;
SDL_Texture *tex4 = NULL;
SDL_Texture *tex5 = NULL;
SDL_Texture *tex6 = NULL;
SDL_Texture *tex7 = NULL;
SDL_Texture *tex8 = NULL;
SDL_Texture *tex9 = NULL;
SDL_Texture *tex10 = NULL;
SDL_Texture *tex11 = NULL;
SDL_Texture *tex12 = NULL;
SDL_Texture *tex13 = NULL;
SDL_Texture *tex14 = NULL;
SDL_Texture *tex15 = NULL;
SDL_Texture *tex16 = NULL;


tex1 = SDL_CreateTextureFromSurface(gRenderer, bitmap1);
tex2 = SDL_CreateTextureFromSurface(gRenderer, bitmap2);
tex3 = SDL_CreateTextureFromSurface(gRenderer, bitmap3);
tex4 = SDL_CreateTextureFromSurface(gRenderer, bitmap4);
tex5 = SDL_CreateTextureFromSurface(gRenderer, bitmap5);
tex6 = SDL_CreateTextureFromSurface(gRenderer, bitmap6);
tex7 = SDL_CreateTextureFromSurface(gRenderer, bitmap7);
tex8 = SDL_CreateTextureFromSurface(gRenderer, bitmap8);
tex9 = SDL_CreateTextureFromSurface(gRenderer, bitmap9);
tex10 = SDL_CreateTextureFromSurface(gRenderer, bitmap10);
tex11 = SDL_CreateTextureFromSurface(gRenderer, bitmap11);
tex12 = SDL_CreateTextureFromSurface(gRenderer, bitmap12);
tex13 = SDL_CreateTextureFromSurface(gRenderer, bitmap13);
tex14 = SDL_CreateTextureFromSurface(gRenderer, bitmap14);
tex15 = SDL_CreateTextureFromSurface(gRenderer, bitmap15);
tex16 = SDL_CreateTextureFromSurface(gRenderer, bitmap16);
    map_texture = SDL_CreateTexture(renderer,SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, SCREEN_WIDTH, SCREEN_HEIGHT);
    SDL_SetRenderTarget(renderer, map_texture);
    int i, j;

    for (i = 0; i < SCREEN_HEIGHT / TILE_SIZE; i++) {
        for (j = 0; j < SCREEN_WIDTH / TILE_SIZE; j++) {
            if(map[i][j]==PATH_LIB){
                rectangle_.x = TILE_SIZE * j;
                rectangle_.y = TILE_SIZE * i;
                SDL_RenderCopy(renderer, tex6, NULL, &rectangle_);

            }else if(map[i][j]==ENTRY_EXIT_LIB){
                rectangle_.x = TILE_SIZE * j;
                rectangle_.y = TILE_SIZE * i;
                SDL_RenderCopy(renderer, tex15, NULL, &rectangle_);

            }else if(map[i][j]==BOUNDARY_LIB){
                rectangle_.x = TILE_SIZE * j;
                rectangle_.y = TILE_SIZE * i;
                SDL_RenderCopy(renderer, tex14, NULL, &rectangle_);

            }else if(map[i][j]==SHELVES_LIB){
                rectangle_.x = TILE_SIZE * j;
                rectangle_.y = TILE_SIZE * i;
                SDL_RenderCopy(renderer, tex4, NULL, &rectangle_);

            }else if(map[i][j] == TABLE_LIB){
                rectangle_.x = TILE_SIZE * j;
                rectangle_.y = TILE_SIZE * i;
                SDL_RenderCopy(renderer, tex8, NULL, &rectangle_);

            }else if(map[i][j] == OBSTACLES_LIB){
                rectangle_.x = TILE_SIZE * j;
                rectangle_.y = TILE_SIZE * i;
                SDL_RenderCopy(renderer, tex16, NULL, &rectangle_);

            }
        }
    }
    SDL_SetRenderTarget(renderer, NULL);
    return map_texture;
}

void save_texture(SDL_Renderer *ren, SDL_Texture *tex, const char *filename)
{
    SDL_Texture *ren_tex;
    SDL_Surface *surf;
    int st;
    int w;
    int h;
    int format;
    void *pixels;

    pixels  = NULL;
    surf    = NULL;
    ren_tex = NULL;
    format  = SDL_PIXELFORMAT_RGBA32;

    /* Get information about texture we want to save */
    st = SDL_QueryTexture(tex, NULL, NULL, &w, &h);
    if (st != 0) {
        SDL_Log("Failed querying texture: %s\n", SDL_GetError());
        goto cleanup;
    }

    ren_tex = SDL_CreateTexture(ren, format, SDL_TEXTUREACCESS_TARGET, w, h);
    if (!ren_tex) {
        SDL_Log("Failed creating render texture: %s\n", SDL_GetError());
        goto cleanup;
    }

    /*
     * Initialize our canvas, then copy texture to a target whose pixel data we 
     * can access
     */
    st = SDL_SetRenderTarget(ren, ren_tex);
    if (st != 0) {
        SDL_Log("Failed setting render target: %s\n", SDL_GetError());
        goto cleanup;
    }

    SDL_SetRenderDrawColor(ren, 0x00, 0x00, 0x00, 0x00);
    SDL_RenderClear(ren);

    st = SDL_RenderCopy(ren, tex, NULL, NULL);
    if (st != 0) {
        SDL_Log("Failed copying texture data: %s\n", SDL_GetError());
        goto cleanup;
    }

    /* Create buffer to hold texture data and load it */
    pixels = malloc(w * h * SDL_BYTESPERPIXEL(format));
    if (!pixels) {
        SDL_Log("Failed allocating memory\n");
        goto cleanup;
    }

    st = SDL_RenderReadPixels(ren, NULL, format, pixels, w * SDL_BYTESPERPIXEL(format));
    if (st != 0) {
        SDL_Log("Failed reading pixel data: %s\n", SDL_GetError());
        goto cleanup;
    }

    /* Copy pixel data over to surface */
    surf = SDL_CreateRGBSurfaceWithFormatFrom(pixels, w, h, SDL_BITSPERPIXEL(format), w * SDL_BYTESPERPIXEL(format), format);
    if (!surf) {
        SDL_Log("Failed creating new surface: %s\n", SDL_GetError());
        goto cleanup;
    }

    /* Save result to an image */
    st = IMG_SavePNG(surf, filename);
    if (st != 0) {
        SDL_Log("Failed saving image: %s\n", SDL_GetError());
        goto cleanup;
    }

cleanup:
    SDL_FreeSurface(surf);
    free(pixels);
    SDL_DestroyTexture(ren_tex);
}
