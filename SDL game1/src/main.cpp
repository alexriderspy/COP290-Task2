#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include "RenderWindow.hpp"
#include "Entity.hpp"

const int SCREEN_WIDTH = 1000;
const int SCREEN_HEIGHT = 1280;

enum KeyPressSurfaces
{
    KEY_PRESS_SURFACE_DEFAULT,
    KEY_PRESS_SURFACE_UP,
    KEY_PRESS_SURFACE_DOWN,
    KEY_PRESS_SURFACE_LEFT,
    KEY_PRESS_SURFACE_RIGHT,
    KEY_PRESS_SURFACE_TOTAL
};

bool init();
bool loadMedia();
void close();

SDL_Surface* loadSurface (std::string path);
SDL_Window* gWindow = NULL;
SDL_Surface* gScreenSurface = NULL;
SDL_Surface* gKeyPressSurfaces[KEY_PRESS_SURFACE_TOTAL];
SDL_Surface* gCurrentSurface = NULL;

SDL_Surface* loadSurface (std::string path){
	SDL_Surface* loadedSurface = SDL_LoadBMP(path.c_str());
	if (loadedSurface == NULL){
		std::cout<<"Unable to load image: "<<path.c_str()<<' '<<SDL_GetError()<<'\n';
	}
	return loadedSurface;
}

bool init()
{
    //Initialization flag
    bool success = true;

    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
        success = false;
    }
    else
    {
        //Create window
        gWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        if( gWindow == NULL )
        {
            printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
            success = false;
        }
        else
        {
            //Get window surface
            gScreenSurface = SDL_GetWindowSurface( gWindow );
        }
    }

    return success;
}

bool loadMedia()
{
    //Loading success flag
    bool success = true;

    //Load default surface
    gKeyPressSurfaces[ KEY_PRESS_SURFACE_DEFAULT ] = loadSurface( "res/gfx/screen1.bmp" );
    if( gKeyPressSurfaces[ KEY_PRESS_SURFACE_DEFAULT ] == NULL )
    {
        printf( "Failed to load default image!\n" );
        success = false;
    }

    //Load up surface
    // gKeyPressSurfaces[ KEY_PRESS_SURFACE_UP ] = loadSurface( "04_key_presses/up.bmp" );
    // if( gKeyPressSurfaces[ KEY_PRESS_SURFACE_UP ] == NULL )
    // {
    //     printf( "Failed to load up image!\n" );
    //     success = false;
    // }

    // //Load down surface
    // gKeyPressSurfaces[ KEY_PRESS_SURFACE_DOWN ] = loadSurface( "04_key_presses/down.bmp" );
    // if( gKeyPressSurfaces[ KEY_PRESS_SURFACE_DOWN ] == NULL )
    // {
    //     printf( "Failed to load down image!\n" );
    //     success = false;
    // }

    // //Load left surface
    // gKeyPressSurfaces[ KEY_PRESS_SURFACE_LEFT ] = loadSurface( "04_key_presses/left.bmp" );
    // if( gKeyPressSurfaces[ KEY_PRESS_SURFACE_LEFT ] == NULL )
    // {
    //     printf( "Failed to load left image!\n" );
    //     success = false;
    // }

    // //Load right surface
    // gKeyPressSurfaces[ KEY_PRESS_SURFACE_RIGHT ] = loadSurface( "04_key_presses/right.bmp" );
    // if( gKeyPressSurfaces[ KEY_PRESS_SURFACE_RIGHT ] == NULL )
    // {
    //     printf( "Failed to load right image!\n" );
    //     success = false;
    // }

    gKeyPressSurfaces[ KEY_PRESS_SURFACE_RIGHT ] = loadSurface( "res/gfx/screen2.bmp" );
    if( gKeyPressSurfaces[ KEY_PRESS_SURFACE_RIGHT ] == NULL )
    {
        printf( "Failed to load 2nd image!\n" );
        success = false;
    }

    return success;
}

void close()
{
    //Deallocate surface
    SDL_FreeSurface( gCurrentSurface );
    gCurrentSurface = NULL;

    //Destroy window
    SDL_DestroyWindow( gWindow );
    gWindow = NULL;

    //Quit SDL subsystems
    SDL_Quit();
}

int main(int argc, char* args[])
{

	if (!init()){
		std::cout << "Failed to initialize\n";
	}else{
		if (!loadMedia()){
			std::cout << "Failed to load media\n";
		}else{
			bool quit = false;
			SDL_Event e;

			gCurrentSurface = gKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT];

			while(!quit){
				while( SDL_PollEvent(&e)!=0){
					if (e.type == SDL_QUIT){
						quit = true;
					}else if (e.type == SDL_KEYDOWN){
						switch (e.key.keysym.sym){
							case SDLK_RIGHT:
							gCurrentSurface = gKeyPressSurfaces[KEY_PRESS_SURFACE_RIGHT];
							break;
						}
					}
				}
				SDL_BlitSurface(gCurrentSurface,NULL,gScreenSurface,NULL);
				SDL_UpdateWindowSurface(gWindow);
			}
		}
	}
	close();
	return 0;
}
// 	SDL_Texture* start_screen = window.loadTexture("res/gfx/start_screen.png");

// 	SDL_Texture* character1 = window.loadTexture("res/gfx/character1.png");

//     Entity entity0(0, 0, 1280, 720, start_screen);
//     Entity entity1(0, 600, 40, 40, character1);


// 	bool gameRunning = true;

// 	SDL_Event event;

// 	while (gameRunning)
// 	{
// 		// Get our controls and events
// 		while (SDL_PollEvent(&event))
// 		{
// 			if (event.type == SDL_QUIT)
// 				gameRunning = false;
// 		}

// 		window.clear();
		
// 		window.render(entity0);
// 		window.render(entity1);
// 		window.display();

// 	}

// 	window.cleanUp();
// 	SDL_Quit();

// 	return 0;
// }