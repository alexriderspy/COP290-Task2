#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_net.h>

#include <timer.hpp>
#include <character.hpp>
#include <map.hpp>
#include <global.hpp>
#include <constants.hpp>
#include <ltexture.hpp>
#include <coin.hpp>
#include <flag.hpp>
#include <pregame.hpp>

#include <stdlib.h>
#include <time.h>
#include <vector>
#include <iostream>
#include <string>
#include <sstream>

//Screen dimension constants

// enum KeyPressTextures
// {
//     KEY_PRESS_TEXTURE_DEFAULT,
//     KEY_PRESS_TEXTURE_LEFT,
//     KEY_PRESS_TEXTURE_RIGHT,
//     KEY_PRESS_TEXTURE_TOTAL
// };

int main( int argc, char* args[] )
{
    //Start up SDL and create window
    if( !init() )
    {
        printf( "Failed to initialize!\n" );
    }
    else
    {
        //Load media
        if( !loadMedia() )
        {
            printf( "Failed to load media!\n" );
        }
        else
        {   
            //Main loop flag
            bool quit = false;

            //Event handler
            SDL_Event e;

            SDL_Color textColor = {0,0,0,255};

            Uint32 startTime = 0;
            LTimer timer;

            std::vector<Coin>coins;

            Flag winflag(0*TILE_SIZE,10*TILE_SIZE,&gFlagTexture);

            int map_flat[MAP_WIDTH*MAP_HEIGHT] = MAP;

            int map[MAP_HEIGHT][MAP_WIDTH];
            int id=0;
            for(int i=0;i<MAP_HEIGHT;++i){
                for(int j=0;j<MAP_WIDTH;++j){
                    map[i][j]=map_flat[id];
                    ++id;
                }
            }

            srand(time(0));
            int i=0;
            while(i<MAX_COINS){
                int xTilecoor = rand()%MAP_HEIGHT;
                int yTilecoor = rand()%MAP_WIDTH;
                if(map[xTilecoor][yTilecoor]==1) continue;
                //int value = rand()%10000;
                Coin coin(10,yTilecoor*TILE_SIZE,xTilecoor*TILE_SIZE,
                    &gCoinTexture);
                coins.push_back(coin);
                ++i;
            }

            std::stringstream timeText;

            //Current rendered texture
            LTexture* currentTexture = &gScreen1Texture;
            Character dot;

            SDL_Rect camera = {0,0,SCREEN_WIDTH,SCREEN_HEIGHT};
            //While application is running
            while( !quit )
            {
                //Handle events on queue
                while( SDL_PollEvent( &e ) != 0 )
                {
                    //User requests quit
                    if( e.type == SDL_QUIT )
                    {
                        quit = true;

                    }else if(e.type == SDL_KEYDOWN){
                        if (currentTexture == &gScreen1Texture && e.key.keysym.sym == SDLK_RETURN){
                            currentTexture = &gScreen2Texture;
                            startTime = SDL_GetTicks();
                            
                        }else if(currentTexture == &gScreen2Texture && e.key.keysym.sym == SDLK_LEFT){
                            currentTexture = &gScreen1Texture;
                            startTime = SDL_GetTicks();
                        }else if(currentTexture == &gScreen2Texture && e.key.keysym.sym == SDLK_RETURN){
                            currentTexture = &gGameTexture;
                            Mix_PlayMusic(gMusic,-1);
                            startTime = SDL_GetTicks();
                        }else if(e.key.keysym.sym == SDLK_s){
                            if(timer.isStarted()){
                                timer.stop();
                            }else{
                                timer.start();
                            }
                        }else if(e.key.keysym.sym == SDLK_p){
                            if(timer.isPaused()){
                                timer.unpause();
                            }else{
                                timer.pause();
                            }
                        }

                        // if(e.key.keysym.sym == SDLK_1){
                        //     Mix_PlayChannel (-1,gScratch,0);
                            
                        // }else if(e.key.keysym.sym == SDLK_9){
                        //     if(Mix_PlayingMusic() == 0){
                        //         Mix_PlayMusic(gMusic,-1);
                        //     }else if (Mix_PausedMusic() == 1){
                        //         Mix_ResumeMusic();
                        //     }else{
                        //         Mix_PauseMusic();
                        //     }
                        // }else if(e.key.keysym.sym == SDLK_0){
                        //     Mix_HaltMusic();
                        // }

                        dot.handleEvent(e);
                    }

                }

                //Move the dot
                dot.move();

                //Center the camera over the dot
                camera.x = ( dot.getmPosX() + Character::CHARACTER_WIDTH / 2 ) - SCREEN_WIDTH / 2;
                camera.y = ( dot.getmPosY() + Character::CHARACTER_HEIGHT / 2 ) - SCREEN_HEIGHT / 2;

                std::cout<<dot.getmPosX()<<' '<<dot.getmPosY()<<' '<<camera.x<<' '<<camera.y<<'\n';
                //Keep the camera in bounds
                if( camera.x < 0 )
                { 
                    camera.x = 0;
                }
                if( camera.y < 0 )
                {
                    camera.y = 0;
                }
                if( camera.x > LEVEL_WIDTH - camera.w )
                {
                    camera.x = LEVEL_WIDTH - camera.w;
                }
                if( camera.y > LEVEL_HEIGHT - camera.h )
                {
                    camera.y = LEVEL_HEIGHT - camera.h;
                }
                                
                timeText.str("");
                timeText << "Seconds since start time : " <<(timer.getTicks()/1000.f);

                if( !gTimeTextTexture.loadFromRenderedText( timeText.str().c_str(),textColor ) )
                {
                    printf( "Failed to load time texture!\n" );
                }

                //Clear screen
                SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
                SDL_RenderClear( gRenderer );

                //Render current texture
                if(currentTexture != &gGameTexture){
                    SDL_RenderCopy(gRenderer,currentTexture->getTexture(),NULL,NULL);
                }else{
                    currentTexture->render(0,0,&camera);
                    gTimeTextTexture.render(0,0);
                    dot.render(camera.x,camera.y);
                    for(int i=0;i<(int)coins.size();++i){
                        coins[i].render(camera.x,camera.y);
                        if(coins[i].mPosX/TILE_SIZE == dot.getmPosX()/TILE_SIZE && coins[i].mPosY/TILE_SIZE == dot.getmPosY()/TILE_SIZE){
                            dot.points+=coins[i].value;
                            coins.erase(coins.begin()+i);
                        }                        
                    }

                    winflag.render(camera.x,camera.y);
                    if(winflag.mPosX/TILE_SIZE == dot.getmPosX()/TILE_SIZE && winflag.mPosY/TILE_SIZE == dot.getmPosY()/TILE_SIZE){
                        currentTexture=&gScoreBoardTexture;
                    }


                }
                // gTextTexture.render( ( SCREEN_WIDTH - gTextTexture.getWidth() ) / 2, 0 );

                if(currentTexture == &gScreen1Texture){
                    gTextTexture.render(100,400);
                }
                //Update screen
                SDL_RenderPresent( gRenderer );
            }
        }
    }

    //Free resources and close SDL
    close();

    return 0;
}