#include<events.hpp>

void events(SDL_Event &e,std::string &inputText, bool &renderText, bool &quit, LTimer &timer, Player &dot, LTexture * &currentTexture){
        while( SDL_PollEvent( &e ) != 0 )
        {
            //User requests quit
            if( e.type == SDL_QUIT )
            {
                quit = true;

            }else if(e.type == SDL_KEYDOWN){
                if (currentTexture == &gEnterTexture){
                    if(e.key.keysym.sym == SDLK_RETURN){
                        currentTexture = &gGameTexture;
                        Mix_PlayMusic(gMusic,0);        
                    
                        timer.start();

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

                }
            }
        
            else if(e.type == SDL_TEXTINPUT){
                    if(currentTexture == &gEnterTexture){
                        if(!(SDL_GetModState() & KMOD_CTRL && (e.text.text[0] == 'c' || e.text.text[0] == 'C' || e.text.text[0] == 'v' || e.text.text[0] == 'V'))){
                            inputText += e.text.text;
                            renderText = true;
                            
                        }
                    }
            }

                dot.handleEvent(e,currentTexture);
                dot.name = inputText;
        }

}