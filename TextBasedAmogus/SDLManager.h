#pragma once
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>

class SDLManager
{
public:
	SDLManager(int windowSizeX, int windowSizeY);
	~SDLManager();

	SDL_Renderer* SDLInit();

protected:
	// Set up stuff needed for SDL and create pointer to menu class
	int m_windowSizeX;
	int m_windowSizeY;
	SDL_Window* m_window;
	SDL_Renderer* m_renderer;
};

