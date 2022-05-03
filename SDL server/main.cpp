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
#include <coin.hpp>
#include <flag.hpp>
#include <prenpostgame.hpp>
#include <text.hpp>
#include <ghost.hpp>
#include <client.hpp>

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
            int flag=0;
            int timeLeft=LEVEL1_TIME;
            std::stringstream timeText,score;
            //Uint32 startTime = 0;

            SDL_Event e;
            SDL_Color textColor = {0,0xFF,0xFF};
//            SDL_Rect camera = {0,0,SCREEN_WIDTH,SCREEN_HEIGHT};

            LTimer timer;
            LTexture* currentTexture = &gScreen1Texture;
            LTexture p;
            LTexture gInputTextTexture;
            Flag winflag(0*TILE_SIZE,10*TILE_SIZE,&gFlagTexture);
            Text textVal("Your points are ");
            
            Player dot("Himadri","Vag",3,0);
            Player dot2("Kailash","Vidu",3,0);

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

            std::vector<Coin>coins;
            srand(time(0));
            i=0;
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

            SDL_StartTextInput();
            while( !quit )
            {
                bool renderText = false;
                //Handle events on queue
                while( SDL_PollEvent( &e ) != 0 )
                {
                    //User requests quit
                    if( e.type == SDL_QUIT )
                    {
                        quit = true;

                    }else if(e.type == SDL_KEYDOWN){
                        if (currentTexture == &gScreen1Texture){
                            if(e.key.keysym.sym == SDLK_RETURN){
                                currentTexture = &gScreen2Texture;
                                //startTime = SDL_GetTicks();
                                continue;
                            }else if(e.key.keysym.sym == SDLK_BACKSPACE && inputText.length() > 0){
                                inputText.pop_back();
                                renderText = true;
                            }else if(e.key.keysym.sym == SDLK_c && SDL_GetModState() & KMOD_CTRL){
                                SDL_SetClipboardText(inputText.c_str());
                            }else if( e.key.keysym.sym == SDLK_v && SDL_GetModState() & KMOD_CTRL){
                                inputText = SDL_GetClipboardText();
                                renderText = true;
                            }

                        }else if(currentTexture == &gScreen2Texture && e.key.keysym.sym == SDLK_LEFT){
                            currentTexture = &gScreen1Texture;
                            //startTime = SDL_GetTicks();
                        }else if(currentTexture == &gScreen2Texture && e.key.keysym.sym == SDLK_RETURN){
                            currentTexture = &gGameTexture;
                            //startTime = SDL_GetTicks();
                            
                            timer.start();
                        }else if(e.key.keysym.sym == SDLK_p){
                            if(currentTexture == &gGamePauseTexture && timer.isPaused()){
                                timer.unpause();
                                currentTexture = &gGameTexture;
                        }else if(currentTexture == &gGameTexture && !timer.isPaused()){
                                timer.pause();
                                currentTexture = &gGamePauseTexture;
                        }
                    }
                }
                    else if(e.type == SDL_TEXTINPUT){
                            if(currentTexture == &gScreen1Texture){
                                if(!(SDL_GetModState() & KMOD_CTRL && (e.text.text[0] == 'c' || e.text.text[0] == 'C' || e.text.text[0] == 'v' || e.text.text[0] == 'V'))){
                                    inputText += e.text.text;
                                    renderText = true;
                                    
                                }
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

                        
                        dot.handleEvent(e,currentTexture);
                        dot.name = inputText;
                    }

                

                //Move the dot
                
                //Center the camera over the dot
                // camera.x = ( dot.getmPosX() + PLAYER_WIDTH / 2 ) - SCREEN_WIDTH / 2;
                // camera.y = ( dot.getmPosY() + PLAYER_HEIGHT / 2 ) - SCREEN_HEIGHT / 2;

                // //Keep the camera in bounds
                // if( camera.x < 0 ){ 
                //     camera.x = 0;
                // }
                // if( camera.y < 0 ){
                //     camera.y = 0;
                // }
                // if( camera.x > LEVEL_WIDTH - camera.w ){
                //     camera.x = LEVEL_WIDTH - camera.w;
                // }
                // if( camera.y > LEVEL_HEIGHT - camera.h ){
                //     camera.y = LEVEL_HEIGHT - camera.h;
                // }

                //Clear screen
                SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
                SDL_RenderClear( gRenderer );

                //Render current texture

                //gScreen1Texture
                if(currentTexture == &gScreen1Texture){
                    SDL_RenderCopy(gRenderer,currentTexture->getTexture(),NULL,NULL);
                    gTextTexture.render( ( SCREEN_WIDTH - gTextTexture.getWidth() ) / 2, 0 );
                    if(renderText){
                        if(inputText != ""){
                            gInputTextTexture.loadFromRenderedText(inputText.c_str(),textColor);
                        }else{
                            gInputTextTexture.loadFromRenderedText(" ",textColor);
                        }
                    }
                    gInputTextTexture.render( ( SCREEN_WIDTH - gInputTextTexture.getWidth() ) / 2, gTextTexture.getHeight() );
                }
                //gScreen2Texture
                else if(currentTexture == &gScreen2Texture){
                    SDL_RenderCopy(gRenderer,currentTexture->getTexture(),NULL,NULL);

                }
                //gGameTexture
                else if(currentTexture == &gGameTexture){
                    Mix_PlayMusic(gMusic,-1);
                    SDL_Rect clip = {0,0,LEVEL_WIDTH,LEVEL_HEIGHT};
                    currentTexture->render(0,0,&clip);
                    // SDL_Rect renderQuad = {-camera.x,-camera.y,LEVEL_WIDTH,LEVEL_HEIGHT};
                    // SDL_RenderCopy(gRenderer,gScreen1Texture.getTexture(),NULL,&renderQuad);
                    
                    //to go to lhc
                    if(dot.getmPosX()/TILE_SIZE == LHC_TILEY && dot.getmPosY()/TILE_SIZE == LHC_TILEX){
                        currentTexture = &gLHCTexture;

                        dot.mPosX = (MAPLHC_WIDTH-2)*TILE_SIZE;
                        dot.mPosY = (MAPLHC_HEIGHT-1)*TILE_SIZE;
                        
                    }
                    //pop up
                    if(dot.getmPosX()/TILE_SIZE == LHC_TILEY+4 && dot.getmPosY()/TILE_SIZE == LHC_TILEX){
                        SDL_Rect renderQuad = {100,100,TILE_SIZE*5,TILE_SIZE};
                        SDL_RenderCopy(gRenderer,gScreen2Texture.getTexture(),NULL,&renderQuad);

                    }

                    //timeLeft
                    timeText.str("");
                    timeLeft = LEVEL1_TIME - timer.getTicks()/1000;
                    timeText << "Seconds since start time : " <<timeLeft;

                    if(timeLeft==0){
                        currentTexture = &gGameOverTexture;
                        continue;
                    }
                    if( !gTimeTextTexture.loadFromRenderedText( timeText.str().c_str(),textColor ) ){
                        printf( "Failed to load time texture!\n" );
                    }
                    
                    gTimeTextTexture.render(0,0);
                    
                    std::cout<<"Hello";
                    
                    Client obj;
                    //string client_data = obj.server_send(to_string(dot.mPosX)+"#"+to_string(dot.mPosY)+"#"+to_string(dot.lives)+"#"+to_string(dot.points)); 
                    string server_data = obj.client_send(to_string(dot.mPosX)+"#"+to_string(dot.mPosY)+"#"); 
                    int cnt=0; int s=0; int i=0;
                    while (cnt<2){
                        if(server_data[i]=='#'){
                            if(cnt == 0){
                                dot2.mPosX=stoi(server_data.substr(s,i-s));
                                s=i+1; cnt++;
                            }
                            else if(cnt == 1){
                                dot2.mPosY=stoi(server_data.substr(s,i-s));
                                s=i+1; cnt++;
                            }
                        }
                        i++;
                    }

                    
                    //dot.render(camera.x,camera.y);
                    dot.render(0,0);
                    dot2.render(0,0);

                    // for(int i=0;i<(int)coins.size();++i){
                    //     coins[i].render(camera.x,camera.y);
                    //     if(coins[i].mPosX/TILE_SIZE == dot.getmPosX()/TILE_SIZE && coins[i].mPosY/TILE_SIZE == dot.getmPosY()/TILE_SIZE){
                    //         dot.points+=coins[i].value;
                    //         coins.erase(coins.begin()+i);
                    //     }

                    // }

                    // for(int i=0;i<MAX_GHOSTS;++i){
                    //     ghosts[i].render(camera.x,camera.y);
                    //     ghosts[i].move();
                    //     if(ghosts[i].mPosX/TILE_SIZE == dot.getmPosX()/TILE_SIZE && ghosts[i].mPosY/TILE_SIZE == dot.getmPosY()/TILE_SIZE){

                    //     }
                    // }

                    // winflag.render(camera.x,camera.y);

                    // if(winflag.mPosX/TILE_SIZE == dot.getmPosX()/TILE_SIZE && winflag.mPosY/TILE_SIZE == dot.getmPosY()/TILE_SIZE){
                    //     currentTexture=&gScoreBoardTexture;
                    // }

                }
                //gScoreBoardTexture
                else if(currentTexture == &gScoreBoardTexture){
                    SDL_RenderCopy(gRenderer,currentTexture->getTexture(),NULL,NULL);
                    if(flag==0){
                        textVal.addText(std::to_string(dot.points));
                        std::cout<<textVal.text<<'\n';
                        score.str("");
                        score << textVal.text;
                        if( !p.loadFromRenderedText( score.str().c_str(),textColor ) )
                        {
                            printf( "Failed to load score texture!\n" );
                        }
                        flag=1;
                    }

                    p.render(0,0);

                }else if(currentTexture == &gGameOverTexture){
                    SDL_RenderCopy(gRenderer,currentTexture->getTexture(),NULL,NULL);

                }else if (currentTexture == &gGamePauseTexture){
                    SDL_RenderCopy(gRenderer,currentTexture->getTexture(),NULL,NULL);

                }else if(currentTexture == &gLHCTexture){
                    SDL_RenderCopy(gRenderer,currentTexture->getTexture(),NULL,NULL);
                    timeText.str("");
                    timeLeft = LEVEL1_TIME - timer.getTicks()/1000;
                    timeText << "Seconds since start time : " <<timeLeft;

                    if(timeLeft==0){
                        currentTexture = &gGameOverTexture;
                        continue;
                    }
                    if( !gTimeTextTexture.loadFromRenderedText( timeText.str().c_str(),textColor ) ){
                        printf( "Failed to load time texture!\n" );
                    }
                    
                    gTimeTextTexture.render(0,0);
                    dot.render(currentTexture);

                    std::cout<<dot.getmPosX()<<' '<<dot.getmPosY()<<'\n';
                    if(dot.getmPosX() >= (MAPLHC_WIDTH-1)*TILE_SIZE && dot.getmPosY() >= (MAPLHC_HEIGHT-1)*TILE_SIZE){
                        std::cout<<"hey"<<dot.getmPosX()<<' '<<dot.getmPosY()<<'\n';

                        currentTexture = &gGameTexture;
                        dot.mPosX = (LHC_TILEY+1)*TILE_SIZE;
                        dot.mPosY = LHC_TILEX*TILE_SIZE;
                        
                    }
                    
                }
                //Update screen
                SDL_RenderPresent( gRenderer );
            }
            //std::cout<<"Well"<<inputText<<'\n';
        }

    }

    SDL_StopTextInput();
    //Free resources and close SDL
    close();

    return 0;
}