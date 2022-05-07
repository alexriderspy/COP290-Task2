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
#include <server.hpp>
#include <screens.hpp>
#include <events.hpp>
#include <levels.hpp>
#include <deathworm.hpp>

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
            Entity winflag(0,21*TILE_SIZE,41*TILE_SIZE,&gFlagTexture);
            Text textPoints("");
            Text lives("");
            Text textPoints2("");
            Text lives2("");

            Server obj;
            obj.connectCS();

            std::string path;

            Player dot("Himadri","Vag",3,0,"res/girl1_back.png","res/girl1_front.png","res/girl1_left.png","res/girl1_right.png");
            Player dot2("Kailash","Vidu",3,0,"res/girl1_back.png","res/girl1_front.png","res/girl1_left.png","res/girl1_right.png");

            int level = 2;
            Level1 lev1;
            Level2 lev2;

            int level_server=2;
            std::string inputText="";

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

            std::vector<Worm>worms;

            Worm worm1(52*TILE_SIZE,39*TILE_SIZE,&gDeathWormTexture,1,1);
            worms.push_back(worm1);
            Worm worm2(86*TILE_SIZE,22*TILE_SIZE,&gDeathWormTexture,1,1);
            worms.push_back(worm2);
            Worm worm3(29*TILE_SIZE,37*TILE_SIZE,&gDeathWormTexture,1,1);
            worms.push_back(worm3);
            Worm worm4(62*TILE_SIZE,22*TILE_SIZE,&gDeathWormTexture,1,1);
            worms.push_back(worm4);
            Worm worm5(12*TILE_SIZE,60*TILE_SIZE,&gDeathWormTexture,1,1);
            worms.push_back(worm5);

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
                int value = rand()%10000;
                Entity coin(value,yTilecoor*TILE_SIZE,xTilecoor*TILE_SIZE,
                    &gCoinTexture);
                coins.push_back(coin);
                ++i;
            }

            SDL_StartTextInput();
            timerLoading.start();

            int tex=100;
            int tex_server = 100;

            while( !quit )
            {
                bool renderText = false;
                //Handle events on queue

                events(e,inputText,renderText,quit,timer,dot,dot2,currentTexture,camera,level,winflag,tex,path,tex_server,level_server);

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
                std::string client_data = obj.receiveCS();

                std::cout<<client_data<<'\n';


                if(currentTexture==&gGameTexture){
                    tex=0;
                }
                else if(currentTexture==&gLHCTexture){
                    tex=1;
                }
                else if(currentTexture==&gScoopsTexture){
                    tex=2;
                }
                else if(currentTexture==&gStaffCanteen){
                    tex=3;
                }
                else if(currentTexture==&gLibraryTexture){
                    tex=4;
                }
                else if(currentTexture==&gHostelTexture){
                    tex=5;
                }
                obj.sendCS(std::to_string(dot.mPosX)+"#"+std::to_string(dot.mPosY)+"#"+std::to_string(dot.lives)+"#"+std::to_string(dot.points)+"#"+dot.path+"#"+std::to_string(tex)+"#"+std::to_string(level)+"#");


                int cnt=0; int s=0; int i=0; 
                while (cnt<7){
                    if(client_data[i]=='#'){
                        if(cnt == 0){
                            dot2.mPosX=stoi(client_data.substr(s,i-s));
                            s=i+1; cnt++;
                        }
                        else if(cnt == 1){
                            dot2.mPosY=stoi(client_data.substr(s,i-s));
                            s=i+1; cnt++;
                        }
                        else if(cnt == 2){
                            dot2.lives=stoi(client_data.substr(s,i-s));
                            s=i+1; cnt++;
                        }
                        else if(cnt == 3){
                            dot2.points=stoi(client_data.substr(s,i-s));
                            s=i+1; cnt++;
                        }
                        else if(cnt == 4){

                            path = client_data.substr(s,i-s);
                            s=i+1; cnt++;
                        }
                        else if(cnt == 5){
                            tex_server=stoi(client_data.substr(s,i-s));
                            s=i+1; cnt++;
                        }else if(cnt == 6){
                            level_server = stoi(client_data.substr(s,i-s));
                            s=i+1; cnt++;
                        }
                        i++;
                }
                }
                if(dot.lives==0){
                    SDL_RenderCopy(gRenderer,gGameOverTexture.getTexture(),NULL,NULL);
                    quit=true;
                }
                if(dot2.lives==0){
                    SDL_RenderCopy(gRenderer,gScoreBoardTexture.getTexture(),NULL,NULL);
                    quit=true;
                }
                
                if(currentTexture == &gScreen1Texture){
                    title(flagLoading,currentTexture,timeLeft,timerLoading);
                }
                
                else if(currentTexture == &gScreen2Texture || currentTexture == &gScreen2_2Texture || currentTexture == &gScreen2_3Texture || currentTexture == &gScreen2_4Texture){
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

                }else if(currentTexture == &gWordOfAdvice){
                    SDL_RenderCopy(gRenderer,currentTexture->getTexture(),NULL,NULL);
                }
                else{
                    if(level == 1){
                        level1(currentTexture,camera,dot,dot2,timeText,timeLeft,score,p,textColor,textPoints,lives,timer,coins,ghosts,worms,winflag,lev1,tex_server,path);
                    }else{
                        level2(currentTexture,camera,dot,dot2,timeText,timeLeft,score,p,textColor,textPoints,lives,timer,coins,ghosts,worms,winflag,lev2,tex_server,path);
                    }
                
                    timeText.str("");
                    timeLeft = LEVEL1_TIME - timer.getTicks()/1000;
                    timeText << "Seconds since start time : " <<timeLeft;

                    if(timeLeft==0){
                    currentTexture = &gGameOverTexture;
                    }
                    if( !gTimeTextTexture.loadFromRenderedText( timeText.str().c_str(),textColor ) ){
                        printf( "Failed to load time texture!\n" );
                    }
        
                    gTimeTextTexture.render(0,0);

        
                    textPoints.text = ("Points of player 1: "+std::to_string(dot.points));
                    score.str("");
                    score << textPoints.text;
                    if( !p.loadFromRenderedText( score.str().c_str(),textColor ) )
                    {
                        printf( "Failed to load score texture!\n" );
                    }
        

                    p.render(SCREEN_WIDTH/2,0);

                    lives.text = ("Lives of player 1: "+std::to_string(dot.lives));
                    score.str("");
                    score << lives.text;
                    if( !p.loadFromRenderedText( score.str().c_str(),textColor ) )
                    {
                        printf( "Failed to load score texture!\n" );
                    }
        

                    p.render(SCREEN_WIDTH/2,20);

                    textPoints2.text = ("Points of player 2: "+std::to_string(dot2.points));
                    score.str("");
                    score << textPoints2.text;
                    if( !p.loadFromRenderedText( score.str().c_str(),textColor ) )
                    {
                        printf( "Failed to load score texture!\n" );
                    }

                    p.render(SCREEN_WIDTH/2 + 600,0);

                    lives2.text = ("Lives of player 2: "+std::to_string(dot2.lives));
                    score.str("");
                    score << lives2.text;
                    if( !p.loadFromRenderedText( score.str().c_str(),textColor ) )
                    {
                        printf( "Failed to load score texture!\n" );
                    }
                    p.render(SCREEN_WIDTH/2+600,20);
                //Update screen
                SDL_RenderPresent( gRenderer );
            }
        }

    

    SDL_StopTextInput();
    //Free resources and close SDL
    close();

    return 0;
    }
    }
}