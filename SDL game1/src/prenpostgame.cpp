#include <prenpostgame.hpp>
#include <iostream>

bool init()
{
    //Initialization flag
    bool success = true;

    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO | SDL_INIT_AUDIO ) < 0 )
    {
        printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
        success = false;
    }
    else
    {
        //Set texture filtering to linear
        if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
        {
            printf( "Warning: Linear texture filtering not enabled!" );
        }

        //Create window
        gWindow = SDL_CreateWindow( "DR Racing", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        if( gWindow == NULL )
        {
            printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
            success = false;
        }
        else
        {
            //Create vsynced renderer for window
            gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
            if( gRenderer == NULL )
            {
                printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
                success = false;
            }
            else
            {
                //Initialize renderer color
                SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

                //Initialize PNG loading
                int imgFlags = IMG_INIT_PNG;
                if( !( IMG_Init( imgFlags ) & imgFlags ) )
                {
                    printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
                    success = false;
                }

                if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT,2,2048) < 0){
                    std::cout<<"SDL_mixer can't be initialized "<<Mix_GetError()<<'\n';
                    success=false;
                }
                if ( TTF_Init() == -1){
                    std::cout<<"font can't be initialized "<<TTF_GetError()<<'\n';
                    success=false;
                }
            }
        }
    }

    return success;
}

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
