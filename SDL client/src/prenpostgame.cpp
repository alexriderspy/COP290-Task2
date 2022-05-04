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
        gWindow = SDL_CreateWindow( "Night Core", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
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
        SDL_Color textColor = { 0, 0xFF, 0xFF };
        if( !gTextTexture.loadFromRenderedText( "Choose your hostel: a) Udaigiri b) Kailash Press Enter to continue;", textColor ) ){
            printf( "Failed to render text texture!\n" );
            success = false;
        }
        if( !gLoading1Texture.loadFromRenderedText( "Loading . ", textColor ) ){
            printf( "Failed to render text texture!\n" );
            success = false;
        }
        if( !gLoading2Texture.loadFromRenderedText( "Loading . . ", textColor ) ){
            printf( "Failed to render text texture!\n" );
            success = false;
        }
        if( !gLoading3Texture.loadFromRenderedText( "Loading . . . ", textColor ) ){
            printf( "Failed to render text texture!\n" );
            success = false;
        }


    }

    //Load screen1 texture
    if( !gScreen1Texture.loadFromFile( "res/titleScreen.png" ) )
    {
        printf( "Failed to load screen1 texture!\n" );
        success = false;
    }
    
    if( !gEnterTexture.loadFromFile( "res/Blank.png" ) )
    {
        printf( "Failed to load blank texture!\n" );
        success = false;
    }

    if( !gMazeTexture.loadFromFile( "res/mazeImage.png" ) )
    {
        printf( "Failed to load blank texture!\n" );
        success = false;
    }

    SDL_Texture* tex = get_map_texture(gRenderer);
    if(!tex){
        printf("can't load map texture");
        success=false;
    }

    save_texture(gRenderer,tex,"res/maze.png");
    
    SDL_Texture* texLHC = get_mapLHC_texture(gRenderer);
    if(!texLHC){
        printf("can't load map texture");
        success=false;
    }

    save_texture(gRenderer,texLHC,"res/mazeLHC.png");

    SDL_Texture* texStaffCanteen = get_mapStaffCanteen_texture(gRenderer);
    if(!texStaffCanteen){
        printf("can't load map texture");
        success=false;
    }

    save_texture(gRenderer,texStaffCanteen,"res/mazeStaffCanteen.png");

    if( !gGameTexture.loadFromFile( "res/maze.png" ) )
    {
        printf( "Failed to load screen1 texture!\n" );
        success = false;
    }

    if( !gPlayerTexture.loadFromFile( "res/char1_up.png" ) )
    {
        printf( "Failed to load character1 texture!\n" );
        success = false;
    }

    if( !gLHCTexture.loadFromFile( "res/mazeLHC.png" ) )
    {
        printf( "Failed to load character1 texture!\n" );
        success = false;
    }

    if( !gStaffCanteen.loadFromFile( "res/mazeStaffCanteen.png" ) )
    {
        printf( "Failed to load character1 texture!\n" );
        success = false;
    }

    if( !gCoinTexture.loadFromFile( "res/coin.png" ) )
    {
        printf( "Failed to load coin texture!\n" );
        success = false;
    }

    if( !gFlagTexture.loadFromFile( "res/flag.png" ) )
    {
        printf( "Failed to load flag texture!\n" );
        success = false;
    }

    if( !gGhostTexture.loadFromFile( "res/ghost.png" ) )
    {
        printf( "Failed to load ghost texture!\n" );
        success = false;
    }

    if( !gScoreBoardTexture.loadFromFile( "res/winscreen.png" ) )
    {
        printf( "Failed to load flag texture!\n" );
        success = false;
    }

    if( !gGameOverTexture.loadFromFile( "res/gameover.png" ) )
    {
        printf( "Failed to load gameover texture!\n" );
        success = false;
    }

    gMusic = Mix_LoadMUS("res/DARKNESS.mp3");
    if (gMusic == NULL){
        std::cout<<"failed to load music "<<Mix_GetError()<<'\n';
        success = false;
    }   
     
    gArm = Mix_LoadWAV("res/gasping_zombie.wav");
    if (gArm == NULL){
        std::cout<<"failed to load beat "<<Mix_GetError()<<'\n';
        success = false;
    }   

    gCreature = Mix_LoadWAV("res/creature.wav");
    if (gCreature == NULL){
        std::cout<<"failed to load beat "<<Mix_GetError()<<'\n';
        success = false;
    }   

    gBlood = Mix_LoadWAV("res/blood_splash.wav");
    if (gBlood == NULL){
        std::cout<<"failed to load beat "<<Mix_GetError()<<'\n';
        success = false;
    }   

    gEnterDarkness = Mix_LoadWAV("res/enter_darkness.wav");
    if (gEnterDarkness == NULL){
        std::cout<<"failed to load beat "<<Mix_GetError()<<'\n';
        success = false;
    }   

    return success;

}

void close()
{
    //Free loaded images
    gScreen1Texture.free();
    gGameTexture.free();
    gMazeTexture.free();
    gLHCTexture.free();
    gStaffCanteen.free();

    gTimeTextTexture.free();
    gPlayerTexture.free();
    gCoinTexture.free();
    gScoreBoardTexture.free();

    Mix_FreeChunk(gArm);
    gArm = NULL;

    Mix_FreeChunk(gCreature);
    gCreature = NULL;

    Mix_FreeChunk(gBlood);
    gBlood = NULL;

    Mix_FreeChunk(gEnterDarkness);
    gEnterDarkness = NULL;

    Mix_FreeMusic(gMusic);
    gMusic = NULL;
    
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
