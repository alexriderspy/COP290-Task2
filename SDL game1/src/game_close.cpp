#include <pregame.hpp>

void close()
{
    //Free loaded images
    gScreen1Texture.free();
    gScreen2Texture.free();
    gGameTexture.free();
    gTimeTextTexture.free();
    gCharacterTexture.free();
    gCoinTexture.free();
    gScoreBoardTexture.free();

    Mix_FreeChunk(gScratch);
    gScratch = NULL;

    Mix_FreeMusic(gMusic);
    gScratch = NULL;

    TTF_CloseFont(gFont);
    gFont = NULL;

    //Destroy window    
    SDL_DestroyRenderer( gRenderer );
    SDL_DestroyWindow( gWindow );
    gWindow = NULL;
    gRenderer = NULL;

    //Quit SDL subsystems
    Mix_Quit();
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();

}
