#pragma once
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>

class SDLManager
{
public:
	SDLManager(int windowWidth, int windowHeight);
	~SDLManager();

	SDL_Renderer* SDLInit();

protected:
	// Set up stuff needed for SDL and create pointer to menu class
	int m_windowWidth;
	int m_windowHeight;
	SDL_Window* m_window;
	SDL_Renderer* m_renderer;
};

