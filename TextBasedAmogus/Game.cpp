#include "Game.h"


void Game::Initialize(int _playerCount)
{
	m_playerCount = _playerCount;

	for (int i = 0; i < _playerCount; i++)
	{
		Crewmate* crewmate = new Crewmate("Red" + std::to_string(i));
		crewmates.push_back(crewmate);
		std::cout << crewmates[i]->GetColour();
	}
	 

	return;
}

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
