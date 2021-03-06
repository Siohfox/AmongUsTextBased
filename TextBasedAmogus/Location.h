#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Players.h"

class Location
{
public:
	Location(std::string locationName)
	{
		m_locationName = locationName;

		m_numberOfCrewAtLocation = 0;
	}

	~Location()
	{

	}

	void setNumberOfCrewAtLocation(int crewAmount) { m_numberOfCrewAtLocation = crewAmount; }
	void addPlayerToLocation(Players* player) { m_playersAtLocation.push_back(player); }

	int getNumberOfCrewAtLocation() { return m_numberOfCrewAtLocation; }
	std::vector<Players*> getplayersAtLocation() { return m_playersAtLocation; }
	std::string getLocationName() { return m_locationName; }


private:
	std::string m_locationName;

	int m_numberOfCrewAtLocation;

	std::vector<Players*> m_playersAtLocation;
};

