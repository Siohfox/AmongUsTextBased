#pragma once
#include "Players.h"

class Crewmate : public Players
{
public:
	Crewmate(std::string _colour)
	{
		for (int i = 0; i < 8; i++)
		{
			m_tasks[i] = i;
		}
		this->m_colour = _colour;
		this->m_aliveState = true;
	}

	~Crewmate()
	{

	}
	
	inline std::string& GetColour() { return m_colour; }

private:
	int m_tasks[8];
};

