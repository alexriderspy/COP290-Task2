#include <screens.hpp>

void choose(bool &renderText,LTexture* &currentTexture, std::string &inputText, SDL_Color &textColor){
    SDL_RenderCopy(gRenderer,currentTexture->getTexture(),NULL,NULL);
    if(renderText){
        if(inputText != ""){
            gInputTextTexture.loadFromRenderedText(inputText.c_str(),textColor);
        }else{
            gInputTextTexture.loadFromRenderedText(" ",textColor);
        }
    }
    gInputTextTexture.render(300,300 );

}