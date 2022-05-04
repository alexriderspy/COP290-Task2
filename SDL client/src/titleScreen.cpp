#include <screens.hpp>

void title(int &flagLoading, LTexture* &currentTexture, int &timeLeft, LTimer &timerLoading){
    SDL_RenderCopy(gRenderer,currentTexture->getTexture(),NULL,NULL);
    if(flagLoading == 0)
        gLoading1Texture.render(0,0);
    else if(flagLoading==1)
        gLoading2Texture.render(0,0);
    else if(flagLoading==2)
        gLoading3Texture.render(0,0);

    timeLeft = SCREEN1_TIME - timerLoading.getTicks()/1000;


    if(timeLeft==0){
        if(flagLoading==0){
                gLoading2Texture.render(0,0);
                timerLoading.start();
                flagLoading++;
                
            }
        else if(flagLoading==1){
                gLoading3Texture.render(0,0);
                timerLoading.start();
                flagLoading++;
                
            }
        else if(flagLoading==2){
                currentTexture=&gEnterTexture;
                
            }
        }

}