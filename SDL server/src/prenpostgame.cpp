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
    
    if( !gScreen2Texture.loadFromFile( "res/screen2.png" ) )
    {
        printf( "Failed to load blank texture!\n" );
        success = false;
    }
    if( !gScreen2_2Texture.loadFromFile( "res/screen2_2.png" ) )
    {
        printf( "Failed to load blank texture!\n" );
        success = false;
    }
    if( !gScreen2_3Texture.loadFromFile( "res/screen2_3.png" ) )
    {
        printf( "Failed to load blank texture!\n" );
        success = false;
    }
    if( !gScreen2_4Texture.loadFromFile( "res/screen2_4.png" ) )
    {
        printf( "Failed to load blank texture!\n" );
        success = false;
    }

    if( !gMazeTexture.loadFromFile( "res/background.png" ) )
    {
        printf( "Failed to load blank texture!\n" );
        success = false;
    }

    if( !gWordOfAdvice.loadFromFile( "res/wordofadvice.png" ) )
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

    SDL_Texture* texHostel = get_mapHostel_texture(gRenderer);
    if(!texHostel){
        printf("can't load map texture");
        success=false;
    }

    save_texture(gRenderer,texHostel,"res/mazeHostel.png");

    SDL_Texture* texLibrary = get_mapLibrary_texture(gRenderer);
    if(!texLibrary){
        printf("can't load map texture");
        success=false;
    }

    save_texture(gRenderer,texLibrary,"res/mazeLibrary.png");

    SDL_Texture* texScoops = get_mapScoops_texture(gRenderer);
    if(!texScoops){
        printf("can't load map texture");
        success=false;
    }

    save_texture(gRenderer,texScoops,"res/mazeScoops.png");

    if( !gGameTexture.loadFromFile( "res/maze.png" ) )
    {
        printf( "Failed to load screen1 texture!\n" );
        success = false;
    }


    if( !gLHCTexture.loadFromFile( "res/mazeLHC.png" ) )
    {
        printf( "Failed to load character1 texture!\n" );
        success = false;
    }

    // if( !gLHCTexture.loadFromFile( "res/mazeLHC.png" ) )
    // {
    //     printf( "Failed to load character1 texture!\n" );
    //     success = false;
    // }

    if( !gStaffCanteen.loadFromFile( "res/mazeStaffCanteen.png" ) )
    {
        printf( "Failed to load character1 texture!\n" );
        success = false;
    }

    if( !gHostelTexture.loadFromFile( "res/mazeHostel.png" ) )
    {
        printf( "Failed to load hostel texture!\n" );
        success = false;
    }

    if( !gScoopsTexture.loadFromFile( "res/mazeScoops.png" ) )
    {
        printf( "Failed to load scoops texture!\n" );
        success = false;
    }

    if( !gLibraryTexture.loadFromFile( "res/mazeLibrary.png" ) )
    {
        printf( "Failed to load mazelib texture!\n" );
        success = false;
    }

