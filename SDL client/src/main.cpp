#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_net.h>

#include <timer.hpp>
#include <player.hpp>
#include <map.hpp>
#include <global.hpp>
#include <constants.hpp>
#include <ltexture.hpp>
#include <entity.hpp>
#include <prenpostgame.hpp>
#include <text.hpp>
#include <ghost.hpp>
#include <client.hpp>
#include <screens.hpp>
#include <events.hpp>
#include <levels.hpp>

#include <stdlib.h>
#include <time.h>
#include <vector>
#include <iostream>
#include <string>
#include <sstream>

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
            int flag=0,flagLoading=0;
            int timeLeft=LEVEL1_TIME;
            std::stringstream timeText,score;

            SDL_Event e;
            SDL_Color textColor = {0,0xFF,0xFF};
            SDL_Rect camera = {0,0,SCREEN_WIDTH,SCREEN_HEIGHT};

            LTimer timer,timerLoading;
            LTexture* currentTexture = &gScreen1Texture;
            LTexture p;
            Entity winflag(0,22*TILE_SIZE,21*TILE_SIZE,&gFlagTexture);
            Text textPoints("");
            Text lives("");
            // Client obj;
            // obj.connectCS();
            Player dot("Himadri","Vag",3,0);
            Player dot2("Kailash","Vidu",3,0);

            int level=1;
            std::string inputText="";
            std::string hostelText="";

            std::vector<Ghost>ghosts;
            srand(time(0));
            int i=0;
            while(i<MAX_GHOSTS){
                int xTilecoor = rand()%MAP_HEIGHT;
                int yTilecoor = rand()%MAP_WIDTH;

                Ghost ghost(yTilecoor*TILE_SIZE,xTilecoor*TILE_SIZE,&gGhostTexture,1,1);
                ghosts.push_back(ghost);
                ++i;
            }


            int map_flat[MAP_WIDTH*MAP_HEIGHT] = MAP;
            int map[MAP_HEIGHT][MAP_WIDTH];
            int id=0;
            for(int i=0;i<MAP_HEIGHT;++i){
                for(int j=0;j<MAP_WIDTH;++j){
                    map[i][j]=map_flat[id];
                    ++id;
                }
            }

            std::vector<Entity>coins;
            srand(time(0));
            i=0;
            while(i<MAX_COINS){
                int xTilecoor = rand()%MAP_HEIGHT;
                int yTilecoor = rand()%MAP_WIDTH;
                if(map[xTilecoor][yTilecoor]==1) continue;
                //int value = rand()%10000;
                Entity coin(10,yTilecoor*TILE_SIZE,xTilecoor*TILE_SIZE,
                    &gCoinTexture);
                coins.push_back(coin);
                ++i;
            }

            SDL_StartTextInput();
            timerLoading.start();

            while( !quit )
            {
                bool renderText = false;
                //Handle events on queue

                events(e,inputText,renderText,quit,timer,dot,currentTexture);

                //Move the dot
                //Center the camera over the dot
                camera.x = ( dot.getmPosX() + PLAYER_WIDTH / 2 ) - SCREEN_WIDTH / 2;
                camera.y = ( dot.getmPosY() + PLAYER_HEIGHT / 2 ) - SCREEN_HEIGHT / 2;

                //Keep the camera in bounds
                if( camera.x < 0 ){ 
                    camera.x = 0;
                }
                if( camera.y < 0 ){
                    camera.y = 0;
                }
                if( camera.x > LEVEL_WIDTH - camera.w ){
                    camera.x = LEVEL_WIDTH - camera.w;
                }
                if( camera.y > LEVEL_HEIGHT - camera.h ){
                    camera.y = LEVEL_HEIGHT - camera.h;
                }

                //Clear screen
                SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
                SDL_RenderClear( gRenderer );

                //Render current texture

                //gScreen1Texture
                //string client_data = obj.server_send(to_string(dot.mPosX)+"#"+to_string(dot.mPosY)+"#"+to_string(dot.lives)+"#"+to_string(dot.points)); 
                // obj.sendCS(std::to_string(dot.mPosX)+"#"+std::to_string(dot.mPosY)+"#"); 
                // std::string server_data = obj.receiveCS();

                // std::cout<<server_data<<'\n';

                // int cnt=0; int s=0; int i=0;
                // while (cnt<2){
                //     if(server_data[i]=='#'){
                //         if(cnt == 0){
                //             dot2.mPosX=stoi(server_data.substr(s,i-s));
                //             s=i+1; cnt++;
                //         }
                //         else if(cnt == 1){
                //             dot2.mPosY=stoi(server_data.substr(s,i-s));
                //             s=i+1; cnt++;
                //         }
                //     }
                //     i++;
                // }

                
                if(currentTexture == &gScreen1Texture){
                    title(flagLoading,currentTexture,timeLeft,timerLoading);
                }
                
                else if(currentTexture == &gEnterTexture){
                    choose(renderText,currentTexture,inputText,textColor);
                }
                //gGameTexture
                //gScoreBoardTexture
                else if(currentTexture == &gScoreBoardTexture){
                    SDL_RenderCopy(gRenderer,currentTexture->getTexture(),NULL,NULL);
                    if(flag==0){
                        std::cout<<textPoints.text<<'\n';
                        score.str("");
                        score << textPoints.text;
                        if( !p.loadFromRenderedText( score.str().c_str(),textColor ) )
                        {
                            printf( "Failed to load score texture!\n" );
                        }
                        flag=1;
                    }

                    p.render(0,0);

                }else if(currentTexture == &gGameOverTexture){
                    SDL_RenderCopy(gRenderer,currentTexture->getTexture(),NULL,NULL);

                }
                else{
                    if(level == 1){
                        level1(currentTexture,camera,dot,dot2,timeText,timeLeft,score,p,textColor,textPoints,lives,timer,coins,ghosts,winflag);
                    }else{
                        level2();
                    }
                }
                
                //Update screen
                SDL_RenderPresent( gRenderer );
            }
        }

    }

    SDL_StopTextInput();
    //Free resources and close SDL
    close();

    return 0;
}