#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <time.h>
#include "Crewmate.h"
#include "Imposter.h"
#include "Task.h"
#include "EmergencyTask.h"
#include "Location.h"

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
	void Render();

	void InitLocations();
	void InitTasks();



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

	// a vector for storing crewmates
	std::vector<Crewmate*> m_crewmates;
	std::vector<Imposter*> m_imposters;

	//This is the range of colours that can be picked from
	std::string m_colourList[10];

	std::vector<Location*> m_locations;

	std::vector<Task*> m_tasks;
	std::vector<Task*> m_emergencyTasks;

};

