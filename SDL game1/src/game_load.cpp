#include <pregame.hpp>

#include <iostream>

bool loadMedia()
{
    //Loading success flag
    bool success = true;

    gFont = TTF_OpenFont( "res/SF Atarian System.ttf", 28 );
    if( gFont == NULL )
    {
        printf( "Failed to load lazy font! SDL_ttf Error: %s\n", TTF_GetError() );
        success = false;
    }
    else
    {
        //Render text
        SDL_Color textColor = { 0xFF, 0xFF, 0xFF };
        if( !gTextTexture.loadFromRenderedText( "Choose your hostel: a) Udaigiri b) Kailash Press Enter to continue;", textColor ) )
        {
            printf( "Failed to render text texture!\n" );
            success = false;
        }

    }

    //Load screen1 texture
    if( !gScreen1Texture.loadFromFile( "res/screen1.png" ) )
    {
        printf( "Failed to load screen1 texture!\n" );
        success = false;
    }
    
    //Load screen2 texture
    if( !gScreen2Texture.loadFromFile( "res/screen2.png" ) )
    {
        printf( "Failed to load screen2 texture!\n" );
        success = false;
    }

    SDL_Texture* tex = get_map_texture(gRenderer);
    if(!tex){
        printf("can't load map texture");
        success=false;
    }

    save_texture(gRenderer,tex,"res/maze.png");
    

    if( !gGameTexture.loadFromFile( "res/maze.png" ) )
    {
        printf( "Failed to load screen1 texture!\n" );
        success = false;
    }

    if( !gCharacterTexture.loadFromFile( "res/character1.png" ) )
    {
        printf( "Failed to load character1 texture!\n" );
        success = false;
    }

    if( !gCoinTexture.loadFromFile( "res/coin.png" ) )
    {
        printf( "Failed to load character1 texture!\n" );
        success = false;
    }

    if( !gFlagTexture.loadFromFile( "res/flag.png" ) )
    {
        printf( "Failed to load flag texture!\n" );
        success = false;
    }

    if( !gScoreBoardTexture.loadFromFile( "res/winscreen.png" ) )
    {
        printf( "Failed to load flag texture!\n" );
        success = false;
    }

    gMusic = Mix_LoadMUS("res/beat.wav");
    if (gMusic == NULL){
        std::cout<<"failed to load beat "<<Mix_GetError()<<'\n';
        success = false;
    }   
     
    gScratch = Mix_LoadWAV("res/beat.wav");
    if (gScratch == NULL){
        std::cout<<"failed to load beat "<<Mix_GetError()<<'\n';
        success = false;
    }   

    return success;

}
