#include <iostream>
#include "SDLManager.h"
#include "Menu.h"

int main(int argc, char* argv[])
{
	SDL_Renderer* renderer;

	SDLManager SDL(1920, 1080);

	renderer = SDL.SDLInit();

	Menu menu(renderer);

	menu.MenuLoop();

	return 0;
}