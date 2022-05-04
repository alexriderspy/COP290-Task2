#include <screens.hpp>

void choose(bool &renderText,LTexture* &currentTexture, std::string &inputText, SDL_Color &textColor){
    SDL_RenderCopy(gRenderer,currentTexture->getTexture(),NULL,NULL);
    gTextTexture.render( ( SCREEN_WIDTH - gTextTexture.getWidth() ) / 2, 0 );
    if(renderText){
        if(inputText != ""){
            gInputTextTexture.loadFromRenderedText(inputText.c_str(),textColor);
        }else{
            gInputTextTexture.loadFromRenderedText(" ",textColor);
        }
    }
    gInputTextTexture.render( ( SCREEN_WIDTH - gInputTextTexture.getWidth() ) / 2, gTextTexture.getHeight() );

}