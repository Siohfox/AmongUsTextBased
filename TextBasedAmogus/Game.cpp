#include "Game.h"

void Game::Gameloop()
{
	while (m_running)
	{
		PollEvents();
		Update();
	}
}

void Game::PollEvents()
{
	
}

void Game::Update()
{
}
