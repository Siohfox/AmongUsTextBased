#pragma once
#include <string>
#include <vector>

class Players
{
public:
	Players()
	{
		m_colour = "null";
		m_aliveState = NULL;
	}

	~Players()
	{

	}

	/// <summary>
	/// Getter for player's alive state, if they're dead this should be false.
	/// </summary>
	/// <returns> Returns the alive state of the player </returns>
	inline bool const& GetAliveState() { return m_aliveState; }

	

protected:
	// This is the colour the player will be
	std::string m_colour;

	bool m_aliveState;
};

