#include <iostream>
#include "SDLManager.h"
#include "Menu.h"

int main(int argc, char* argv[])
{
	// Create local renderer
	SDL_Renderer* renderer;

	// Create object instance of SDL manager, passing in screen size
	SDLManager SDL(800, 800);

	// Return SDLInit's renderer to the local one here
	// SDL init will also set up all of the other SDL related components
	renderer = SDL.SDLInit();

	// Create instance of the menu, passing in the initialized renderer
	// The renderer will be passed down along the way
	Menu menu(renderer);

	// Start the menu loop
	menu.MenuLoop();

	return 0;
}