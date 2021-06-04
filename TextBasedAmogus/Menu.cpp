#include "Menu.h"
#include "Game.h"

void Menu::MenuLoop()
{
	while (menuActive)
	{
		PollEvents();
	}
}

void Menu::PollEvents()
{
	if (std::cin.get())
	{
		Run();
	}
}

void Menu::Run()
{
	/// <summary>
	/// Ask user how many players they want to play
	/// This will include themselves.
	/// This will be passed into the initialization of the game
	/// </summary>
	int playerCount;
	std::cout << "Enter player amount:" << std::endl;
	std::cin >> playerCount;

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
