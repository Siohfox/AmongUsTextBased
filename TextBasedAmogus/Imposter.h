#pragma once
#include "Players.h"

class Imposter : public Players
{
public:
	Imposter(std::string _colour, bool playerstate)
	{
		this->m_colour = _colour;
		this->m_aliveState = true;
		this->m_player = playerstate;
		// 1 means imposter
		this->m_playerType = 1;
	}

	~Imposter()
	{

	}

	void Update() override;

private:
	
};

