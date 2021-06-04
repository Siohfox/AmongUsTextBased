#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "Crewmate.h"
#include "Imposter.h"

class Game
{
public:
	Game()
	{
		m_running = true;
		m_playerCount = 10;
		std::cout << "Game constructor called" << std::endl;
	}
	~Game()
	{

	}

	void Initialize(int _playerCount);
	void Gameloop();
	void PollEvents();
	void Update();

private:
	/// <summary>
	/// Determines whether the game is running. 
	/// </summary>
	bool m_running;

	/// <summary>
	/// Determines how many players there are.
	/// </summary>
	int m_playerCount;
	std::vector<Crewmate*> crewmates;
};

