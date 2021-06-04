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

	~Players()
	{

	}

	/// <summary>
	/// Getter for player's alive state, if they're dead this should be false.
	/// </summary>
	/// <returns> Returns the alive state of the player </returns>
	inline bool const& GetAliveState() { return m_aliveState; }


	inline std::string const& GetColour(int colourNumber) { return m_colourList[colourNumber]; }
	

protected:
	// This is the colour the player will be
	std::string m_colour;

	//This is the range of colours that can be picked from
	std::string m_colourList[10];

	bool m_aliveState;
};

