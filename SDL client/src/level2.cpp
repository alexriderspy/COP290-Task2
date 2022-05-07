#include <levels.hpp>

void level2(LTexture* &currentTexture,SDL_Rect &camera, Player &dot, Player &dot2, std::stringstream &timeText, int &timeLeft,std::stringstream &score,LTexture &p,SDL_Color &textColor, Text &textPoints, Text &lives, LTimer &timer, std::vector <Entity>&coins, std::vector<Ghost>&ghosts,Entity &winflag,Level2&lev2,int &tex_client, std::string &path){

    if(currentTexture == &gGameTexture){
        currentTexture->render(0,0,&camera);
        lev2.print();
        SDL_Rect renderQuad = {-camera.x,-camera.y,LEVEL_WIDTH,LEVEL_HEIGHT};
        SDL_RenderCopy(gRenderer,gMazeTexture.getTexture(),NULL,&renderQuad);
        
        if(dot.getmPosX()/TILE_SIZE == SCOOPS_TILEY && dot.getmPosY()/TILE_SIZE == SCOOPS_TILEX){

            lev2.checkSac(dot);

            currentTexture = &scoops;
            Mix_PlayChannel(-1,gEnterDarkness,0);
            dot.mPosX = (11)*TILE_SIZE;
            dot.mPosY = (14)*TILE_SIZE;
        }

        if(dot.hostel == "Himadri"  && dot.getmPosX()/TILE_SIZE == HOSTEL_HIM_TILEY && dot.getmPosY()/TILE_SIZE == HOSTEL_HIM_TILEX){

            
            lev2.checkSac(dot);


            currentTexture = &hos1;
            Mix_PlayChannel(-1,gEnterDarkness,0);
            dot.mPosX = (1)*TILE_SIZE;
            dot.mPosY = (14)*TILE_SIZE;
        }
        if(dot.hostel == "Kailash"  && dot.getmPosX()/TILE_SIZE == HOSTEL_KAILASH_TILEY && dot.getmPosY()/TILE_SIZE == HOSTEL_KAILASH_TILEX){

            
            lev2.checkSac(dot);


            currentTexture = &hos1;
            Mix_PlayChannel(-1,gEnterDarkness,0);
            dot.mPosX = (1)*TILE_SIZE;
            dot.mPosY = (14)*TILE_SIZE;
        }
        if(dot.hostel == "Girnar"  && dot.getmPosX()/TILE_SIZE == HOSTEL_GIRNAR_TILEY && dot.getmPosY()/TILE_SIZE == HOSTEL_GIRNAR_TILEX){

            
            lev2.checkSac(dot);

            currentTexture = &hos1;
            Mix_PlayChannel(-1,gEnterDarkness,0);
            dot.mPosX = (1)*TILE_SIZE;
            dot.mPosY = (14)*TILE_SIZE;
        }
        if(dot.hostel == "Karakoram"  && dot.getmPosX()/TILE_SIZE == HOSTEL_KARA_TILEY && dot.getmPosY()/TILE_SIZE == HOSTEL_KARA_TILEX){

            
            lev2.checkSac(dot);

            currentTexture = &hos1;
            Mix_PlayChannel(-1,gEnterDarkness,0);
            dot.mPosX = (1)*TILE_SIZE;
            dot.mPosY = (14)*TILE_SIZE;
        }
        if(dot.getmPosX()/TILE_SIZE == LIB_TILEY && dot.getmPosY()/TILE_SIZE == LIB_TILEX){

            
            lev2.checkSac(dot);

            currentTexture = &lib1;
            Mix_PlayChannel(-1,gEnterDarkness,0);
            dot.mPosX = (6)*TILE_SIZE;
            dot.mPosY = (14)*TILE_SIZE;
        }

        if(dot.getmPosX()/TILE_SIZE == SAC_TILEY && dot.getmPosY()/TILE_SIZE == SAC_TILEX){

            
            lev2.checkSac(dot);
            currentTexture = &sac1;
            dot.mPosX+=TILE_SIZE;
        }

        if(dot.getmPosX()/TILE_SIZE == lev2.pos_sac[3].first && dot.getmPosY()/TILE_SIZE == lev2.pos_sac[3].second){

            
            lev2.checkSac(dot);
            currentTexture = &sac2;
            dot.mPosY+=TILE_SIZE;
        }
        if(dot.getmPosX()/TILE_SIZE == lev2.pos_sac[4].first && dot.getmPosY()/TILE_SIZE == lev2.pos_sac[4].second){

            
            lev2.checkSac(dot);

            currentTexture = &r_gate;
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
        
        if(tex_client==0){
            dot2.lastTexture.loadFromFile(path);
            dot2.render(camera.x,camera.y);
        }
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
                dot.points -= 10;
            }
        }

        winflag.render(camera.x,camera.y);

        lev2.checkSac(dot);

        if(winflag.mPosX/TILE_SIZE == dot.getmPosX()/TILE_SIZE && winflag.mPosY/TILE_SIZE == dot.getmPosY()/TILE_SIZE){
            if(lev2.checkHostel(dot,currentTexture) && lev2.checkScoops(dot,currentTexture) && lev2.checkLibrary(dot,currentTexture) && lev2.checkSac(dot)){
                currentTexture=&gScoreBoardTexture;
            }
        }

    }else if(currentTexture == &gHostelTexture){
        lev2.print();
        SDL_RenderCopy(gRenderer,currentTexture->getTexture(),NULL,NULL);
        LTexture Bg;
        Bg.loadFromFile("res/maze_hostel.png");
        SDL_RenderCopy(gRenderer,Bg.getTexture(),NULL,NULL);

        if(dot.getmPosX()/TILE_SIZE == lev2.pos_hostel[0].first && dot.getmPosY()/TILE_SIZE == lev2.pos_hostel[0].second){

            lev2.checkHostel(dot,currentTexture);
            currentTexture = &hos2;
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
        if(tex_client==5){
            dot2.lastTexture.loadFromFile(path);
            dot2.render(0,0);
        }
        dot.render(0,0);

        lev2.checkHostel(dot,currentTexture);

        if(dot.getmPosX() >= (29)*TILE_SIZE && dot.getmPosY() >= (14)*TILE_SIZE){

            currentTexture = &r_scoops;
            if(dot.hostel == "Himadri"){

                
                dot.mPosX = (HOSTEL_HIM_TILEY)*TILE_SIZE;
                dot.mPosY = (HOSTEL_HIM_TILEX+1)*TILE_SIZE;
                
            }   
            if(dot.hostel == "Kailash"){

                
                dot.mPosX = (HOSTEL_KAILASH_TILEY)*TILE_SIZE;
                dot.mPosY = (HOSTEL_KAILASH_TILEX+1)*TILE_SIZE;
                
            }   
            if(dot.hostel == "Girnar"){

                
                dot.mPosX = (HOSTEL_GIRNAR_TILEY)*TILE_SIZE;
                dot.mPosY = (HOSTEL_GIRNAR_TILEX+1)*TILE_SIZE;
                
            }   
            if(dot.hostel == "Karakoram"){

                
                dot.mPosX = (HOSTEL_KARA_TILEY+1)*TILE_SIZE;
                dot.mPosY = (HOSTEL_KARA_TILEX+1)*TILE_SIZE;
                
            }
        }   
    }else if(currentTexture == &gScoopsTexture){
        lev2.print();
        SDL_RenderCopy(gRenderer,currentTexture->getTexture(),NULL,NULL);
        LTexture Bg;
        Bg.loadFromFile("res/maze_scoops.png");
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
        if(tex_client==2){
            dot2.lastTexture.loadFromFile(path);
            dot2.render(0,0);
        }
        dot.render(0,0);

        lev2.checkScoops(dot,currentTexture);
        
        if(dot.getmPosX() >= (18)*TILE_SIZE && dot.getmPosY() >= (14)*TILE_SIZE){


            currentTexture = &r_lib;
            dot.mPosX = (SCOOPS_TILEY-1)*TILE_SIZE;
            dot.mPosY = (SCOOPS_TILEX-1)*TILE_SIZE;
            
        }   
    }else if(currentTexture == &gLibraryTexture){
        lev2.print();
        SDL_RenderCopy(gRenderer,currentTexture->getTexture(),NULL,NULL);
        LTexture Bg;
        Bg.loadFromFile("res/maze_library.png");
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
        if(tex_client==4){
            dot2.lastTexture.loadFromFile(path);
            dot2.render(0,0);
        }
        dot.render(0,0);

        lev2.checkLibrary(dot,currentTexture);
        
        if(dot.getmPosX()/TILE_SIZE == lev2.pos_library[0].first && dot.getmPosY()/TILE_SIZE == lev2.pos_library[0].second){

            lev2.checkLibrary(dot,currentTexture);

            currentTexture = &lib2;
            dot.mPosX+=TILE_SIZE;
        }
        if(dot.getmPosX()/TILE_SIZE == lev2.pos_library[1].first && dot.getmPosY()/TILE_SIZE == lev2.pos_library[1].second){

            lev2.checkLibrary(dot,currentTexture);
            currentTexture = &lib3;            
            dot.mPosY+=TILE_SIZE;
        }


        if(dot.getmPosX() >= (24)*TILE_SIZE && dot.getmPosY() >= (14)*TILE_SIZE){


            currentTexture = &r_sac;
            dot.mPosX = (LIB_TILEY+1)*TILE_SIZE;
            dot.mPosY = (LIB_TILEX+1)*TILE_SIZE;
            
        }   
    }else if(currentTexture == &r_scoops){
        SDL_RenderCopy(gRenderer,currentTexture->getTexture(),NULL,NULL);
    }else if(currentTexture == &r_lib){
        SDL_RenderCopy(gRenderer,currentTexture->getTexture(),NULL,NULL);
    }else if(currentTexture == &r_sac){
        SDL_RenderCopy(gRenderer,currentTexture->getTexture(),NULL,NULL);
    }else if(currentTexture == &r_gate){
        SDL_RenderCopy(gRenderer,currentTexture->getTexture(),NULL,NULL);
    }else if(currentTexture == &hos1){
        SDL_RenderCopy(gRenderer,currentTexture->getTexture(),NULL,NULL);
    }else if(currentTexture == &hos2){
        SDL_RenderCopy(gRenderer,currentTexture->getTexture(),NULL,NULL);
    }else if(currentTexture == &scoops){
        SDL_RenderCopy(gRenderer,currentTexture->getTexture(),NULL,NULL);
    }else if(currentTexture == &lib1){
        SDL_RenderCopy(gRenderer,currentTexture->getTexture(),NULL,NULL);
    }else if(currentTexture == &lib2){
        SDL_RenderCopy(gRenderer,currentTexture->getTexture(),NULL,NULL);
    }else if(currentTexture == &lib3){
        SDL_RenderCopy(gRenderer,currentTexture->getTexture(),NULL,NULL);
    }else if(currentTexture == &sac1){
        SDL_RenderCopy(gRenderer,currentTexture->getTexture(),NULL,NULL);
    }else if(currentTexture == &sac2){
        SDL_RenderCopy(gRenderer,currentTexture->getTexture(),NULL,NULL);
    }

}