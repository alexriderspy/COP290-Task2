#include<events.hpp>

void events(SDL_Event &e,std::string &inputText, bool &renderText, bool &quit, LTimer &timer, Player &dot, Player &dot2,LTexture * &currentTexture,SDL_Rect &camera,int &level,Entity&winflag,int &tex,std::string &path,int &tex_client, int &level_client){
        while( SDL_PollEvent( &e ) != 0 )
        {
            //User requests quit
            if( e.type == SDL_QUIT )
            {
                quit = true;

            }else if(e.type == SDL_KEYDOWN){
                if (currentTexture == &gScreen2Texture){
                    if(e.key.keysym.sym == SDLK_RETURN){
                        currentTexture = &gScreen2_2Texture;
                        
                    }   
                    else if(e.key.keysym.sym == SDLK_BACKSPACE && inputText.length() > 0){
                        inputText.pop_back();
                        renderText = true;
                    }else if(e.key.keysym.sym == SDLK_c && SDL_GetModState() & KMOD_CTRL){
                        SDL_SetClipboardText(inputText.c_str());
                    }else if( e.key.keysym.sym == SDLK_v && SDL_GetModState() & KMOD_CTRL){
                        inputText = SDL_GetClipboardText();
                        renderText = true;
                    }

                }else if(currentTexture == &gScreen2_2Texture){
                    if(e.key.keysym.sym == SDLK_1){
                        dot.hostel = "Karakoram";
                        currentTexture = &gScreen2_3Texture;
                    }else if(e.key.keysym.sym == SDLK_2){
                        dot.hostel = "Himadri";
                        currentTexture = &gScreen2_3Texture;
                    }else if(e.key.keysym.sym == SDLK_3){
                        dot.hostel = "Girnar";
                        currentTexture = &gScreen2_3Texture;
                    }else if(e.key.keysym.sym == SDLK_4){
                        dot.hostel = "Kailash";
                        currentTexture = &gScreen2_3Texture;
                    }              
                }else if(currentTexture == &gScreen2_3Texture){
                    if(e.key.keysym.sym == SDLK_a){
                        dot.playerDownTexture.loadFromFile("res/boy1_front.png");
                        dot.pathDown = "res/boy1_front.png";
                        dot.playerUpTexture.loadFromFile("res/boy1_back.png");
                        dot.pathUp = "res/boy1_back.png";
                        dot.playerLeftTexture.loadFromFile("res/boy1_left.png");
                        dot.pathLeft = "res/boy1_left.png";
                        dot.playerRightTexture.loadFromFile("res/boy1_right.png");
                        dot.pathRight = "res/boy1_right.png";
                        currentTexture = &gScreen2_4Texture;

                    }else if(e.key.keysym.sym == SDLK_b){
                        dot.playerDownTexture.loadFromFile("res/boy2_front.png");
                        dot.pathDown = "res/boy2_front.png";

                        dot.playerUpTexture.loadFromFile("res/boy2_back.png");
                        dot.pathUp = "res/boy2_back.png";
                        dot.playerLeftTexture.loadFromFile("res/boy2_left.png");
                        dot.pathLeft = "res/boy2_left.png";
                        dot.playerRightTexture.loadFromFile("res/boy2_right.png");
                        dot.pathRight = "res/boy2_right.png";
                        currentTexture = &gScreen2_4Texture;

                    }else if(e.key.keysym.sym == SDLK_c){
                        dot.playerDownTexture.loadFromFile("res/girl2_front.png");
                        dot.pathDown = "res/girl2_front.png";
                        dot.playerUpTexture.loadFromFile("res/girl2_back.png");
                        dot.pathUp = "res/girl2_back.png";
                        dot.playerLeftTexture.loadFromFile("res/girl2_left.png");
                        dot.pathLeft = "res/girl2_left.png";
                        dot.playerRightTexture.loadFromFile("res/girl2_right.png");
                        dot.pathRight = "res/girl2_right.png";
                        currentTexture = &gScreen2_4Texture;

                    }else if(e.key.keysym.sym == SDLK_d){
                        dot.playerDownTexture.loadFromFile("res/girl1_front.png");
                        dot.pathDown = "res/girl1_front.png";
                        dot.playerUpTexture.loadFromFile("res/girl1_back.png");
                        dot.pathUp = "res/girl1_back.png";
                        dot.playerLeftTexture.loadFromFile("res/girl1_left.png");
                        dot.pathLeft = "res/girl1_left.png";
                        dot.playerRightTexture.loadFromFile("res/girl1_right.png");
                        dot.pathRight = "res/girl1_right.png";
                        currentTexture = &gScreen2_4Texture;
                        
                    }              
                }else if(currentTexture == &gScreen2_4Texture){
                    if(e.key.keysym.sym == SDLK_e){
                        level = 1;
                        dot.mPosX = 95*TILE_SIZE;
                        dot.mPosY = 12*TILE_SIZE;
                        winflag.mPosX = 21*TILE_SIZE;
                        winflag.mPosY = 43*TILE_SIZE;
                        currentTexture = &gWordOfAdvice;

                    }else if(e.key.keysym.sym == SDLK_h){
                        level = 2;
                        if (dot.hostel == "Himadri"){
                            dot.mPosX = 113*TILE_SIZE;
                            dot.mPosY = 9*TILE_SIZE;

                        }else if(dot.hostel == "Kailash"){
                            dot.mPosX = 106*TILE_SIZE;
                            dot.mPosY = 14*TILE_SIZE;

                        }else if(dot.hostel == "Girnar"){
                            dot.mPosX = 54*TILE_SIZE;
                            dot.mPosY = 14*TILE_SIZE;

                        }else if(dot.hostel == "Karakoram"){
                            dot.mPosX = 13*TILE_SIZE;
                            dot.mPosY = 43*TILE_SIZE;

                        }
                        winflag.mPosX = 43*TILE_SIZE;
                        winflag.mPosY = 18*TILE_SIZE;
                        currentTexture = &gWordOfAdvice;

                    }              
                }else if(currentTexture == &gWordOfAdvice){
                    // if(level!=level_client){
                    //     currentTexture = &gGameOverTexture; 
                    //     SDL_Delay(2000);
                    //     quit = true;
                    // }
                    if(e.key.keysym.sym == SDLK_RETURN){


                        if(level == 1){

                            currentTexture = &r_lhc;
                        }else{
                            currentTexture = &r_hos;

                        }
                            Mix_PlayMusic(gMusic,-1);
                            timer.start();
                        
 
                    }
                }else if(currentTexture == &r_lhc){
                    if(e.key.keysym.sym == SDLK_RETURN){
                        currentTexture = &gGameTexture;
                    }
                }else if(currentTexture == &lhc1){
                    if(e.key.keysym.sym == SDLK_RETURN){
                        currentTexture = &gLHCTexture;
                    }
                }else if(currentTexture == &r_fb){
                    if(e.key.keysym.sym == SDLK_RETURN){
                        currentTexture = &gGameTexture;
                    }
                }else if(currentTexture == &lhc2){
                    if(e.key.keysym.sym == SDLK_RETURN){
                        currentTexture = &gLHCTexture;
                    }
                }else if(currentTexture == &lhc3){
                    if(e.key.keysym.sym == SDLK_RETURN){
                        currentTexture = &gLHCTexture;
                    }
                }else if(currentTexture == &lhc4){
                    if(e.key.keysym.sym == SDLK_RETURN){
                        currentTexture = &gLHCTexture;
                    }
                }else if(currentTexture == &r_sc){
                    if(e.key.keysym.sym == SDLK_RETURN){
                        currentTexture = &gGameTexture;
                    }
                }else if(currentTexture == &sc){
                    if(e.key.keysym.sym == SDLK_RETURN){
                        currentTexture = &gStaffCanteen;
                    }
                }else if(currentTexture == &fb){
                    if(e.key.keysym.sym == SDLK_RETURN){
                        currentTexture = &gGameTexture;
                    }
                }else if(currentTexture == &r_scoops){
                    if(e.key.keysym.sym == SDLK_RETURN){
                        currentTexture = &gGameTexture;
                    }
                }else if(currentTexture == &r_hos){
                    if(e.key.keysym.sym == SDLK_RETURN){
                        currentTexture = &gGameTexture;
                    }
                }else if(currentTexture == &r_lib){
                    if(e.key.keysym.sym == SDLK_RETURN){
                        currentTexture = &gGameTexture;
                    }
                }else if(currentTexture == &r_sac){
                    if(e.key.keysym.sym == SDLK_RETURN){
                        currentTexture = &gGameTexture;
                    }
                }else if(currentTexture == &r_gate){
                    if(e.key.keysym.sym == SDLK_RETURN){
                        currentTexture = &gGameTexture;
                    }
                }else if(currentTexture == &hos1){
                    if(e.key.keysym.sym == SDLK_RETURN){
                        currentTexture = &gHostelTexture;
                    }
                }else if(currentTexture == &hos2){
                    if(e.key.keysym.sym == SDLK_RETURN){
                        currentTexture = &gHostelTexture;
                    }
                }else if(currentTexture == &scoops){
                    if(e.key.keysym.sym == SDLK_RETURN){
                        currentTexture = &gScoopsTexture;
                    }
                }else if(currentTexture == &lib1){
                    if(e.key.keysym.sym == SDLK_RETURN){
                        currentTexture = &gLibraryTexture;
                    }
                }else if(currentTexture == &lib2){
                    if(e.key.keysym.sym == SDLK_RETURN){
                        currentTexture = &gLibraryTexture;
                    }
                }else if(currentTexture == &lib3){
                    if(e.key.keysym.sym == SDLK_RETURN){
                        currentTexture = &gLibraryTexture;
                    }
                }else if(currentTexture == &sac1){
                    if(e.key.keysym.sym == SDLK_RETURN){
                        currentTexture = &gGameTexture;
                    }
                }else if(currentTexture == &sac2){
                    if(e.key.keysym.sym == SDLK_RETURN){
                        currentTexture = &gGameTexture;
                    }
                }
            }
        
            else if(e.type == SDL_TEXTINPUT){
                    if(currentTexture == &gScreen2Texture){
                        if(!(SDL_GetModState() & KMOD_CTRL && (e.text.text[0] == 'c' || e.text.text[0] == 'C' || e.text.text[0] == 'v' || e.text.text[0] == 'V'))){
                            inputText += e.text.text;
                            renderText = true;
                            
                        }
                    }
            }
                if(currentTexture == &gGameTexture){
                    dot.render(e,camera.x,camera.y);
                }else if(currentTexture == &gLHCTexture || currentTexture == &gStaffCanteen ||currentTexture == &gHostelTexture || currentTexture == &gScoopsTexture  || currentTexture == &gLibraryTexture  ){
                    dot.render(e,0,0);
                }
                dot.handleEvent(e,currentTexture);
                dot.name = inputText;

                if(tex == tex_client && tex!=0){
                    dot2.lastTexture.loadFromFile(path);
                    dot2.render(0,0);
                }else if(tex == tex_client && tex==0){
                    dot2.lastTexture.loadFromFile(path);
                    dot2.render(camera.x,camera.y);
                }

        }

}