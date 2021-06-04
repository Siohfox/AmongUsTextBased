#include "SDLManager.h"
#include <iostream>

// Constrtuctor 
SDLManager::SDLManager(int windowSizeX, int windowSizeY)
{
    this->m_windowSizeX = windowSizeX;
    this->m_windowSizeY = windowSizeY;
    m_renderer = nullptr;
    m_window = nullptr;
}

// Destructor for manager, destroys all sdl stuff and the menu instance
SDLManager::~SDLManager()
{
    SDL_DestroyWindow(m_window);
    SDL_DestroyRenderer(m_renderer);
    SDL_Quit();
}

SDL_Renderer* SDLManager::SDLInit()
{
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0)
    {
        std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
        exit(EXIT_FAILURE);
    }

    // Check if VS is linked to the TTF lib file and initialise it
    if (TTF_Init() < 0)
    {
        SDL_Log("Unable to initialise SDL_TTF: %s", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    // Create Window
    m_window = SDL_CreateWindow("Asteroid Shooter Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, m_windowSizeX, m_windowSizeY, SDL_WINDOW_SHOWN);

    if (m_window == nullptr)
    {
        std::cout << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        exit(EXIT_FAILURE);
    }

    // Create renderer
    m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (m_renderer == nullptr)
    {
        std::cout << "Renderer could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        exit(EXIT_FAILURE);
    }
    return m_renderer;
}