extern LTexture r_lhc;
extern LTexture r_sc;
extern LTexture congo;
extern LTexture lhc1;
extern LTexture lhc2;
extern LTexture lhc3;
extern LTexture lhc4;

    if( !r_lhc.loadFromFile( "res/riddle_LHC.png" ) )
    {
        printf( "Failed to load mazelib texture!\n" );
        success = false;
    }

    if( !r_sc.loadFromFile( "res/riddle_staffcanteen.png" ) )
    {
        printf( "Failed to load mazelib texture!\n" );
        success = false;
    }

    if( !r_fb.loadFromFile( "res/Riddle_football.png" ) )
    {
        printf( "Failed to load mazelib texture!\n" );
        success = false;
    }

    if( !lhc1.loadFromFile( "res/LHC1.png" ) )
    {
        printf( "Failed to load mazelib texture!\n" );
        success = false;
    }

    if( !lhc2.loadFromFile( "res/LHC2.png" ) )
    {
        printf( "Failed to load mazelib texture!\n" );
        success = false;
    }

    if( !lhc3.loadFromFile( "res/LHC3.png" ) )
    {
        printf( "Failed to load mazelib texture!\n" );
        success = false;
    }

    if( !lhc4.loadFromFile( "res/LHC4.png" ) )
    {
        printf( "Failed to load mazelib texture!\n" );
        success = false;
    }

    if( !sc.loadFromFile( "res/SC.png" ) )
    {
        printf( "Failed to load mazelib texture!\n" );
        success = false;
    }

    if( !fb.loadFromFile( "res/football.png" ) )
    {
        printf( "Failed to load mazelib texture!\n" );
        success = false;
    }

    if( !r_hos.loadFromFile( "res/riddle_hostel.png" ) )
    {
        printf( "Failed to load mazelib texture!\n" );
        success = false;
    }
    if( !r_scoops.loadFromFile( "res/riddle_scoops.png" ) )
    {
        printf( "Failed to load mazelib texture!\n" );
        success = false;
    }
    if( !r_lib.loadFromFile( "res/Riddle_library.png" ) )
    {
        printf( "Failed to load mazelib texture!\n" );
        success = false;
    }
    if( !r_sac.loadFromFile( "res/riddle_sac.png" ) )
    {
        printf( "Failed to load mazelib texture!\n" );
        success = false;
    }
    if( !r_gate.loadFromFile( "res/gate.png" ) )
    {
        printf( "Failed to load mazelib texture!\n" );
        success = false;
    }
    if( !hos1.loadFromFile( "res/hostel1.png" ) )
    {
        printf( "Failed to load mazelib texture!\n" );
        success = false;
    }
    if( !hos2.loadFromFile( "res/hostel2.png" ) )
    {
        printf( "Failed to load mazelib texture!\n" );
        success = false;
    }
    if( !scoops.loadFromFile( "res/scoops.png" ) )
    {
        printf( "Failed to load mazelib texture!\n" );
        success = false;
    }
    if( !lib1.loadFromFile( "res/library1.png" ) )
    {
        printf( "Failed to load mazelib texture!\n" );
        success = false;
    }
    if( !lib2.loadFromFile( "res/library2.png" ) )
    {
        printf( "Failed to load mazelib texture!\n" );
        success = false;
    }
    if( !lib3.loadFromFile( "res/library3.png" ) )
    {
        printf( "Failed to load mazelib texture!\n" );
        success = false;
    }
    if( !sac1.loadFromFile( "res/SAC1.png" ) )
    {
        printf( "Failed to load mazelib texture!\n" );
        success = false;
    }
    if( !sac2.loadFromFile( "res/SAC2.png" ) )
    {
        printf( "Failed to load mazelib texture!\n" );
        success = false;
    }
    if( !gCoinTexture.loadFromFile( "res/coin.png" ) )
    {
        printf( "Failed to load coin texture!\n" );
        success = false;
    }

    if( !gHimadriTexture.loadFromFile( "res/himadri.png" ) )
    {
        printf( "Failed to load himadri texture!\n" );
        success = false;
    }

    if( !gKailashTexture.loadFromFile( "res/kailash.png" ) )
    {
        printf( "Failed to load kailash texture!\n" );
        success = false;
    }

    if( !gLHC_exTexture.loadFromFile( "res/lhc.png" ) )
    {
        printf( "Failed to load kailash texture!\n" );
        success = false;
    }

    if( !gGirnarTexture.loadFromFile( "res/girnar.png" ) )
    {
        printf( "Failed to load kailash texture!\n" );
        success = false;
    }

    if( !gKaraTexture.loadFromFile( "res/kara.png" ) )
    {
        printf( "Failed to load kara texture!\n" );
        success = false;
    }

    if( !gSacTexture.loadFromFile( "res/sac.png" ) )
    {
        printf( "Failed to load sac texture!\n" );
        success = false;
    }

    if( !gBroomTexture.loadFromFile( "res/broom.png" ) )
    
    {
        printf( "Failed to load broom texture!\n" );
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

    if( !girl1BackTexture.loadFromFile( "res/girl1_back.png" ) )
    {
        printf( "Failed to load character1 texture!\n" );
        success = false;
    }
    if( !girl1LeftTexture.loadFromFile( "res/girl1_left.png" ) )
    {
        printf( "Failed to load character1 texture!\n" );
        success = false;
    }
    if( !girl1FrontTexture.loadFromFile( "res/girl1_front.png" ) )
    {
        printf( "Failed to load character1 texture!\n" );
        success = false;
    }
    if( !girl1RightTexture.loadFromFile( "res/girl1_right.png" ) )
    {
        printf( "Failed to load character1 texture!\n" );
        success = false;
    }
    if( !girl2BackTexture.loadFromFile( "res/girl2_back.png" ) )
    {
        printf( "Failed to load character1 texture!\n" );
        success = false;
    }
    if( !girl2LeftTexture.loadFromFile( "res/girl2_left.png" ) )
    {
        printf( "Failed to load character1 texture!\n" );
        success = false;
    }
    if( !girl2FrontTexture.loadFromFile( "res/girl2_front.png" ) )
    {
        printf( "Failed to load character1 texture!\n" );
        success = false;
    }
    if( !girl2RightTexture.loadFromFile( "res/girl2_right.png" ) )
    {
        printf( "Failed to load character1 texture!\n" );
        success = false;
    }if( !boy1BackTexture.loadFromFile( "res/boy1_back.png" ) )
    {
        printf( "Failed to load character1 texture!\n" );
        success = false;
    }
    if( !boy1LeftTexture.loadFromFile( "res/boy1_left.png" ) )
    {
        printf( "Failed to load character1 texture!\n" );
        success = false;
    }
    if( !boy1FrontTexture.loadFromFile( "res/boy1_front.png" ) )
    {
        printf( "Failed to load character1 texture!\n" );
        success = false;
    }
    if( !boy1RightTexture.loadFromFile( "res/boy1_right.png" ) )
    {
        printf( "Failed to load character1 texture!\n" );
        success = false;
    }if( !boy2BackTexture.loadFromFile( "res/boy2_back.png" ) )
    {
        printf( "Failed to load character1 texture!\n" );
        success = false;
    }
    if( !boy2LeftTexture.loadFromFile( "res/boy2_left.png" ) )
    {
        printf( "Failed to load character1 texture!\n" );
        success = false;
    }
    if( !boy2FrontTexture.loadFromFile( "res/boy2_front.png" ) )
    {
        printf( "Failed to load character1 texture!\n" );
        success = false;
    }
    if( !boy2RightTexture.loadFromFile( "res/boy2_right.png" ) )
    {
        printf( "Failed to load character1 texture!\n" );
        success = false;
    }


//chote mazes


}

void close()
{
    //Free loaded images
    gScreen1Texture.free();
    gGameTexture.free();
    gMazeTexture.free();
    gLHCTexture.free();
    gStaffCanteen.free();
    gScoopsTexture.free();
    gHostelTexture.free();
    gLibraryTexture.free();
    gBroomTexture.free();

    gTimeTextTexture.free();
    gPlayerTexture.free();
    gCoinTexture.free();
    gScoreBoardTexture.free();

    girl1BackTexture.free();
    girl1FrontTexture.free();
    girl1LeftTexture.free();
    girl1RightTexture.free();

    girl2BackTexture.free();
    girl2FrontTexture.free();
    girl2LeftTexture.free();
    girl2RightTexture.free();

    boy1BackTexture.free();
    boy1FrontTexture.free();
    boy1LeftTexture.free();
    boy1RightTexture.free();

    boy2BackTexture.free();
    boy2FrontTexture.free();
    boy2LeftTexture.free();
    boy2RightTexture.free();

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