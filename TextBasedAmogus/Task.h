#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Location.h"

class Task
{
public:
	Task()
	{
		m_taskName = "null";
		m_taskComplete = false;
		m_taskParts = 1;
	}

	Task(std::string taskName, int taskParts, std::vector<Location*> locations)
	{
		m_taskName = taskName;
		m_taskComplete = false;
		m_taskParts = taskParts;
		m_associatedLocations = locations;
	}

	~Task()
	{
		
	}

	// Getters
	std::string getTaskName() { return m_taskName; }
	bool getTaskStatus() { return m_taskComplete; }

	// Setters
	void setTaskStatus(bool complete) { m_taskComplete = complete; }
	void setTaskName(std::string name) { m_taskName = name; }
	std::string getTaskLocation()
	{
		for (size_t i = 0; i < this->m_associatedLocations.size(); i++)
		{
			return m_associatedLocations.at(i)->getLocationName();
		}
	}

protected:
	std::string m_taskName;
	int m_taskParts;
	bool m_taskComplete;
	std::vector<Location*> m_associatedLocations;
};

