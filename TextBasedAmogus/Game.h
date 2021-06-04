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
		m_colourList[0] = "Red";
		m_colourList[1] = "Orange";
		m_colourList[2] = "Yellow";
		m_colourList[3] = "Green";
		m_colourList[4] = "Blue";
		m_colourList[5] = "Cyan";
		m_colourList[6] = "Pink";
		m_colourList[7] = "Purple";
		m_colourList[8] = "White";
		m_colourList[9] = "Black";
	}
	~Game()
	{

	}

	void Initialize(int _playerCount);
	void Gameloop();
	void PollEvents();
	void Update();

	inline std::string const& GetColour(int colourNumber) { return m_colourList[colourNumber]; }

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

	//This is the range of colours that can be picked from
	std::string m_colourList[10];
};

