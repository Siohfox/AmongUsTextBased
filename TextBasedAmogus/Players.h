#pragma once
#include <string>
#include <vector>

class Players
{
public:
	Players()
	{
		m_colour = "null";
		this->aliveState = true;
	}

	~Players()
	{

	}

	/// <summary>
	/// Getter for player's alive state, if they're dead this should be false.
	/// </summary>
	/// <returns> Returns the alive state of the player </returns>
	inline bool const& GetAliveState() { return aliveState; }
	

protected:
	std::string m_colour;
	bool aliveState;
};

