#include "Menu.h"
#include "Game.h"
#include <sstream>
void Menu::MenuLoop()
{
	std::cout << "Press R to run" << std::endl;

	while (menuActive)
	{
		PollEvents();

		Render();
	}
}

void Menu::PollEvents()
{
	const Uint8* keyboard_state_array = SDL_GetKeyboardState(NULL);

	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_KEYDOWN:

			// If player presses R in the menu, it will run the game.
			// Once the game finishes, it will update the highscore for the menu
			if ((keyboard_state_array[SDL_SCANCODE_R]))
			{
				Run();

				std::cout << "Returned to menu!" << std::endl;
			}
		}
	}
}

void Menu::Render()
{
	// Clear screen
	SDL_RenderClear(m_renderer);

	// Set background default colour (black)
	SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 255);

	// Set background image
	SDL_RenderCopyEx(m_renderer, this->m_backgroundTexture, nullptr, &this->m_backgroundRect, 0, nullptr, SDL_FLIP_NONE);

	// Update Screen
	SDL_RenderPresent(m_renderer);
}

void Menu::Run()
{
	/// <summary>
	/// Ask user how many players they want to play
	/// This will include themselves.
	/// This will be passed into the initialization of the game
	/// </summary>
	int playerCount;

	std::string input = "";

	// The loop waits for them to enter a correct integer between 4 and 10 (min and max players)
	while (true) 
	{
		std::cout << "Enter player amount: ";
		std::getline(std::cin, input);

		// This code converts from string to number safely.
		std::stringstream myStream(input);
		if (myStream >> playerCount)
		{ 
			if (playerCount <= 10 && playerCount >= 4)
			{
				break;
			}
		}
		std::cout << "Invalid number, please try again" << std::endl;
	}

	// Create instance of the game
	Game* game = new Game();

	// Initialize the players using the input player amont
	game->Initialize(playerCount);

	// Start the game
	game->Gameloop();

	// Finish game and clear memory
	delete game;

	return;
}


