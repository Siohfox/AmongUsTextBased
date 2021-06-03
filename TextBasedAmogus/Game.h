#pragma once
#include <string>
#include <iostream>

class Game
{
public:
	Game()
	{
		m_running = true;
		std::cout << "Game constructor called" << std::endl;
	}
	~Game()
	{

	}

	void Gameloop();
	void PollEvents();
	void Update();

private:
	bool m_running;

};

