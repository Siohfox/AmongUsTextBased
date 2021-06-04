#pragma once
#include <string>

class Players
{
public:
	Players()
	{
		aliveState = true;
	}

	~Players()
	{

	}

	/// <summary>
	/// Getter for player's alive state, if they're dead this should be false.
	/// </summary>
	/// <returns> Returns the alive state of the player </returns>
	inline bool const& GetAliveState() { return &aliveState; }

protected:
	std::string m_color;
	bool aliveState;
};

