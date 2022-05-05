#include <levels.hpp>

void level1(LTexture* &currentTexture,SDL_Rect &camera, Player &dot, Player &dot2, std::stringstream &timeText, int &timeLeft,std::stringstream &score,LTexture &p,SDL_Color &textColor, Text &textPoints, Text &lives, LTimer &timer, std::vector <Entity>&coins, std::vector<Ghost>&ghosts,Entity &winflag,Level1&lev1){

    if(currentTexture == &gGameTexture){
        currentTexture->render(0,0,&camera);
        lev1.print();
        // SDL_Rect renderQuad = {-camera.x,-camera.y,LEVEL_WIDTH,LEVEL_HEIGHT};
        // SDL_RenderCopy(gRenderer,gMazeTexture.getTexture(),NULL,&renderQuad);
        
        //to go to lhc
        if(dot.getmPosX()/TILE_SIZE == LHC_TILEY && dot.getmPosY()/TILE_SIZE == LHC_TILEX){
            currentTexture = &gLHCTexture;
            Mix_PlayChannel(-1,gEnterDarkness,0);
            dot.mPosX = (MAPLHC_WIDTH-2)*TILE_SIZE;
            dot.mPosY = (MAPLHC_HEIGHT-1)*TILE_SIZE;
        }

        if(dot.getmPosX()/TILE_SIZE == STAFF_TILEY && dot.getmPosY()/TILE_SIZE == STAFF_TILEX){
            currentTexture = &gStaffCanteen;
            Mix_PlayChannel(-1,gEnterDarkness,0);
            dot.mPosX = (MAPSTAFF_WIDTH-2)*TILE_SIZE;
            dot.mPosY = (MAPSTAFF_HEIGHT-1)*TILE_SIZE;
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

        if(winflag.mPosX/TILE_SIZE == dot.getmPosX()/TILE_SIZE && winflag.mPosY/TILE_SIZE == dot.getmPosY()/TILE_SIZE){
            if(lev1.checkFootball(dot) && lev1.checkLHC(dot,currentTexture) && lev1.checkStaffCanteen(dot,currentTexture)){
                currentTexture=&gScoreBoardTexture;
            }
        }
        dot2.render(camera.x,camera.y);
        dot.render(camera.x,camera.y);

        SDL_Rect renderHimadri = {107*TILE_SIZE-camera.x,0*TILE_SIZE-camera.y,15*TILE_SIZE,10*TILE_SIZE};
        SDL_RenderCopy(gRenderer,gHimadriTexture.getTexture(),NULL,&renderHimadri);

        
    }else if(currentTexture == &gLHCTexture){
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

        lev1.checkLHC(dot,currentTexture);

        if(dot.getmPosX() >= (MAPLHC_WIDTH-1)*TILE_SIZE && dot.getmPosY() >= (MAPLHC_HEIGHT-1)*TILE_SIZE){

            currentTexture = &gGameTexture;
            dot.mPosX = (LHC_TILEY+1)*TILE_SIZE;
            dot.mPosY = LHC_TILEX*TILE_SIZE;
            
        }   
    }else if(currentTexture == &gStaffCanteen){
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

        lev1.checkStaffCanteen(dot,currentTexture);
        
        if(dot.getmPosX() >= (MAPSTAFF_WIDTH-1)*TILE_SIZE && dot.getmPosY() >= (MAPSTAFF_HEIGHT-1)*TILE_SIZE){

            currentTexture = &gGameTexture;
            dot.mPosX = (STAFF_TILEY+1)*TILE_SIZE;
            dot.mPosY = STAFF_TILEX*TILE_SIZE;
            
        }   
    }

}