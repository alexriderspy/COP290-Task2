#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include <iostream>
#include <string>
#include <sstream>

#include <map.hpp>
#include <player.hpp>
#include <constants.hpp>

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
    SDL_Texture *map_texture;
    SDL_Rect rect;
    rect.w = TILE_SIZE;
    rect.h = TILE_SIZE;
    bitmap1 = SDL_LoadBMP("res/tile.bmp");
    bitmap2 = SDL_LoadBMP("res/LHC.bmp");
    bitmap3 = SDL_LoadBMP("res/deathpool.bmp");
    bitmap4 = SDL_LoadBMP("res/hostelfront.bmp");
    bitmap5 = SDL_LoadBMP("res/boundary.bmp");
    bitmap6 = SDL_LoadBMP("res/mainpath.bmp");
    bitmap7 = SDL_LoadBMP("res/lawn.bmp");
    
    if(!bitmap3){
        std::cout<<"Helo\n";
    }
    if(!bitmap1 || !bitmap2 || !bitmap3 || !bitmap4||!bitmap5 || !bitmap6 || !bitmap7){
        std::cout<<"can't load tile"<<'\n';
    }
    // SDL_Texture *tex1 = NULL;
    // SDL_Texture *tex2 = NULL;
    SDL_Texture *tex3 = NULL;
    SDL_Texture *tex4 = NULL;
    SDL_Texture *tex5 = NULL;
    SDL_Texture *tex6 = NULL;
    SDL_Texture *tex7 = NULL;

    // tex1 = SDL_CreateTextureFromSurface(renderer, bitmap1);
    // tex2 = SDL_CreateTextureFromSurface(renderer, bitmap2);
    tex3 = SDL_CreateTextureFromSurface(renderer, bitmap3);
    tex4 = SDL_CreateTextureFromSurface(renderer, bitmap4);
    tex5 = SDL_CreateTextureFromSurface(renderer, bitmap5);
    tex6 = SDL_CreateTextureFromSurface(renderer, bitmap6);
    tex7 = SDL_CreateTextureFromSurface(renderer, bitmap7);

    map_texture = SDL_CreateTexture(renderer,SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, LEVEL_WIDTH, LEVEL_HEIGHT);
    SDL_SetRenderTarget(renderer, map_texture);
    int i, j;

    for (i = 0; i < LEVEL_HEIGHT / TILE_SIZE; i++) {
        for (j = 0; j < LEVEL_WIDTH / TILE_SIZE; j++) {
            if (map[i][j]== PATH) {
                rect.x = TILE_SIZE * j;
                rect.y = TILE_SIZE * i;
                SDL_RenderCopy(renderer, tex3, NULL, &rect);
                
            }else if(map[i][j]==HOSTEL_FRONT){
                rect.x = TILE_SIZE * j;
                rect.y = TILE_SIZE * i;
                SDL_RenderCopy(renderer, tex4, NULL, &rect);

            }else if(map[i][j]==LAWN){
                rect.x = TILE_SIZE * j;
                rect.y = TILE_SIZE * i;
                SDL_RenderCopy(renderer, tex7, NULL, &rect);

            }else if(map[i][j]==BOUNDARY){
                rect.x = TILE_SIZE * j;
                rect.y = TILE_SIZE * i;
                SDL_RenderCopy(renderer, tex5, NULL, &rect);

            }else if(map[i][j]==GROUND){
                rect.x = TILE_SIZE * j;
                rect.y = TILE_SIZE * i;
                SDL_RenderCopy(renderer, tex6, NULL, &rect);

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

    SDL_Surface *bitmap = NULL;
    SDL_Texture *map_texture;
    SDL_Rect rect;
    rect.w = TILE_SIZE;
    rect.h = TILE_SIZE;
    bitmap = SDL_LoadBMP("res/tile.bmp");
    if(!bitmap){
        std::cout<<"can't load tile"<<'\n';
    }
    SDL_Texture *tex = NULL;
    tex = SDL_CreateTextureFromSurface(renderer, bitmap);
    map_texture = SDL_CreateTexture(renderer,SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, SCREEN_WIDTH, SCREEN_HEIGHT);
    SDL_SetRenderTarget(renderer, map_texture);
    int i, j;

    for (i = 0; i < SCREEN_HEIGHT / TILE_SIZE; i++) {
        for (j = 0; j < SCREEN_WIDTH / TILE_SIZE; j++) {
            if (map[i][j]==BLOCK) {
                rect.x = TILE_SIZE * j;
                rect.y = TILE_SIZE * i;
                SDL_RenderCopy(renderer, tex, NULL, &rect);
                
            }
        }
    }
    SDL_SetRenderTarget(renderer, NULL);
    return map_texture;
}

SDL_Texture* get_mapStaffCanteen_texture(SDL_Renderer *renderer) {
    int map_flat[MAPSTAFF_WIDTH*MAPSTAFF_HEIGHT] = MAPLHC;

    int map[MAPSTAFF_HEIGHT][MAPSTAFF_WIDTH];
    int id=0;
    for(int i=0;i<MAPSTAFF_HEIGHT;++i){
        for(int j=0;j<MAPSTAFF_WIDTH;++j){
            map[i][j]=map_flat[id];
            ++id;
        }
    }

    SDL_Surface *bitmap = NULL;
    SDL_Texture *map_texture;
    SDL_Rect rect;
    rect.w = TILE_SIZE;
    rect.h = TILE_SIZE;
    bitmap = SDL_LoadBMP("res/tile.bmp");
    if(!bitmap){
        std::cout<<"can't load tile"<<'\n';
    }
    SDL_Texture *tex = NULL;
    tex = SDL_CreateTextureFromSurface(renderer, bitmap);
    map_texture = SDL_CreateTexture(renderer,SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, SCREEN_WIDTH, SCREEN_HEIGHT);
    SDL_SetRenderTarget(renderer, map_texture);
    int i, j;

    for (i = 0; i < SCREEN_HEIGHT / TILE_SIZE; i++) {
        for (j = 0; j < SCREEN_WIDTH / TILE_SIZE; j++) {
            if (map[i][j]==BLOCK) {
                rect.x = TILE_SIZE * j;
                rect.y = TILE_SIZE * i;
                SDL_RenderCopy(renderer, tex, NULL, &rect);
                
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
