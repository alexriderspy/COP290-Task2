#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_net.h>
#include <iostream>
#include <string>
#include <sstream>
#include "../include/timer.hpp"
#include "../include/character.hpp"
//Screen dimension constants

enum KeyPressTextures
{
    KEY_PRESS_TEXTURE_DEFAULT,
    KEY_PRESS_TEXTURE_LEFT,
    KEY_PRESS_TEXTURE_RIGHT,
    KEY_PRESS_TEXTURE_TOTAL
};

SDL_Window* gWindow = NULL;

//The window renderer
SDL_Renderer* gRenderer = NULL;

TTF_Font* gFont = NULL;

Mix_Music* gMusic = NULL;

//The sound effects that will be used
Mix_Chunk *gScratch = NULL;

class LTexture
{

    public:
        //Initializes variables
        LTexture();

        //Deallocates memory
        ~LTexture();

        //Loads image at specified path
        bool loadFromFile( std::string path );
        
        //Creates image from font string
        bool loadFromRenderedText( std::string textureText, SDL_Color textColor );
        
        //Deallocates texture
        void free();

        //Set color modulation
        void setColor( Uint8 red, Uint8 green, Uint8 blue );

        //Set blending
        void setBlendMode( SDL_BlendMode blending );

        //Set alpha modulation
        void setAlpha( Uint8 alpha );
        
        //Renders texture at given point
        void render( int x, int y, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE );

        //Gets image dimensions
        int getWidth();
        int getHeight();

        SDL_Texture* getTexture();
    private:
        //The actual hardware texture
        SDL_Texture* mTexture;

        //Image dimensions
        int mWidth;
        int mHeight;
};

LTexture::LTexture()
{
    //Initialize
    mTexture = NULL;
    mWidth = 0;
    mHeight = 0;
}

LTexture::~LTexture()
{
    //Deallocate
    free();
}

bool LTexture::loadFromFile( std::string path )
{
    //Get rid of preexisting texture
    free();

    //The final texture
    SDL_Texture* newTexture = NULL;

    //Load image at specified path
    SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
    if( loadedSurface == NULL )
    {
        printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
    }
    else
    {
        //Color key image
        SDL_SetColorKey( loadedSurface, SDL_TRUE, SDL_MapRGB( loadedSurface->format, 0, 0xFF, 0xFF ) );

        //Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface( gRenderer, loadedSurface );
        if( newTexture == NULL )
        {
            printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
        }
        else
        {
            //Get image dimensions
            mWidth = loadedSurface->w;
            mHeight = loadedSurface->h;
        }

        //Get rid of old loaded surface
        SDL_FreeSurface( loadedSurface );
    }

    //Return success
    mTexture = newTexture;
    return mTexture != NULL;
}

