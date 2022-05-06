#include <levels.hpp>

void level2(LTexture* &currentTexture,SDL_Rect &camera, Player &dot, Player &dot2, std::stringstream &timeText, int &timeLeft,std::stringstream &score,LTexture &p,SDL_Color &textColor, Text &textPoints, Text &lives, LTimer &timer, std::vector <Entity>&coins, std::vector<Ghost>&ghosts,Entity &winflag,Level2&lev2){

    if(currentTexture == &gGameTexture){
        currentTexture->render(0,0,&camera);
        lev2.print();
        SDL_Rect renderQuad = {-camera.x,-camera.y,LEVEL_WIDTH,LEVEL_HEIGHT};
        SDL_RenderCopy(gRenderer,gMazeTexture.getTexture(),NULL,&renderQuad);
        
        if(dot.getmPosX()/TILE_SIZE == SCOOPS_TILEY && dot.getmPosY()/TILE_SIZE == SCOOPS_TILEX){

            LTexture popUp;
            popUp.loadFromFile("res/scoops.png");
            SDL_Rect renderQuad = {400,200,SCREEN_WIDTH/2,SCREEN_HEIGHT/2};
            SDL_RenderCopy(gRenderer,popUp.getTexture(),NULL,&renderQuad);
            SDL_RenderPresent(gRenderer);
            SDL_Delay(8000);
            popUp.free();

            currentTexture = &gScoopsTexture;
            Mix_PlayChannel(-1,gEnterDarkness,0);
            dot.mPosX = (11)*TILE_SIZE;
            dot.mPosY = (14)*TILE_SIZE;
        }
        std::cout<<dot.getmPosX()/TILE_SIZE<<'\n';
        std::cout<<dot.getmPosY()/TILE_SIZE<<'\n';
        std::cout<<dot.hostel<<'\n';
        if(dot.hostel == "Himadri"  && dot.getmPosX()/TILE_SIZE == HOSTEL_HIM_TILEY && dot.getmPosY()/TILE_SIZE == HOSTEL_HIM_TILEX){

            LTexture popUp;
            popUp.loadFromFile("res/hostel1.png");
            SDL_Rect renderQuad = {400,200,SCREEN_WIDTH/2,SCREEN_HEIGHT/2};
            SDL_RenderCopy(gRenderer,popUp.getTexture(),NULL,&renderQuad);
            SDL_RenderPresent(gRenderer);
            SDL_Delay(8000);
            popUp.free();

            currentTexture = &gHostelTexture;
            Mix_PlayChannel(-1,gEnterDarkness,0);
            dot.mPosX = (1)*TILE_SIZE;
            dot.mPosY = (14)*TILE_SIZE;
        }
        if(dot.hostel == "Kailash"  && dot.getmPosX()/TILE_SIZE == HOSTEL_KAILASH_TILEY && dot.getmPosY()/TILE_SIZE == HOSTEL_KAILASH_TILEX){

            LTexture popUp;
            popUp.loadFromFile("res/hostel1.png");
            SDL_Rect renderQuad = {400,200,SCREEN_WIDTH/2,SCREEN_HEIGHT/2};
            SDL_RenderCopy(gRenderer,popUp.getTexture(),NULL,&renderQuad);
            SDL_RenderPresent(gRenderer);
            SDL_Delay(8000);
            popUp.free();

            currentTexture = &gHostelTexture;
            Mix_PlayChannel(-1,gEnterDarkness,0);
            dot.mPosX = (1)*TILE_SIZE;
            dot.mPosY = (14)*TILE_SIZE;
        }
        if(dot.hostel == "Girnar"  && dot.getmPosX()/TILE_SIZE == HOSTEL_GIRNAR_TILEY && dot.getmPosY()/TILE_SIZE == HOSTEL_GIRNAR_TILEX){

            LTexture popUp;
            popUp.loadFromFile("res/hostel1.png");
            SDL_Rect renderQuad = {400,200,SCREEN_WIDTH/2,SCREEN_HEIGHT/2};
            SDL_RenderCopy(gRenderer,popUp.getTexture(),NULL,&renderQuad);
            SDL_RenderPresent(gRenderer);
            SDL_Delay(8000);
            popUp.free();

            currentTexture = &gHostelTexture;
            Mix_PlayChannel(-1,gEnterDarkness,0);
            dot.mPosX = (1)*TILE_SIZE;
            dot.mPosY = (14)*TILE_SIZE;
        }
        if(dot.hostel == "Karakoram"  && dot.getmPosX()/TILE_SIZE == HOSTEL_KARA_TILEY && dot.getmPosY()/TILE_SIZE == HOSTEL_KARA_TILEX){

            LTexture popUp;
            popUp.loadFromFile("res/hostel1.png");
            SDL_Rect renderQuad = {400,200,SCREEN_WIDTH/2,SCREEN_HEIGHT/2};
            SDL_RenderCopy(gRenderer,popUp.getTexture(),NULL,&renderQuad);
            SDL_RenderPresent(gRenderer);
            SDL_Delay(8000);
            popUp.free();

            currentTexture = &gHostelTexture;
            Mix_PlayChannel(-1,gEnterDarkness,0);
            dot.mPosX = (1)*TILE_SIZE;
            dot.mPosY = (14)*TILE_SIZE;
        }
        if(dot.getmPosX()/TILE_SIZE == LIB_TILEY && dot.getmPosY()/TILE_SIZE == LIB_TILEX){

            LTexture popUp;
            popUp.loadFromFile("res/library1.png");
            SDL_Rect renderQuad = {400,200,SCREEN_WIDTH/2,SCREEN_HEIGHT/2};
            SDL_RenderCopy(gRenderer,popUp.getTexture(),NULL,&renderQuad);
            SDL_RenderPresent(gRenderer);
            SDL_Delay(8000);
            popUp.free();

            currentTexture = &gLibraryTexture;
            Mix_PlayChannel(-1,gEnterDarkness,0);
            dot.mPosX = (3)*TILE_SIZE;
            dot.mPosY = (14)*TILE_SIZE;
        }

        if(dot.getmPosX()/TILE_SIZE == LAWN_TILEY && dot.getmPosY()/TILE_SIZE == LAWN_TILEX){

            LTexture popUp;
            popUp.loadFromFile("res/biotech.png");
            SDL_Rect renderQuad = {400,200,SCREEN_WIDTH/2,SCREEN_HEIGHT/2};
            SDL_RenderCopy(gRenderer,popUp.getTexture(),NULL,&renderQuad);
            SDL_RenderPresent(gRenderer);
            SDL_Delay(8000);
            popUp.free();
            
        }

        if(dot.getmPosX()/TILE_SIZE == lev2.pos_lawn[0].first && dot.getmPosY()/TILE_SIZE == lev2.pos_lawn[0].second){

            LTexture popUp;
            popUp.loadFromFile("res/congrats.png");
            SDL_Rect renderQuad = {400,200,SCREEN_WIDTH/2,SCREEN_HEIGHT/2};
            SDL_RenderCopy(gRenderer,popUp.getTexture(),NULL,&renderQuad);
            SDL_RenderPresent(gRenderer);
            SDL_Delay(2000);
            popUp.free();

            dot.mPosX-=TILE_SIZE;
            
        }
        if(dot.getmPosX()/TILE_SIZE == lev2.pos_lawn[1].first && dot.getmPosY()/TILE_SIZE == lev2.pos_lawn[1].second){

            LTexture popUp;
            popUp.loadFromFile("res/congrats.png");
            SDL_Rect renderQuad = {400,200,SCREEN_WIDTH/2,SCREEN_HEIGHT/2};
            SDL_RenderCopy(gRenderer,popUp.getTexture(),NULL,&renderQuad);
            SDL_RenderPresent(gRenderer);
            SDL_Delay(2000);
            popUp.free();

            dot.mPosX-=TILE_SIZE;
            
        }
        if(dot.getmPosX()/TILE_SIZE == lev2.pos_lawn[2].first && dot.getmPosY()/TILE_SIZE == lev2.pos_lawn[2].second){

            LTexture popUp;
            popUp.loadFromFile("res/Blank.png");
            SDL_Rect renderQuad = {400,200,SCREEN_WIDTH/2,SCREEN_HEIGHT/2};
            SDL_RenderCopy(gRenderer,popUp.getTexture(),NULL,&renderQuad);
            SDL_RenderPresent(gRenderer);
            SDL_Delay(2000);
            popUp.free();
            
            dot.mPosY+=TILE_SIZE;
        }
        if(dot.getmPosX()/TILE_SIZE == SAC_TILEY && dot.getmPosY()/TILE_SIZE == SAC_TILEX){

            LTexture popUp;
            popUp.loadFromFile("res/SAC1.png");
            SDL_Rect renderQuad = {400,200,SCREEN_WIDTH/2,SCREEN_HEIGHT/2};
            SDL_RenderCopy(gRenderer,popUp.getTexture(),NULL,&renderQuad);
            SDL_RenderPresent(gRenderer);
            SDL_Delay(8000);
            popUp.free();
            dot.mPosX+=TILE_SIZE;
        }

        if(dot.getmPosX()/TILE_SIZE == lev2.pos_sac[0].first && dot.getmPosY()/TILE_SIZE == lev2.pos_sac[0].second){

            LTexture popUp;
            popUp.loadFromFile("res/congrats.png");
            SDL_Rect renderQuad = {400,200,SCREEN_WIDTH/2,SCREEN_HEIGHT/2};
            SDL_RenderCopy(gRenderer,popUp.getTexture(),NULL,&renderQuad);
            SDL_RenderPresent(gRenderer);
            SDL_Delay(2000);
            popUp.free();
            dot.mPosX+=TILE_SIZE;
        }
        if(dot.getmPosX()/TILE_SIZE == lev2.pos_sac[1].first && dot.getmPosY()/TILE_SIZE == lev2.pos_sac[1].second){

            LTexture popUp;
            popUp.loadFromFile("res/congrats.png");
            SDL_Rect renderQuad = {400,200,SCREEN_WIDTH/2,SCREEN_HEIGHT/2};
            SDL_RenderCopy(gRenderer,popUp.getTexture(),NULL,&renderQuad);
            SDL_RenderPresent(gRenderer);
            SDL_Delay(2000);
            popUp.free();
            dot.mPosY+=TILE_SIZE;
        }
        if(dot.getmPosX()/TILE_SIZE == lev2.pos_sac[2].first && dot.getmPosY()/TILE_SIZE == lev2.pos_sac[2].second){

            LTexture popUp;
            popUp.loadFromFile("res/congrats.png");
            SDL_Rect renderQuad = {400,200,SCREEN_WIDTH/2,SCREEN_HEIGHT/2};
            SDL_RenderCopy(gRenderer,popUp.getTexture(),NULL,&renderQuad);
            SDL_RenderPresent(gRenderer);
            SDL_Delay(2000);
            popUp.free();
            dot.mPosX-=TILE_SIZE;
        }
        if(dot.getmPosX()/TILE_SIZE == lev2.pos_sac[3].first && dot.getmPosY()/TILE_SIZE == lev2.pos_sac[3].second){

            LTexture popUp;
            popUp.loadFromFile("res/SAC2.png");
            SDL_Rect renderQuad = {400,200,SCREEN_WIDTH/2,SCREEN_HEIGHT/2};
            SDL_RenderCopy(gRenderer,popUp.getTexture(),NULL,&renderQuad);
            SDL_RenderPresent(gRenderer);
            SDL_Delay(2000);
            popUp.free();
            dot.mPosY+=TILE_SIZE;
        }
        if(dot.getmPosX()/TILE_SIZE == lev2.pos_sac[4].first && dot.getmPosY()/TILE_SIZE == lev2.pos_sac[4].second){

            LTexture popUp;
            popUp.loadFromFile("res/gate.png");
            SDL_Rect renderQuad = {400,200,SCREEN_WIDTH/2,SCREEN_HEIGHT/2};
            SDL_RenderCopy(gRenderer,popUp.getTexture(),NULL,&renderQuad);
            SDL_RenderPresent(gRenderer);
            SDL_Delay(2000);
            popUp.free();
            dot.mPosX-=2*TILE_SIZE;
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

        if(dot.getmPosX()/TILE_SIZE == lev2.pos_hostel[0].first && dot.getmPosY()/TILE_SIZE == lev2.pos_hostel[0].second){

            LTexture popUp;
            popUp.loadFromFile("res/hostel2.png");
            SDL_Rect renderQuad = {400,200,SCREEN_WIDTH/2,SCREEN_HEIGHT/2};
            SDL_RenderCopy(gRenderer,popUp.getTexture(),NULL,&renderQuad);
            SDL_RenderPresent(gRenderer);
            SDL_Delay(8000);
            popUp.free();

            dot.mPosX+=TILE_SIZE;
        }

        if(dot.getmPosX()/TILE_SIZE == lev2.pos_hostel[1].first && dot.getmPosY()/TILE_SIZE == lev2.pos_hostel[1].second){

            LTexture popUp;
            popUp.loadFromFile("res/congrats.png");
            SDL_Rect renderQuad = {400,200,SCREEN_WIDTH/2,SCREEN_HEIGHT/2};
            SDL_RenderCopy(gRenderer,popUp.getTexture(),NULL,&renderQuad);
            SDL_RenderPresent(gRenderer);
            SDL_Delay(1000);
            popUp.free();

            dot.mPosX+=TILE_SIZE;
        }

        if(dot.getmPosX()/TILE_SIZE == lev2.pos_hostel[2].first && dot.getmPosY()/TILE_SIZE == lev2.pos_hostel[2].second){

            LTexture popUp;
            popUp.loadFromFile("res/congrats.png");
            SDL_Rect renderQuad = {400,200,SCREEN_WIDTH/2,SCREEN_HEIGHT/2};
            SDL_RenderCopy(gRenderer,popUp.getTexture(),NULL,&renderQuad);
            SDL_RenderPresent(gRenderer);
            SDL_Delay(1000);
            popUp.free();

            dot.mPosX+=TILE_SIZE;
        }

        if(dot.getmPosX()/TILE_SIZE == lev2.pos_hostel[3].first && dot.getmPosY()/TILE_SIZE == lev2.pos_hostel[3].second){

            LTexture popUp;
            popUp.loadFromFile("res/congrats.png");
            SDL_Rect renderQuad = {400,200,SCREEN_WIDTH/2,SCREEN_HEIGHT/2};
            SDL_RenderCopy(gRenderer,popUp.getTexture(),NULL,&renderQuad);
            SDL_RenderPresent(gRenderer);
            SDL_Delay(1000);
            popUp.free();
            dot.mPosX+=TILE_SIZE;
        }

        if(dot.getmPosX()/TILE_SIZE == lev2.pos_hostel[4].first && dot.getmPosY()/TILE_SIZE == lev2.pos_hostel[4].second){

            LTexture popUp;
            popUp.loadFromFile("res/congrats.png");
            SDL_Rect renderQuad = {400,200,SCREEN_WIDTH/2,SCREEN_HEIGHT/2};
            SDL_RenderCopy(gRenderer,popUp.getTexture(),NULL,&renderQuad);
            SDL_RenderPresent(gRenderer);
            SDL_Delay(1000);
            popUp.free();
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
        dot.render(0,0);

        lev2.checkHostel(dot,currentTexture);
        if(dot.getmPosX() >= (29)*TILE_SIZE && dot.getmPosY() >= (14)*TILE_SIZE){

            LTexture popUp;
            popUp.loadFromFile("res/Blank.png");
            SDL_Rect renderQuad = {400,200,SCREEN_WIDTH/2,SCREEN_HEIGHT/2};
            SDL_RenderCopy(gRenderer,popUp.getTexture(),NULL,&renderQuad);
            SDL_RenderPresent(gRenderer);
            SDL_Delay(8000);
            popUp.free();

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

        if(dot.getmPosX()/TILE_SIZE == lev2.pos_scoops[0].first && dot.getmPosY()/TILE_SIZE == lev2.pos_scoops[0].second){

            LTexture popUp;
            popUp.loadFromFile("res/congrats.png");
            SDL_Rect renderQuad = {400,200,SCREEN_WIDTH/2,SCREEN_HEIGHT/2};
            SDL_RenderCopy(gRenderer,popUp.getTexture(),NULL,&renderQuad);
            SDL_RenderPresent(gRenderer);
            SDL_Delay(1000);
            popUp.free();
            dot.mPosX+=TILE_SIZE;
        }

        if(dot.getmPosX()/TILE_SIZE == lev2.pos_scoops[1].first && dot.getmPosY()/TILE_SIZE == lev2.pos_scoops[1].second){

            LTexture popUp;
            popUp.loadFromFile("res/congrats.png");
            SDL_Rect renderQuad = {400,200,SCREEN_WIDTH/2,SCREEN_HEIGHT/2};
            SDL_RenderCopy(gRenderer,popUp.getTexture(),NULL,&renderQuad);
            SDL_RenderPresent(gRenderer);
            SDL_Delay(1000);
            popUp.free();
            dot.mPosX-=TILE_SIZE;
        }

        if(dot.getmPosX()/TILE_SIZE == lev2.pos_scoops[2].first && dot.getmPosY()/TILE_SIZE == lev2.pos_scoops[2].second){

            LTexture popUp;
            popUp.loadFromFile("res/congrats.png");
            SDL_Rect renderQuad = {400,200,SCREEN_WIDTH/2,SCREEN_HEIGHT/2};
            SDL_RenderCopy(gRenderer,popUp.getTexture(),NULL,&renderQuad);
            SDL_RenderPresent(gRenderer);
            SDL_Delay(1000);
            popUp.free();
            dot.mPosY+=TILE_SIZE;
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
        dot.render(0,0);

        lev2.checkScoops(dot,currentTexture);
        
        if(dot.getmPosX() >= (18)*TILE_SIZE && dot.getmPosY() >= (14)*TILE_SIZE){

            LTexture popUp;
            popUp.loadFromFile("res/Riddle_library.png");
            SDL_Rect renderQuad = {400,200,SCREEN_WIDTH/2,SCREEN_HEIGHT/2};
            SDL_RenderCopy(gRenderer,popUp.getTexture(),NULL,&renderQuad);
            SDL_RenderPresent(gRenderer);
            SDL_Delay(8000);
            popUp.free();

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
        
        if(dot.getmPosX()/TILE_SIZE == lev2.pos_library[0].first && dot.getmPosY()/TILE_SIZE == lev2.pos_library[0].second){

            LTexture popUp;
            popUp.loadFromFile("res/library2.png");
            SDL_Rect renderQuad = {400,200,SCREEN_WIDTH/2,SCREEN_HEIGHT/2};
            SDL_RenderCopy(gRenderer,popUp.getTexture(),NULL,&renderQuad);
            SDL_RenderPresent(gRenderer);
            SDL_Delay(8000);
            popUp.free();

            dot.mPosX+=TILE_SIZE;
        }
        if(dot.getmPosX()/TILE_SIZE == lev2.pos_library[1].first && dot.getmPosY()/TILE_SIZE == lev2.pos_library[1].second){

            LTexture popUp;
            popUp.loadFromFile("res/library3.png");
            SDL_Rect renderQuad = {400,200,SCREEN_WIDTH/2,SCREEN_HEIGHT/2};
            SDL_RenderCopy(gRenderer,popUp.getTexture(),NULL,&renderQuad);
            SDL_RenderPresent(gRenderer);
            SDL_Delay(8000);
            popUp.free();
            dot.mPosY+=TILE_SIZE;
        }

        if(dot.getmPosX()/TILE_SIZE == lev2.pos_library[2].first && dot.getmPosY()/TILE_SIZE == lev2.pos_library[2].second){

            LTexture popUp;
            popUp.loadFromFile("res/congrats.png");
            SDL_Rect renderQuad = {400,200,SCREEN_WIDTH/2,SCREEN_HEIGHT/2};
            SDL_RenderCopy(gRenderer,popUp.getTexture(),NULL,&renderQuad);
            SDL_RenderPresent(gRenderer);
            SDL_Delay(1000);
            popUp.free();

            dot.mPosX-=TILE_SIZE;
        }

        if(dot.getmPosX() >= (27)*TILE_SIZE && dot.getmPosY() >= (14)*TILE_SIZE){

            LTexture popUp;
            popUp.loadFromFile("res/Blank.png");
            SDL_Rect renderQuad = {400,200,SCREEN_WIDTH/2,SCREEN_HEIGHT/2};
            SDL_RenderCopy(gRenderer,popUp.getTexture(),NULL,&renderQuad);
            SDL_RenderPresent(gRenderer);
            SDL_Delay(8000);
            popUp.free();

            currentTexture = &gGameTexture;
            dot.mPosX = (LIB_TILEY+1)*TILE_SIZE;
            dot.mPosY = (LIB_TILEX+3)*TILE_SIZE;
            
        }   
    }

}