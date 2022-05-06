#include <levels.hpp>

void level2(LTexture* &currentTexture,SDL_Rect &camera, Player &dot, Player &dot2, std::stringstream &timeText, int &timeLeft,std::stringstream &score,LTexture &p,SDL_Color &textColor, Text &textPoints, Text &lives, LTimer &timer, std::vector <Entity>&coins, std::vector<Ghost>&ghosts,Entity &winflag,Level2&lev2){

    if(currentTexture == &gGameTexture){
        currentTexture->render(0,0,&camera);
        lev2.print();
        SDL_Rect renderQuad = {-camera.x,-camera.y,LEVEL_WIDTH,LEVEL_HEIGHT};
        SDL_RenderCopy(gRenderer,gMazeTexture.getTexture(),NULL,&renderQuad);
        
        //to go to lhc
        if(dot.getmPosX()/TILE_SIZE == LHC_TILEY && dot.getmPosY()/TILE_SIZE == LHC_TILEX){
            currentTexture = &gLHCTexture;
            Mix_PlayChannel(-1,gEnterDarkness,0);
            dot.mPosX = (5)*TILE_SIZE;
            dot.mPosY = (14)*TILE_SIZE;
        }

        if(dot.getmPosX()/TILE_SIZE == STAFF_TILEY && dot.getmPosY()/TILE_SIZE == STAFF_TILEX){
            currentTexture = &gStaffCanteen;
            Mix_PlayChannel(-1,gEnterDarkness,0);
            dot.mPosX = (2)*TILE_SIZE;
            dot.mPosY = (14)*TILE_SIZE;
        }

        if(dot.getmPosX()/TILE_SIZE == SCOOPS_TILEY && dot.getmPosY()/TILE_SIZE == SCOOPS_TILEX){
            currentTexture = &gScoopsTexture;
            Mix_PlayChannel(-1,gEnterDarkness,0);
            dot.mPosX = (11)*TILE_SIZE;
            dot.mPosY = (14)*TILE_SIZE;
        }
        if(dot.hostel == "Himadri"  && dot.getmPosX()/TILE_SIZE == HOSTEL_HIM_TILEY && dot.getmPosY()/TILE_SIZE == HOSTEL_HIM_TILEX){
            currentTexture = &gHostelTexture;
            Mix_PlayChannel(-1,gEnterDarkness,0);
            dot.mPosX = (1)*TILE_SIZE;
            dot.mPosY = (14)*TILE_SIZE;
        }
        if(dot.hostel == "Kailash"  && dot.getmPosX()/TILE_SIZE == HOSTEL_KAILASH_TILEY && dot.getmPosY()/TILE_SIZE == HOSTEL_KAILASH_TILEX){
            currentTexture = &gHostelTexture;
            Mix_PlayChannel(-1,gEnterDarkness,0);
            dot.mPosX = (1)*TILE_SIZE;
            dot.mPosY = (14)*TILE_SIZE;
        }
        if(dot.hostel == "Girnar"  && dot.getmPosX()/TILE_SIZE == HOSTEL_GIRNAR_TILEY && dot.getmPosY()/TILE_SIZE == HOSTEL_GIRNAR_TILEX){
            currentTexture = &gHostelTexture;
            Mix_PlayChannel(-1,gEnterDarkness,0);
            dot.mPosX = (1)*TILE_SIZE;
            dot.mPosY = (14)*TILE_SIZE;
        }
        if(dot.hostel == "Karakoram"  && dot.getmPosX()/TILE_SIZE == HOSTEL_KARA_TILEY && dot.getmPosY()/TILE_SIZE == HOSTEL_KARA_TILEX){
            currentTexture = &gHostelTexture;
            Mix_PlayChannel(-1,gEnterDarkness,0);
            dot.mPosX = (1)*TILE_SIZE;
            dot.mPosY = (14)*TILE_SIZE;
        }
        if(dot.getmPosX()/TILE_SIZE == LIB_TILEY && dot.getmPosY()/TILE_SIZE == LIB_TILEX){
            currentTexture = &gLibraryTexture;
            Mix_PlayChannel(-1,gEnterDarkness,0);
            dot.mPosX = (3)*TILE_SIZE;
            dot.mPosY = (14)*TILE_SIZE;
        }

        //timeLeft
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

        dot2.render(camera.x,camera.y);
        dot.render(camera.x,camera.y);
        
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
            }
        }

        winflag.render(camera.x,camera.y);

        lev2.checkLawn(dot);
        lev2.checkSac(dot);

        if(winflag.mPosX/TILE_SIZE == dot.getmPosX()/TILE_SIZE && winflag.mPosY/TILE_SIZE == dot.getmPosY()/TILE_SIZE){
            if(lev2.checkLawn(dot) && lev2.checkHostel(dot,currentTexture) && lev2.checkScoops(dot,currentTexture) && lev2.checkLibrary(dot,currentTexture) && lev2.checkSac(dot)){
                currentTexture=&gScoreBoardTexture;
            }
        }

    }else if(currentTexture == &gHostelTexture){
        lev2.print();
        SDL_RenderCopy(gRenderer,currentTexture->getTexture(),NULL,NULL);
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
        dot.render(0,0);

        lev2.checkHostel(dot,currentTexture);
        if(dot.getmPosX() >= (29)*TILE_SIZE && dot.getmPosY() >= (14)*TILE_SIZE){
            if(dot.hostel == "Himadri"){

                currentTexture = &gGameTexture;
                dot.mPosX = (HOSTEL_HIM_TILEY)*TILE_SIZE;
                dot.mPosY = (HOSTEL_HIM_TILEX+2)*TILE_SIZE;
                
            }   
            if(dot.hostel == "Kailash"){

                currentTexture = &gGameTexture;
                dot.mPosX = (HOSTEL_KAILASH_TILEY)*TILE_SIZE;
                dot.mPosY = (HOSTEL_KAILASH_TILEX+2)*TILE_SIZE;
                
            }   
            if(dot.hostel == "Girnar"){

                currentTexture = &gGameTexture;
                dot.mPosX = (HOSTEL_GIRNAR_TILEY+1)*TILE_SIZE;
                dot.mPosY = (HOSTEL_GIRNAR_TILEX+1)*TILE_SIZE;
                
            }   
            if(dot.hostel == "Karakoram"){

                currentTexture = &gGameTexture;
                dot.mPosX = (HOSTEL_KARA_TILEY+1)*TILE_SIZE;
                dot.mPosY = (HOSTEL_KARA_TILEX+1)*TILE_SIZE;
                
            }
        }   
    }else if(currentTexture == &gScoopsTexture){
        lev2.print();
        SDL_RenderCopy(gRenderer,currentTexture->getTexture(),NULL,NULL);
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
        dot.render(0,0);

        lev2.checkScoops(dot,currentTexture);
        
        if(dot.getmPosX() >= (18)*TILE_SIZE && dot.getmPosY() >= (14)*TILE_SIZE){

            currentTexture = &gGameTexture;
            dot.mPosX = (SCOOPS_TILEY-2)*TILE_SIZE;
            dot.mPosY = (SCOOPS_TILEX+1)*TILE_SIZE;
            
        }   
    }else if(currentTexture == &gLibraryTexture){
        lev2.print();
        SDL_RenderCopy(gRenderer,currentTexture->getTexture(),NULL,NULL);
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
        dot.render(0,0);

        lev2.checkLibrary(dot,currentTexture);
        
        if(dot.getmPosX() >= (27)*TILE_SIZE && dot.getmPosY() >= (14)*TILE_SIZE){

            currentTexture = &gGameTexture;
            dot.mPosX = (LIB_TILEY+1)*TILE_SIZE;
            dot.mPosY = (LIB_TILEX+3)*TILE_SIZE;
            
        }   
    }

}