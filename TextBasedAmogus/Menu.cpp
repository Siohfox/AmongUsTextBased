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
	Game* game = new Game();

	game->Gameloop();

	delete game;

	return;
}
