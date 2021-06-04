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
	int playerCount = 10;

	Game* game = new Game();

	game->Initialize(playerCount);

	game->Gameloop();

	delete game;

	return;
}
