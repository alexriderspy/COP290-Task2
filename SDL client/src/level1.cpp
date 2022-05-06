#include <levels.hpp>

void level1(LTexture* &currentTexture,SDL_Rect &camera, Player &dot, Player &dot2, std::stringstream &timeText, int &timeLeft,std::stringstream &score,LTexture &p,SDL_Color &textColor, Text &textPoints, Text &lives, LTimer &timer, std::vector <Entity>&coins, std::vector<Ghost>&ghosts,Entity &winflag,Level1&lev1){

    if(currentTexture == &gGameTexture){
        currentTexture->render(0,0,&camera);
        lev1.print();
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

        lev1.checkFootball(dot);
        
        if(winflag.mPosX/TILE_SIZE == dot.getmPosX()/TILE_SIZE && winflag.mPosY/TILE_SIZE == dot.getmPosY()/TILE_SIZE){
            if(lev1.checkFootball(dot) && lev1.checkLHC(dot,currentTexture) && lev1.checkStaffCanteen(dot,currentTexture)){
                currentTexture=&gScoreBoardTexture;
            }
        }
        dot2.render(camera.x,camera.y);
        dot.render(camera.x,camera.y);

        //himadri
        SDL_Rect renderHimadri = {107*TILE_SIZE-camera.x,0*TILE_SIZE-camera.y,15*TILE_SIZE,9*TILE_SIZE};
        SDL_RenderCopy(gRenderer,gHimadriTexture.getTexture(),NULL,&renderHimadri);

        //kailash
        SDL_Rect renderKailash = {96*TILE_SIZE-camera.x,7*TILE_SIZE-camera.y,20*TILE_SIZE,12*TILE_SIZE};
        SDL_RenderCopy(gRenderer,gKailashTexture.getTexture(),NULL,&renderKailash);

        //lhc
        SDL_Rect renderLHC = {78*TILE_SIZE-camera.x,20*TILE_SIZE-camera.y,60*TILE_SIZE,30*TILE_SIZE};
        SDL_RenderCopy(gRenderer,gLHC_exTexture.getTexture(),NULL,&renderLHC);

        //girnar
        SDL_Rect renderGirnar = {47*TILE_SIZE-camera.x,4*TILE_SIZE-camera.y,14*TILE_SIZE,9*TILE_SIZE};
        SDL_RenderCopy(gRenderer,gGirnarTexture.getTexture(),NULL,&renderGirnar);

        //sac
        SDL_Rect renderSac = {10*TILE_SIZE-camera.x,30*TILE_SIZE-camera.y,25*TILE_SIZE,30*TILE_SIZE};
        SDL_RenderCopy(gRenderer,gSacTexture.getTexture(),NULL,&renderSac);
        
        //kara
        SDL_Rect renderKara = {(-5)*TILE_SIZE-camera.x,24*TILE_SIZE-camera.y,15*TILE_SIZE,25*TILE_SIZE};
        SDL_RenderCopy(gRenderer,gKaraTexture.getTexture(),NULL,&renderKara);

        // //girnar
        // SDL_Rect renderGirnar = {49*TILE_SIZE-camera.x,8*TILE_SIZE-camera.y,20*TILE_SIZE,12*TILE_SIZE};
        // SDL_RenderCopy(gRenderer,gGirnarTexture.getTexture(),NULL,&renderLHC);
        // //girnar
        // SDL_Rect renderGirnar = {49*TILE_SIZE-camera.x,8*TILE_SIZE-camera.y,20*TILE_SIZE,12*TILE_SIZE};
        // SDL_RenderCopy(gRenderer,gGirnarTexture.getTexture(),NULL,&renderLHC);
        // //girnar
        // SDL_Rect renderGirnar = {49*TILE_SIZE-camera.x,8*TILE_SIZE-camera.y,20*TILE_SIZE,12*TILE_SIZE};
        // SDL_RenderCopy(gRenderer,gGirnarTexture.getTexture(),NULL,&renderLHC);
        
    }else if(currentTexture == &gLHCTexture){
        lev1.print();
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

        if(dot.getmPosX() >= (25)*TILE_SIZE && dot.getmPosY() >= (14)*TILE_SIZE){

            currentTexture = &gGameTexture;
            dot.mPosX = (LHC_TILEY-3)*TILE_SIZE;
            dot.mPosY = (LHC_TILEX-1)*TILE_SIZE;
            
        }   
    }else if(currentTexture == &gStaffCanteen){
        lev1.print();
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
        
        if(dot.getmPosX() >= (27)*TILE_SIZE && dot.getmPosY() >= (14)*TILE_SIZE){

            currentTexture = &gGameTexture;
            dot.mPosX = (STAFF_TILEY-2)*TILE_SIZE;
            dot.mPosY = (STAFF_TILEX-2)*TILE_SIZE;
            
        }   
    }

}