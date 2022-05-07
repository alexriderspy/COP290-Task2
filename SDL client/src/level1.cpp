#include <levels.hpp>

void level1(LTexture* &currentTexture,SDL_Rect &camera, Player &dot, Player &dot2, std::stringstream &timeText, int &timeLeft,std::stringstream &score,LTexture &p,SDL_Color &textColor, Text &textPoints, Text &lives, LTimer &timer, std::vector <Entity>&coins, std::vector<Ghost>&ghosts,Entity &winflag,Level1&lev1,int&tex_client, std::string &path){

    if(currentTexture == &gGameTexture){
        currentTexture->render(0,0,&camera);
        lev1.print();
        SDL_Rect renderQuad = {-camera.x,-camera.y,LEVEL_WIDTH,LEVEL_HEIGHT};
        SDL_RenderCopy(gRenderer,gMazeTexture.getTexture(),NULL,&renderQuad);
        
        //to go to lhc
        if(dot.getmPosX()/TILE_SIZE == LHC_TILEY && dot.getmPosY()/TILE_SIZE == LHC_TILEX){

            currentTexture = &lhc1;
            
            Mix_PlayChannel(-1,gEnterDarkness,0);
            dot.mPosX = (5)*TILE_SIZE;
            dot.mPosY = (14)*TILE_SIZE;
        }

        if(dot.getmPosX()/TILE_SIZE == STAFF_TILEY && dot.getmPosY()/TILE_SIZE == STAFF_TILEX){

            currentTexture = &sc;
            Mix_PlayChannel(-1,gEnterDarkness,0);
            dot.mPosX = (2)*TILE_SIZE;
            dot.mPosY = (14)*TILE_SIZE;
        }
        
        for(int i=0;i<(int)coins.size();++i){
            coins[i].render(camera.x,camera.y);
            if(coins[i].mPosX/TILE_SIZE == dot.getmPosX()/TILE_SIZE && coins[i].mPosY/TILE_SIZE == dot.getmPosY()/TILE_SIZE){
                dot.points+=coins[i].value;
                Mix_PlayChannel(-1,gArm,0);
                coins.erase(coins.begin()+i);
            }
        }

        for(int i=0;i<MAX_GHOSTS;++i){
            ghosts[i].render(camera.x,camera.y);
            ghosts[i].move();
            if(ghosts[i].mPosX/TILE_SIZE == dot.getmPosX()/TILE_SIZE && ghosts[i].mPosY/TILE_SIZE == dot.getmPosY()/TILE_SIZE){
                Mix_PlayChannel(-1,gBlood,0);
                dot.points-=10;
            }
        }

        winflag.render(camera.x,camera.y);

        lev1.checkFootball(dot);

        if(dot.getmPosX()/TILE_SIZE == FOOT_TILEY && dot.getmPosY()/TILE_SIZE == FOOT_TILEX){

            lev1.checkFootball(dot);
            currentTexture = &fb;
            dot.mPosX+=TILE_SIZE;
        }


        if(winflag.mPosX/TILE_SIZE == dot.getmPosX()/TILE_SIZE && winflag.mPosY/TILE_SIZE == dot.getmPosY()/TILE_SIZE){
            if(lev1.checkFootball(dot) && lev1.checkLHC(dot,currentTexture) && lev1.checkStaffCanteen(dot,currentTexture)){
                currentTexture=&gScoreBoardTexture;
            }
        }
        if(tex_client==0){
            dot2.lastTexture.loadFromFile(path);
            dot2.render(camera.x,camera.y);
        }
        dot.render(camera.x,camera.y);

        
    }else if(currentTexture == &gLHCTexture){
        lev1.print();
        SDL_RenderCopy(gRenderer,currentTexture->getTexture(),NULL,NULL);
        LTexture Bg;
        Bg.loadFromFile("res/maze_LHC.png");
        SDL_RenderCopy(gRenderer,Bg.getTexture(),NULL,NULL);
        
        if(dot.getmPosX()/TILE_SIZE == lev1.pos_LHC[0].first && dot.getmPosY()/TILE_SIZE == lev1.pos_LHC[0].second){

            lev1.checkLHC(dot,currentTexture);
            currentTexture = &lhc2;
            dot.mPosX+=TILE_SIZE;
        }
        if(dot.getmPosX()/TILE_SIZE == lev1.pos_LHC[1].first && dot.getmPosY()/TILE_SIZE == lev1.pos_LHC[1].second){

            lev1.checkLHC(dot,currentTexture);

            currentTexture = &lhc3; 
            dot.mPosX+=TILE_SIZE;
        }
        if(dot.getmPosX()/TILE_SIZE == lev1.pos_LHC[2].first && dot.getmPosY()/TILE_SIZE == lev1.pos_LHC[2].second){

            lev1.checkLHC(dot,currentTexture);
            currentTexture = &lhc4;
            dot.mPosX+=TILE_SIZE;
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
        if(tex_client==1){
            dot2.lastTexture.loadFromFile(path);
            dot2.render(0,0);
        }
        dot.render(0,0);

        lev1.checkLHC(dot,currentTexture);

        if(dot.getmPosX() >= (25)*TILE_SIZE && dot.getmPosY() >= (14)*TILE_SIZE){

            currentTexture  = &r_sc;
            dot.mPosX = (LHC_TILEY-3)*TILE_SIZE;
            dot.mPosY = (LHC_TILEX-1)*TILE_SIZE;
            
        }  

        //x,y,width,height
        // SDL_Rect renderRoom1 = {1*TILE_SIZE,3*TILE_SIZE,3*TILE_SIZE,4*TILE_SIZE};
        // SDL_RenderCopy(gRenderer,gRoom1LHCTexture.getTexture(),NULL,&renderRoom1);
 
    }else if(currentTexture == &gStaffCanteen){
        lev1.print();
        SDL_RenderCopy(gRenderer,currentTexture->getTexture(),NULL,NULL);
        LTexture Bg;
        Bg.loadFromFile("res/mazeStaffCanteen.png");
        SDL_RenderCopy(gRenderer,Bg.getTexture(),NULL,NULL);

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
        if(tex_client==3){
            dot2.lastTexture.loadFromFile(path);
            dot2.render(0,0);
        }
        dot.render(0,0);

        lev1.checkStaffCanteen(dot,currentTexture);
        
        if(dot.getmPosX() >= (27)*TILE_SIZE && dot.getmPosY() >= (14)*TILE_SIZE){

            currentTexture = &r_fb;
            dot.mPosX = (STAFF_TILEY-2)*TILE_SIZE;
            dot.mPosY = (STAFF_TILEX-2)*TILE_SIZE;
            
        }   
    }else if(currentTexture == &lhc1){
        SDL_RenderCopy(gRenderer,currentTexture->getTexture(),NULL,NULL);
    }else if(currentTexture == &lhc2){
        SDL_RenderCopy(gRenderer,currentTexture->getTexture(),NULL,NULL);
    }else if(currentTexture == &lhc3){
        SDL_RenderCopy(gRenderer,currentTexture->getTexture(),NULL,NULL);
    }else if(currentTexture == &lhc4){
        SDL_RenderCopy(gRenderer,currentTexture->getTexture(),NULL,NULL);
    }else if(currentTexture == &sc){
        SDL_RenderCopy(gRenderer,currentTexture->getTexture(),NULL,NULL);
    }else if(currentTexture == &fb){
        SDL_RenderCopy(gRenderer,currentTexture->getTexture(),NULL,NULL);
    }else if(currentTexture == &r_lhc){
        SDL_RenderCopy(gRenderer,currentTexture->getTexture(),NULL,NULL);
    }else if(currentTexture == &r_sc){
        SDL_RenderCopy(gRenderer,currentTexture->getTexture(),NULL,NULL);
    }else if(currentTexture == &r_fb){
        SDL_RenderCopy(gRenderer,currentTexture->getTexture(),NULL,NULL);
    }
}