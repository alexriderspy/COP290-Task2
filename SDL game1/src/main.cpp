#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include "RenderWindow.hpp"
#include "Entity.hpp"

int main(int argc, char* args[])
{
	if (SDL_Init(SDL_INIT_VIDEO) > 0)
		std::cout << "HEY.. SDL_Init HAS FAILED. SDL_ERROR: " << SDL_GetError() << std::endl;

	if (!(IMG_Init(IMG_INIT_PNG)))
		std::cout << "IMG_init has failed. Error: " << SDL_GetError() << std::endl;

	RenderWindow window("GAME v1.0", 3000, 200);

	SDL_Texture* start_screen = window.loadTexture("res/gfx/start_screen.png");

	SDL_Texture* character1 = window.loadTexture("res/gfx/character1.png");

    Entity entity0(0, 0, 1280, 720, start_screen);
    Entity entity1(0, 100, 40, 40, character1);

	bool gameRunning = true;

	SDL_Event event;

	while (gameRunning)
	{
		// Get our controls and events
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
				gameRunning = false;
		}

		window.clear();
		
		window.render(entity0);
		window.render(entity1);
		window.display();

	}

	window.cleanUp();
	SDL_Quit();

	return 0;
}