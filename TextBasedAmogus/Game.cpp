#include "Game.h"


void Game::Initialize(int _playerCount)
{
	m_playerCount = _playerCount;

	for (int i = 0; i < _playerCount; i++)
	{
		Crewmate* crewmate = new Crewmate(m_colourList[i]);
		crewmates.push_back(crewmate);
		std::cout << "Initialized crewmate: " << crewmates[i]->GetColour() << std::endl;
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
