#pragma once
#include <string>
#include <vector>
#include <iostream>

class Players
{
public:
	Players()
	{
		m_colour = "null";
		m_aliveState = NULL;
		m_player = NULL;
	}

	~Players()
	{

	}

	/// <summary>
	/// Getter for player's alive state, if they're dead this should be false.
	/// </summary>
	/// <returns> Returns the alive state of the player </returns>
	inline bool const& GetAliveState() { return m_aliveState; }
	inline bool const& GetPlayerState() { return m_player; }
	inline int const& GetPlayerCrewmateType() { return m_playerType; }
	inline std::string& GetColour() { return m_colour; }

	// Setters
	inline void SetAliveState(const int alivestate) { this->m_aliveState = alivestate; }
	inline void SetPlayerState(const bool playerstate) { this->m_player = playerstate; }
	inline void SetPlayerCrewmateType(const int playertype) { this->m_playerType = playertype; }

	//Methods
	virtual void Update() = 0;

protected:
	// This is the colour the player will be
	std::string m_colour;

	// A definition for a player controlled crewmate
	bool m_player;

	bool m_aliveState;

	// player type. 0 = crewmate, 1 = imposter
	int m_playerType;
};