bool LTexture::loadFromRenderedText( std::string textureText, SDL_Color textColor )
{
    //Get rid of preexisting texture
    free();

    //Render text surface
    SDL_Surface* textSurface = TTF_RenderText_Solid( gFont, textureText.c_str(), textColor );
    if( textSurface != NULL )
    {
        //Create texture from surface pixels
        mTexture = SDL_CreateTextureFromSurface( gRenderer, textSurface );
        if( mTexture == NULL )
        {
            printf( "Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError() );
        }
        else
        {
            //Get image dimensions
            mWidth = textSurface->w;
            mHeight = textSurface->h;
        }

        //Get rid of old surface
        SDL_FreeSurface( textSurface );
    }
    else
    {
        printf( "Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError() );
    }

    
    //Return success
    return mTexture != NULL;
}

void LTexture::free()
{
    //Free texture if it exists
    if( mTexture != NULL )
    {
        SDL_DestroyTexture( mTexture );
        mTexture = NULL;
        mWidth = 0;
        mHeight = 0;
    }
}

void LTexture::setColor( Uint8 red, Uint8 green, Uint8 blue )
{
    //Modulate texture rgb
    SDL_SetTextureColorMod( mTexture, red, green, blue );
}

void LTexture::setBlendMode( SDL_BlendMode blending )
{
    //Set blending function
    SDL_SetTextureBlendMode( mTexture, blending );
}
        
void LTexture::setAlpha( Uint8 alpha )
{
    //Modulate texture alpha
    SDL_SetTextureAlphaMod( mTexture, alpha );
}

void LTexture::render( int x, int y, SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip )
{
    //Set rendering space and render to screen
    SDL_Rect renderQuad = { x, y, mWidth, mHeight };

    //Set clip rendering dimensions
    if( clip != NULL )
    {
        renderQuad.w = clip->w;
        renderQuad.h = clip->h;
    }

    //Render to screen
    SDL_RenderCopyEx( gRenderer, mTexture, clip, &renderQuad, angle, center, flip );
}

int LTexture::getWidth()
{
    return mWidth;
}

int LTexture::getHeight()
{
    return mHeight;
}

SDL_Texture* LTexture::getTexture(){
    return mTexture;
}

//Starts up SDL and creates window
bool init();

//Loads media
bool loadMedia();

//Frees media and shuts down SDL
void close();

//The window we'll be rendering to

//Scene textures
LTexture gScreen1Texture;
LTexture gScreen2Texture;
LTexture gTextTexture;
LTexture gGameTexture;
LTexture gTimeTextTexture;
LTexture gCharacterTexture;

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
        gWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
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

int main( int argc, char* args[] )
{
    //Start up SDL and create window
    if( !init() )
    {
        printf( "Failed to initialize!\n" );
    }
    else
    {
        //Load media
        if( !loadMedia() )
        {
            printf( "Failed to load media!\n" );
        }
        else
        {   
            //Main loop flag
            bool quit = false;

            //Event handler
            SDL_Event e;

            SDL_Color textColor = {0,0,0,255};

            Uint32 startTime = 0;
            LTimer timer;

            std::stringstream timeText;

            //Current rendered texture
            LTexture* currentTexture = &gScreen1Texture;
            Character dot;

            //While application is running
            while( !quit )
            {
                //Handle events on queue
                while( SDL_PollEvent( &e ) != 0 )
                {
                    //User requests quit
                    if( e.type == SDL_QUIT )
                    {
                        quit = true;

                    }else if(e.type == SDL_KEYDOWN){
                        if (currentTexture == &gScreen1Texture && e.key.keysym.sym == SDLK_RETURN){
                            currentTexture = &gScreen2Texture;
                            startTime = SDL_GetTicks();
                            
                        }else if(currentTexture == &gScreen2Texture && e.key.keysym.sym == SDLK_LEFT){
                            currentTexture = &gScreen1Texture;
                            startTime = SDL_GetTicks();
                        }else if(currentTexture == &gScreen2Texture && e.key.keysym.sym == SDLK_RETURN){
                            currentTexture = &gGameTexture;
                            Mix_PlayMusic(gMusic,-1);
                            startTime = SDL_GetTicks();
                        }else if(e.key.keysym.sym == SDLK_s){
                            if(timer.isStarted()){
                                timer.stop();
                            }else{
                                timer.start();
                            }
                        }else if(e.key.keysym.sym == SDLK_p){
                            if(timer.isPaused()){
                                timer.unpause();
                            }else{
                                timer.pause();
                            }
                        }

                        // if(e.key.keysym.sym == SDLK_1){
                        //     Mix_PlayChannel (-1,gScratch,0);
                            
                        // }else if(e.key.keysym.sym == SDLK_9){
                        //     if(Mix_PlayingMusic() == 0){
                        //         Mix_PlayMusic(gMusic,-1);
                        //     }else if (Mix_PausedMusic() == 1){
                        //         Mix_ResumeMusic();
                        //     }else{
                        //         Mix_PauseMusic();
                        //     }
                        // }else if(e.key.keysym.sym == SDLK_0){
                        //     Mix_HaltMusic();
                        // }

                        dot.handleEvent(e);
                    }

                }

                timeText.str("");
                timeText << "Seconds since start time : " <<(timer.getTicks()/1000.f);

                if( !gTimeTextTexture.loadFromRenderedText( timeText.str().c_str(),textColor ) )
                {
                    printf( "Failed to load time texture!\n" );
                }

                //Clear screen
                SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
                SDL_RenderClear( gRenderer );

                //Render current texture

                SDL_RenderCopy(gRenderer,currentTexture->getTexture(),NULL,NULL);
                // gTextTexture.render( ( SCREEN_WIDTH - gTextTexture.getWidth() ) / 2, 0 );

                if (currentTexture == &gGameTexture){
                    gTimeTextTexture.render(0,0);
                    gCharacterTexture.render(dot.getmPosX(),dot.getmPosY());

                }
                if(currentTexture == &gScreen1Texture){
                    gTextTexture.render(100,400);
                }
                //Update screen
                SDL_RenderPresent( gRenderer );
            }
        }
    }

    //Free resources and close SDL
    close();

    return 0;
}