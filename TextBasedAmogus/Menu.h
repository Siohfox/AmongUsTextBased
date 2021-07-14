#pragma once
#include <iostream>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>

class Menu
{
public:
	Menu(SDL_Renderer* renderer)
	{
		this->m_renderer = renderer;
		menuActive = true;

		// Create the background
		m_backgroundRect = { 0,0,845,464 };
		m_backgroundImage = SDL_LoadBMP("Images/amogusmaplabled.bmp");
		if (!m_backgroundImage)
		{
			throw std::exception();
		}
		m_backgroundTexture = SDL_CreateTextureFromSurface(m_renderer, m_backgroundImage);
		SDL_FreeSurface(m_backgroundImage);
	}

	~Menu()
	{
		SDL_DestroyTexture(m_backgroundTexture);
	}

	void MenuLoop();
	void PollEvents();
	void Run();
	void Render();

private:
	bool menuActive;
	SDL_Renderer* m_renderer;

	SDL_Rect m_backgroundRect;
	SDL_Surface* m_backgroundImage;
	SDL_Texture* m_backgroundTexture;
};

